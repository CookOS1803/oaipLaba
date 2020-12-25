#include <iostream>
using namespace std;

double S(double x);
double Y(double x);
double diff_S_Y(double x);
void out_rez(double f(double x), double a, double b, double h);

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

double S(double x)
{
    double r = 1,
           s = 0;

    for (int k = 1; k <= 10; k++)
    {
        r = -r * 4*x*x / (4*k*k - 2*k);
        s += r;
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
    double s = S(x);
    double y = Y(x);
    return s - y > 0 ? s - y : y - s;
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