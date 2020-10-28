#include <iostream>
using namespace std;

double Y(double x);

int main()
{
    double a, b, h, x, y, miny, maxy;

    cout << "Enter a(-0.9), b(2.7) and h(0.3): ";
    cin >> a >> b >> h;

    x = a;
    miny = maxy = Y(x);

    cout << "\nn\tx\ty\n";

    for (int i = 1; x <= b; x += h, i++)
    {
        y = Y(x);

        cout << i << ":\t" << x << ";\t" << y << endl;

        if (miny > y) miny = y;
        if (maxy < y) maxy = y;
    }

    cout << "\nmin y: " << miny << "\nmax y: " << maxy << endl;

    system("pause");
        
    return 0;
}

double Y(double x)
{
    return (1. - x*x/4.)*cos(x) - x/2.*sin(x);
}