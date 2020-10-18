#include <iostream>
using namespace std;

int factorial(int a);
double dabs(double a);

int main()
{
    double a, b, h, n, x, y, s;

    cout << "Enter a, b, h and n: ";
    cin >> a >> b >> h >> n;

    x = a;

    for (int i = 1; x <= b; x += h, i++)
    {
        s = 0;
        for (int k = 1; k <= n; k++)
        {
            s += (k % 2 == 0 ? 1 : -1) * pow(2*x, 2*k)/factorial(2*k);
        }

        y = cos(x);
        y = 2*(y*y - 1);

        cout << i << ": " << y << "; " << s << "; " << dabs(y-s) << endl;
    }

    system("pause");

    return 0;
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