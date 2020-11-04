#include <iostream>
#include <time.h>
using namespace std;

const int N = 5;

int main ()
{
    srand(time(0));

    int a[N],
        choice,
        k = N,
        m = 0,
        sum = 0,
        mult = 1;
    double avrg;

    cout << "Select random (1) or manual (2) array: ";
    cin >> choice;
    
    switch (choice)
    {
        default:
        case 1:
            cout << "Random array: ";

            for (int i = 0; i < N; i++)
            { 
                a[i] = rand() % 11 - 5;
                cout << a[i] << " ";
            }

            cout << endl;
        break;
        case 2:
            cout << "Enter " << N << " values: ";

            for (int i = 0; i < N; i++)
                cin >> a[i];
        break;
    }

    for (int i = N - 1; i >= 0; i--)
    { 
        if (a[i] == 0) 
        { 
            k = i + 1;
            break;
        }
    }

    if (k >= N)
    {
        cout << "Array doesn't have zeroes or last zero is the last element\n";
        system("pause");

        return 0;
    }

    for (int i = k; i < N; i++, m++)
        sum += a[i];

    avrg = (double)sum / m;

    while (k < N)
    {
        if (a[k] <= avrg) mult *= a[k];
        k++;
    }

    cout << "Multiplication: " << mult << endl;

    system("pause");
    
    return 0;
}