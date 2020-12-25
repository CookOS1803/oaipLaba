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
    if (n == n % 2)
    {
        return -1;
    }
    else
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
}

double y_recursive(double x, int n)
{
    if (n == 0) return 1;

    if (n > 0) return y_recursive(x, --n) * x;
    else       return y_recursive(x, ++n) * 1/x;
}
