#include <iostream>
#include <math.h>
using namespace std;

const double PI = 3.1415926;

int main()
{
    double a, z1, z2, x;

    while (true)
    {
        cout << "Enter a: ";
        if (!(cin >> a))
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else break;
    }

    x = cos(a);

    z1 = x + sin(a) + cos(3*a) + sin(3*a);
    z2 = 2*sqrt(2) * x * sin(PI/4 + 2*a);

    cout << "z1 = " << z1 << "; z2 = " << z2 << endl;

    system("pause");

    return 0;
}