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
    //попрубуй два циклв
    for (int j = 0; j < order; j++)
    {
        if (order - 1 - j == j or order - j == j)
            continue;

        for (int i = 1 + j; i < order - 1 - j; i++)
        {
            sum  += arr[i][j];
            mult *= arr[i][j];
        }
    }
}
