#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    double x, y, z, f, a, b, c;

    while (true)
    {
        cout << "Enter x (17.421), y (10.365e-3) and z (0.828e5): ";
        if (!(cin >> x >> y >> z))
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else break;
    }
    
    a = pow(y + pow(x - 1, 1/3.), 1/4.);
    b = x - y;
    b = b < 0 ? -b : b;
    c = sin(z);
    c = c*c + tan(z);

    f = a/(b*c);

    cout.precision(5);
    cout << "Result: " << f << endl;

    system("pause");

    return 0;
}