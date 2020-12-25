#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
using namespace std;

const int STR_LEN = 256;

struct aga
{
    int roll;
    char name[10];
    float marks; 
};

int main()
{
    FILE *f;
    int d;
    char str[STR_LEN];
    aga stud= {0,"rima", 88.123}; 

    cin >> d;
    fgetc(stdin);
    if (!(f = fopen("da.txt", "at")))
    {
        cout << "Error\n";
        return -1;
    }

    cout << "Nu davay: ";

    fwrite(&stud, sizeof(stud), 1, stdout);

    fclose(f);

    system("pause");

    return 0;
}