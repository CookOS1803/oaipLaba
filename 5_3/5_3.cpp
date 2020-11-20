#include <iostream>
using namespace std;

bool check_input(bool fail_flag);
void func(double** arr, int order, double& sum, double& mult);

int main()
{
    int n;
    double **a, sum, mult;

    do cout << "Enter n (>=3): ";
    while (!check_input(!(cin >> n)) or n < 3);

    a = new double*[n];
    for (int i = 0; i < n; i++)
        a[i] = new double[n];

    for (int i = 0; i < n; i++)
    {
        int j;
        do
        {
            cout << "Enter " << n << " values for the row " << i + 1 << ": ";
            for (j = 0; j < n; j++)
            {
                if (!check_input(!(cin >> a[i][j])))
                {
                    cout << "Error" << endl;
                    break;
                }
            }
        }
        while (j < n);
    }
    
    func(a, n, sum, mult);

    cout << "summ = " << sum << endl
         << "multiplication = " << mult << endl;
    
    delete[] a;

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

void func(double** arr, int order, double& sum, double& mult)
{
    sum = 0, mult = 1;
    int last = order - 1;
    
    for (int i = 1; i <= last / 2; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum  += arr[i][j];
            mult *= arr[i][j];

            sum  += arr[i][last - j];
            mult *= arr[i][last - j];

            if (i != last - i)
            {
                sum  += arr[last - i][j];
                mult *= arr[last - i][j];
                
                sum  += arr[last - i][last - j];
                mult *= arr[last - i][last - j];
            }
        }
    }
}
