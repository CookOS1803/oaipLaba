#include <iostream>
using namespace std;

double S(double x, double y, int* k);
double Y(double x);
int factorial(int a);
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
        int k = 1;

        y = Y(x);
        s = S(x, y, &k);

        cout << i << ": " << y << "; " << s << "; " << dabs(s-y) << "; " << k << endl;
    }

    system("pause");

    return 0;
}

double S(double x, double y, int* k)
{
    double s = 0;
    
    for (; dabs(s-y) >= OBS_ERROR; (*k)++)
    {
        s += ((*k) % 2 == 0 ? 1 : -1) * pow(2*x, 2*(*k))/factorial(2*(*k));
    }

    (*k)--;

    return s;
}

double Y(double x)
{
    double y = cos(x);
    y = 2*(y*y - 1);

    return y;
}

int factorial(int a)
{
    for (int i = a - 1; i != 0; i--)
    {
        a *= i;
    }

    return a;
}

double dabs(double a)
{
    return a > 0 ? a : -a;
}