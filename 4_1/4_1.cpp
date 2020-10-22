#include <iostream>
using namespace std;

const int N = 5;

int main ()
{
    int a[N],
        s = 0,
        k = 0;
    
    cout << "Enter " << N << " values: ";
    
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    while (a[k] >= 0 and k < N) k++;
    k++;
    
    while (k < N) 
    {
        s += abs(a[k]);
        k++;
    }
    
    cout << "\ns = " << s << endl;

    system("pause");
    
    return 0;
}