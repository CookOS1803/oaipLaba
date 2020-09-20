#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, z1, z2, x, y;

    cout << "Enter a: ";
    cin >> a;

    x = 3*a + 2;
    x = x*x;
    y = sqrt(a);

    z1 = sqrt(x - 24*a) / (3*y - 2/y);
    z2 = (a > 0 and a < 2/3.) ? -y : y;

    cout << "z1 = " << z1 << "; z2 = " << z2 << endl;

    system("pause");

    return 0;
}