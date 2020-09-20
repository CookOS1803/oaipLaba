#include <iostream>
#include <math.h>
using namespace std;

double min(double a, double b);
double max(double a, double b);
double dabs(double a);

int main()
{
    double x, y, f;

    while (true)
    {
        cout << "Enter x and y: ";
        if (!(cin >> x >> y))
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else break;
    }

    if (dabs(x) + dabs(y) <= 1 && x >= 0)
    {
        f = max(x, y) + sqrt(x);
    }
    else if (dabs(x) + dabs(y) > 0 || x < 0 && y < 0)
    {
        double a, b;

        a = sin(x);
        a = a*a;
        b = cos(y);
        b = b*b;

        f = min(x, y) + a - b;
    }
    else
    {
        f = exp(x*x + dabs(y));
    }

    cout << "f = " << f << endl;

    system("pause");

    return 0;
}

double min(double a, double b)
{
    return (a < b) ? a : b;
}

double max(double a, double b)
{
    return (a > b) ? a : b;
}

double dabs(double a)
{
    return (a < 0) ? -a : a;
}
