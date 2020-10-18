#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, h, x, y, miny, maxy;

    cout << "Enter a(-0.9), b(2.7) and h(0.3): ";
    cin >> a >> b >> h;

    x = a;

    cout << "\nn\tx\ty\n";

    for (int i = 1; x <= b; x += h, i++)
    {
        y = (1. - x*x/4.)*cos(x) - x/2.*sin(x);

        double t = trunc(x*10e6)/10e6; //в отчёте убери эту хуйню
        cout << i << ":\t" << (t == 0 ? -t : t) << ";\t" << y << endl;

        if (i == 1)
        {
            miny = maxy = y;
        }
        else 
        {
            if (miny > y) miny = y;
            if (maxy < y) maxy = y;
        }
    }

    cout << "\nmin y: " << miny << "\nmax y: " << maxy << endl;

    system("pause");
        
    return 0;
}