#include <iostream>
using namespace std;

const int STR_LEN = 256;

int main()
{
    char str[STR_LEN];
    int k = 0;

    cout << "Enter string: ";
    cin.getline(str, STR_LEN);

    for (int i = 0, j = 1; str[i] != '\0' and j <= 4; i++)
    {
        if (j >= 2)
        {
            str[k] = str[i];
            k++;
        }

        if (str[i] == ' ') j++;
    }
    str[k] = '\0';

    cout << str;

    system("pause");

    return 0;
}