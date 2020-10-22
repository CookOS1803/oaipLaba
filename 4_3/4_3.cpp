#include <iostream>
using namespace std;

bool func(int* arr, int size);
bool check_input(bool fail_flag);

int main()
{
    int n, k = 0;
    int* a;

    do cout << "Enter array size (>1): ";
    while (!check_input(!(cin >> n)) or n <= 1);

    a = new int[n];
    
    do
    {
        cout << "Enter " << n << " values: ";

        while (k < n)
        {
            if (!check_input(!(cin >> a[k])))
            {
                k = 0;
                break;
            }
            k++;
        }
    }
    while (k == 0);

    if (func(a, n))
    { 
        cout << "Result: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    else cout << "Array doesn't have zeroes "
              << "or has only one zero";
    cout << endl;

    system("pause");

    return 0;
}

bool func(int* arr, int size)
{
    int first = 0,
        last = size;

    for (int i = 0; i < size; i++)
        if (arr[i] == 0) last = i;

    if (last == size or last == 0) return false;

    while (arr[first] != 0 and first < size) first++;

    if (first == last) return false;

    first++;
    last--;

    while (first < last)
    {
        arr[first] = arr[first] ^ arr[last];
        arr[last]  = arr[first] ^ arr[last];
        arr[first] = arr[first] ^ arr[last];

        first++;
        last--;
    }

    return true;
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