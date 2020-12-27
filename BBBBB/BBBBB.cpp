#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

const int STR_LEN = 256;

struct student
{
    char name[STR_LEN];
    int group;
    double phys;
    double math;
    double inf;
};

int main()
{
    student s;
    FILE *f = fopen("da.txt", "rb");

    fread(&s, sizeof(student), 1, f);

    system("pause");

    return 0;
}