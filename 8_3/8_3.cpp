#include <iostream>
using namespace std;

double y_normal(double x);
double y_recursive(double x);

int main()
{
    double a, b, h;
    int n;

    cout << "Enter a, b and h: ";
    cin >> a >> b >> h;
    
    cout << "Enter n: ";
    cin >> n;

    n = n % 2 ? n - 1 : n;
    double x = a;

    while (x <= b)
    {
        

        cout << "Y(x) normal: "    << y_normal(x)    << endl
             << "Y(x) recursive: " << y_recursive(x) << endl
             << endl;
    }

    system("pause");

    return 0;
}
