#include <iostream>
using namespace std;

double dabs(double a);

int main()
{
    double a, b, h, n, x, y, s;

    cout << "Enter a, b, h and n: ";
    cin >> a >> b >> h >> n;

    x = a;

    for (int i = 1; x <= b; x += h, i++)
    {
        double r = 1;
        s = 0;

        for (int k = 1; k <= n; k++)
        {
            r = -r * 4*x*x / (4*k*k - 2*k);
            s += r;
        }

        y = cos(x);
        y = 2*(y*y - 1);

        cout << i << ": " << y << "; " << s << "; " << dabs(y-s) << endl;
    }

    system("pause");

    return 0;
}

double dabs(double a)
{
    return a > 0 ? a : -a;
}