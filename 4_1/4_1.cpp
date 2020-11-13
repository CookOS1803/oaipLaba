#include <iostream>
using namespace std;

const int N = 5;

int main ()
{
    int a[N],
        s,
        k = 0;
    
    cout << "Enter " << N << " values: ";
    
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    while (a[k] >= 0 and k < N) k++;
    k++;

    if (k >= N) 
    {
        cout << "Array doesn't have negative numbers or the first negative number is the last element\n\n";
        system("pause");
        return 0;
    }

    s = 0;
    
    while (k < N) 
    {
        s += abs(a[k]);
        k++;
    }
    
    cout << "\ns = " << s << endl;

    system("pause");
    
    return 0;
}