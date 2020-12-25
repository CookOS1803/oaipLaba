#include <iostream>
using namespace std;

const int ITER_COUNT = 5;

double power(double x, int n);
double y_normal(double x, int n);
double y_recursive(double x, int n);
double y_r_even(double x, int n);
double y_r_odd(double x, int n, double guess = 1, int k = ITER_COUNT);

int main()
{
    double a, b, h, x;
    int n;

    cout << "Enter a, b and h: ";
    cin >> a >> b >> h;
    
    cout << "Enter n: ";
    cin >> n;

    x = a;

    while (x <= b)
    {
        cout << "Y(" << x << ") normal: "    << y_normal(x, n)    << endl
             << "Y(" << x << ") recursive: " << y_recursive(x, n) << endl
             << endl;
        x += h;
    }

    system("pause");

    return 0;
}

double power(double x, int n)
{
    if (n == 0) return 1;

    double y;

    if (n > 0)
    {
        y = x;

        while (n > 1)
        {
            y *= x;
            n--;
        }
    }
    else
    {
        y = 1/x;

        while (n < -1)
        {
            y *= 1/x;
            n++;
        }
    }

    return y;
}

double y_normal(double x, int n)
{    
    if (n % 2)
    {
        n = 2 - n;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        
        double y = 1;
        bool neg = false;
        if (n < 0)
        {
            n = -n;
            neg = true;
        }

        for (int i = 0; i < ITER_COUNT; i++)
        {
            y = y*(1 - (1 - x/power(y, n))/n);
        }

        return neg ? 1/y : y;
    }
    else
    {
        return power(x, n);
    }
}

double y_recursive(double x, int n)
{
    if (n % 2)
    {
        if (2 - n == 1) return x;
        if (2 - n == -1) return 1/x;
        return y_r_odd(x, 2 - n);
    }
    else return y_r_even(x, n);
}

double y_r_even(double x, int n)
{
    if (n == 0) return 1;

    if (n > 0) return y_r_even(x, --n) * x;
    else       return y_r_even(x, ++n) * 1/x;
}

double y_r_odd(double x, int n, double guess, int k)
{
    if (k < 1) return guess;

    if (n > 0)
        return y_r_odd(x, n, guess*(1 - (1 - x/power(guess, n))/n), --k);
    else
        return 1/y_r_odd(x, -n, guess*(1 - (1 - x/power(guess, -n))/(-n)), --k);
}