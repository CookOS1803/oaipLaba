#include <iostream>
using namespace std;

const int STR_LEN = 256;

int main()
{
    char str[STR_LEN],
         s1[STR_LEN],
         s2[STR_LEN];
    int k;

    cout << "Enter string: ";
    cin.getline(str, STR_LEN);

    cout << "Enter k: ";
    cin >> k;

    while (str[k] != ' ' and k > 0) k--;

    for (int i = 0; i < k; i++)
    {
        s1[i] = str[i];
    }
    s1[k] = '\0';

    for (int i = k + 1; i <= strlen(str); i++)
    {
        s2[i - k - 1] = str[i];
    }

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;

    system("pause");

    return 0;
}