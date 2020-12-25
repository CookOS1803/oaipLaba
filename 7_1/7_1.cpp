#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

const int STR_LEN = 256;
const char* FILE_NAME = "rating.txt";

int main()
{
	FILE *f;
	int choice;

	cout << "1. Create\n2. View\n3. Add\n4. Solve Task\n";
	cin >> choice;

	switch (choice)
	{
		case 1:
			if (!(f = fopen(FILE_NAME, "wt")))
				cout << "Error\n";
			else 
				fclose(f);
		break;
		case 2: ;   break;
		case 3:
		{
			if (!(f = fopen(FILE_NAME, "at")))
			{
				cout << "Error\n";
				break;
			}

			char str[STR_LEN];

			cout << "Enter last name: ";
			cin.getline(str, STR_LEN);
			fwrite(str, sizeof(char), sizeof(str), f);

			fclose(f);

			break;
		}
		case 4: ;  break;
	}

	

	system("pause");

	return 0;
}
