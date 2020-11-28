#include <iostream>
using namespace std;

const int STR_LEN = 256;

int main()
{
    char str[STR_LEN];

    cout << "Enter string: ";
    cin.getline(str, STR_LEN);

    int l = strlen(str);

    cout << "String length: " << l;

    if (l != 0 and l % 4 == 0)
    {
        for (int i = 0; i < l / 2; i++)
        {
            char temp = str[i];
            str[i] = str[l / 2 + i];
            str[l / 2 + i] = temp;
        }

        cout << endl << "New string: " << str << endl;
    }
    else cout << " (is not a multiple of 4)" << endl;

    system("pause");

    return 0;
}