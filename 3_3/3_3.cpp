#include <iostream>
using namespace std;

double S(double x, double y, int& k);
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
        int k = 2;

        y = Y(x);
        s = S(x, y, k);

        cout << i << ": " << y << "; " << s << "; " << dabs(s-y) << "; " << k << endl;
    }

    system("pause");

    return 0;
}

double S(double x, double y, int& k)
{
    double r = -4*x*x / 2;
    double s = r;
    
    for (; dabs(s-y) >= OBS_ERROR; k++)
    {
        r = -r * 4*x*x / (4*k*k - 2*k);
        s += r;
    }

    k--;

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