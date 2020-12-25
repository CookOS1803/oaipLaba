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
	fgetc(stdin);

	switch (choice)
	{
		case 1:
			if (!(f = fopen(FILE_NAME, "w")))
				cout << "Error\n";
			else 
				fclose(f);
		break;
		case 2:
			if (!(f = fopen(FILE_NAME, "r")))
			{
				cout << "Error\n";
				break;
			}


		break;
		case 3:
		{
			if (!(f = fopen(FILE_NAME, "a")))
			{
				cout << "Error\n";
				break;
			}

			char str[STR_LEN];
			double avrg;

			fputc('\n', f);

			cout << "Enter last name: ";
			cin.getline(str, STR_LEN);
			fputs(str, f);
			fputc('\n', f);

			cout << "Enter group number: ";
			cin.getline(str, STR_LEN);
			fputs(str, f);
			fputc('\n', f);

			fputs("phy\n", f);
			cout << "Enter physic grades: ";
			cin.getline(str, STR_LEN);
			fputs(str, f);
			fputc('\n', f);
			avrg = atof(str);

			fputs("mat\n", f);
			cout << "Enter math grades: ";
			cin.getline(str, STR_LEN);
			fputs(str, f);
			fputc('\n', f);
			avrg += atof(str);

			fputs("inf\n", f);
			cout << "Enter informatik grades: ";
			cin.getline(str, STR_LEN);
			fputs(str, f);
			fputc('\n', f);
			avrg += atof(str);

			avrg /= 3;
			fputs("avr\n", f);
			snprintf(str, STR_LEN, "%f", avrg);
			fputs(str, f);
			fputc('\n', f);

			fclose(f);
		}
		break;
		case 4: ;  break;
	}

	

	system("pause");

	return 0;
}
