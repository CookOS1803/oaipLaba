#include <iostream>
using namespace std;

double S(double x, double y, int k, int& t);
double Y(double x);
double dabs(double a);

const double OBS_ERROR = 0.0001;

int main()
{
    double a, b, h, x, y, s;

    cout << "Enter a, b and h: ";
    cin >> a >> b >> h;

    x = a;

    for (int i = 1; x <= b; x += h, i++)
    {
        int k = 1, t;

        y = Y(x);
        s = S(x, y, k, t);

        cout << i << ": " << y << "; " << s << "; " << dabs(s-y) << "; " << t << endl;
    }

    system("pause");

    return 0;
}

double S(double x, double y, int k, int& t)
{
    double r = 1, s = 0;
    t = 0;
    
    for (; dabs(s-y) >= OBS_ERROR; k++, t++)
    {
        r = -r * 4*x*x / (4*k*k - 2*k);
        s += r;
    }

    return s;
}

double Y(double x)
{
    double y = cos(x);
    y = 2*(y*y - 1);

    return y;
}

double dabs(double a)
{
    return a > 0 ? a : -a;
}