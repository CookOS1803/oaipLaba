#include <iostream>
using namespace std;

const int STR_LEN = 256;

int main()
{
    char str[STR_LEN];
    int i = 0, k = 0;

    cout << "Enter string: ";
    cin.getline(str, STR_LEN);

    while (str[i] == ' ') i++;

    for (int j = 1; str[i] != '\0' and j <= 4; i++)
    {
        if (j >= 2)
        {
            str[k] = str[i + 1];
            k++;
        }
        
        if (str[i] != ' ' and str[i + 1] == ' ') j++;
    }
    str[k] = '\0';

    cout << str;

    system("pause");

    return 0;
}