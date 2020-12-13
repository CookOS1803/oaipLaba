#include <iostream>
using namespace std;

const int STR_LEN = 256;

int main()
{
    char str[STR_LEN];
    int i = 0, j = 0, n = 0;

    cout << "Enter string: ";
    cin.getline(str, STR_LEN);

    while (str[i] != '\0' and (str[i] == ' ' or n < 1))
    {
        if (str[i] != ' ' and str[i + 1] == ' ')
            n++;
        i++;
    }

    while (str[i] != '\0' and n < 4)
    {
        str[j] = str[i];

        if (str[i] != ' ' and str[i + 1] == ' ')
            n++;

        i++; j++;
    }
    str[j] = '\0';
    
    cout << str;

    system("pause");

    return 0;
}