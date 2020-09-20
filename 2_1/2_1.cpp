#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double n, k, m, z, x, y;

    cout << "Enter n, k, m and z: ";
    cin >> n >> k >> m >> z;

    if (z > 1)
    {
        cout << "z > 1\n";
        x = exp(z) + z;
    }
    else
    {
        cout << "z <= 1\n";
        x = z*z + 1;
    }

    y = sin(n*x) + cos(k*x) + log(m*x);

    cout << "y = " << y << endl;

    system("pause");

    return 0;
}