#include <iostream>
using namespace std;

double dabs(double a);
double S(double x, int* t);
double Y(double x);
double diff_S_Y(double x);
void out_rez(double f(double x), double a, double b, double h);
void out_rez(double f(double x, int *t), double a, double b, double h);

const double OBS_ERROR = 0.0001;

int main()
{
    double a, b, h;
    int choice;

    cout << "Enter a, b and h: ";
    cin >> a >> b >> h;
    
    cout << "Select function: \n1) S(x)\n2) Y(x)\n3) |Y(x) - S(x)|\n";
    cin >> choice;

    switch (choice)
    {
        case 1: out_rez(S, a, b, h); break;
        case 2: out_rez(Y, a, b, h); break;
        case 3: out_rez(diff_S_Y, a, b, h); break;
    }

    system("pause");

    return 0;
}

double dabs(double a)
{
    return a > 0 ? a : -a;
}

double S(double x, int* t)
{
    double r = 1,
           s = 0,
           y = Y(x);
    if (t != nullptr) *t = 0;
    for (int k = 1; dabs(y - s) >= OBS_ERROR; k++)
    {
        r = -r * 4*x*x / (4*k*k - 2*k);
        s += r;
        if (t != nullptr) (*t)++;
    }

    return s;
}

double Y(double x)
{
    double y = cos(x);
    return 2*(y*y - 1);
}

double diff_S_Y(double x)
{
    return dabs(Y(x) - S(x, nullptr));
}

void out_rez(double f(double x), double a, double b, double h)
{   
    double x = a;

    while (x <= b)
    {
        cout << "x = " << x << ": " << f(x) << endl;
        x += h;
    }
}

void out_rez(double f(double x, int* t), double a, double b, double h)
{
    double x = a;
    int t;

    while (x <= b)
    {
        cout << "x = " << x << ": " << f(x, &t);
        cout << "; tries: " << t;
        cout << endl;
        x += h;
    }
}