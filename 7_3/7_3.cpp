#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

const int STR_LEN = 256;
const char* FILE_NAME = "output.txt";

void encrypt(char* str);

int main()
{
	FILE* f;

	if (!(f = fopen(FILE_NAME, "wt")))
	{
		cout << "Error\n";
		system("pause");
		return 1;
	}

	char str[STR_LEN];
	cout << "Enter string: ";
	cin.getline(str, STR_LEN);

	fputs(str, f);
	fgets(str, STR_LEN, f);

	encrypt(str);
	cout << str << endl;

	system("pause");

	return 0;
}

void encrypt(char* str)
{
	int l = strlen(str);
	char temp;
	
	for (int i = 0; i < l - 1; i += 2)
	{
		temp = str[i];
		str[i] = str[i + 1];
		str[i + 1] = temp;
	}
}