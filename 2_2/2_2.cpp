#include <iostream>
#include <math.h>
using namespace std;

bool check_input(bool fail_flag);

int main() //dsad
{
    double n, k, m, z, x, f, y;
    int choice;
    
    do cout << "Enter n, k, z and m (m > 0): ";
    while (!check_input(!(cin >> n >> k >> z >> m)) || m <= 0);

    do cout << "Select f(x):\n1) 2x\n2) x^2\n3) x/3\n";
    while (!check_input(!(cin >> choice)) || choice < 1 || choice > 3);

    if (z > 1)
    {
        cout << "z > 1\n";
        x = z;
    }
    else
    {
        cout << "z <= 1\n";
        x = z*z + 1;
    }

    switch (choice)
    {
        case 1:
            cout << "f(x) = 2x\n";
            f = 2*x;
        break;
        case 2:
            cout << "f(x) = x^2\n";
            f = x*x;
        break;
        case 3:
            cout << "f(x) = x/3\n";
            f = x/3;
        break;
    }

    y = sin(n*f) + cos(k*x) + log(m*x);

    cout << "y = " << y << endl;

    system("pause");

    return 0;
}

bool check_input(bool fail_flag)
{
    if (fail_flag)
    {
        cin.clear();
        while (cin.get() != '\n');
        
        return false;
    }
    else return true;
}
