#include <iostream>
using namespace std;

double y_normal(double x, int n);
double y_recursive(double x, int n);

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

double y_normal(double x, int n)
{
    if (n % 1) n--;
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

double y_recursive(double x, int n)
{
    if (n % 2)
    {
        //if ()

    }
    else
    {
        if (n == 0) return 1;

    }
}