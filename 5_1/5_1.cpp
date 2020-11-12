#include <iostream>
using namespace std;

int main()
{
    int n, m, **a;

    cout << "Enter n and m: ";
    cin >> n >> m;

    a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << m << " values for the row " << i + 1 << ": ";
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == 0)
            {
                cout << "First column with zero is " << j + 1 << endl;
                j = -1;
                break;
            }
        }
        if (j == -1) break;
    }
    
    system("pause");

    return 0;
}