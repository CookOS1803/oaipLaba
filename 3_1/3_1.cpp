#include <iostream>
using namespace std;

int main()
{
    double a, b, h, x, y, miny, maxy;

    cout << "Enter a(-0.9), b(2.7) and h(0.3): ";
    cin >> a >> b >> h;

    x = a;
    miny = numeric_limits<double>::max();
    maxy = numeric_limits<double>::min();

    cout << "\nn\tx\ty\n";

    for (int i = 1; x <= b; x += h, i++)
    {
        y = (1. - x*x/4.)*cos(x) - x/2.*sin(x);

        cout << i << ":\t" << x << ";\t" << y << endl;

        if (miny > y) miny = y;
        if (maxy < y) maxy = y;
    }

    cout << "\nmin y: " << miny << "\nmax y: " << maxy << endl;

    system("pause");
        
    return 0;
}