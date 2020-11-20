#include <iostream>
using namespace std;

int main()
{
    int n, **a, max;

    cout << "Enter n: ";
    cin >> n;

    a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << n << " values for the row " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    
    max = a[n - 1][1];

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = n - i; j < n; j++)
        {
            if (max < a[i][j]) max = a[i][j];
        }
    }

    cout << "max = " << max << endl;

    delete[] a;

    system("pause");

    return 0;
}