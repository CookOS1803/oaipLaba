#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

const int STR_LEN = 64;
const char* FILE_NAME = "rating.dat";

struct student
{
	char name[STR_LEN];
	int group;
	double phys;
	double math;
	double inf;
	double average;
};

void show_student(const student& s);
int get_students(FILE* f, student*& all);
void create();
void view();
void add();
void edit();
void erase();
void sort();
void solve();

int main()
{
	int choice;
	bool exit = false;

	while (!exit)
	{
		cout << "1. Create\n2. View\n3. Add\n4. Edit\n5. Erase\n6. Sort\n7. Solve Task\n8. Exit\n";
		cin >> choice;
		fgetc(stdin);

		switch (choice)
		{
			case 1: create();    break;
			case 2: view();      break;
			case 3: add();       break;
			case 4: edit();      break;
			case 5: erase();     break;
			case 6: sort();      break;
			case 7: solve();     break;
			case 8: exit = true; break;
		}
	}

	return 0;
}

void show_student(const student& s)
{
	cout << "Last name: "           << s.name
		 << "\nGroup number: "      << s.group
		 << "\nPhysic score: "      << s.phys
		 << "\nMath score: "        << s.math
		 << "\nInformatics score: " << s.inf
		 << "\nAverage score: "     << s.average
		 << endl << endl;
}

int get_students(FILE* f, student*& all)
{
	fseek(f, 0, SEEK_END);

	int quantity = ftell(f) / sizeof(student);
	all = new student[quantity];

	rewind(f);

	student s;
	for (int i = 0; fread(&s, sizeof(student), 1, f); i++)
		all[i] = s;

	return quantity;
}

void create()
{
	FILE* f;

	if (!(f = fopen(FILE_NAME, "wb")))
		cout << "Error\n";
	else
		fclose(f);
}


void view()
{
	FILE* f;

	if (!(f = fopen(FILE_NAME, "rb")))
	{
		cout << "Error\n";
		return;
	}

	student s;

	while (fread(&s, sizeof(student), 1, f))
	{
		show_student(s);
	}

	fclose(f);
}


void add()
{
	FILE* f;

	if (!(f = fopen(FILE_NAME, "ab")))
	{
		cout << "Error\n";
		return;
	}

	student s;

	cout << "Enter last name: ";
	cin.getline(s.name, STR_LEN);

	cout << "Enter group number: ";
	cin >> s.group;

	cout << "Enter physic score: ";
	cin >> s.phys;

	cout << "Enter math score: ";
	cin >> s.math;

	cout << "Enter informatics score: ";
	cin >> s.inf;

	s.average = (s.phys + s.math + s.inf) / 3;

	fwrite(&s, sizeof(student), 1, f);

	fclose(f);
}

void edit()
{
	FILE* f;

	if (!(f = fopen(FILE_NAME, "rb")))
	{
		cout << "Error\n";
		return;
	}

	student *all;
	int quantity = get_students(f, all);

	fclose(f);

	char name[STR_LEN];
	cout << "Enter last name: ";
	cin.getline(name, STR_LEN);

	student* s = nullptr;

	for (int i = 0; i < quantity; i++)
	{
		if (!strcmp(all[i].name, name))
		{
			s = &all[i];
			break;
		}
	}

	if (s == nullptr)
	{
		cout << "There's no such student\n";
		delete[] all;
		return;
	}

	int choice;
	cout << "Choose what to edit:\n"
		 << "1. Last name\n2. Group\n3. Physic score\n4. Math score\n5. Informatics score\n";
	cin >> choice;
	fgetc(stdin);

	switch (choice)
	{
		case 1:
			cout << "Enter last name: ";
			cin.getline(s->name, STR_LEN);
		break;
		case 2:
			cout << "Enter group number: ";
			cin >> s->group;
		break;
		case 3:
			cout << "Enter physic score: ";
			cin >> s->phys;
			s->average = (s->phys + s->math + s->inf) / 3;
		break;
		case 4:
			cout << "Enter math score: ";
			cin >> s->math;
			s->average = (s->phys + s->math + s->inf) / 3;
		break;
		case 5:
			cout << "Enter informatics score: ";
			cin >> s->inf;
			s->average = (s->phys + s->math + s->inf) / 3;
		break;
	}


	if (!(f = fopen(FILE_NAME, "wb")))
		cout << "Error\n";
	else
	{
		fwrite(all, sizeof(student) * quantity, 1, f);
		fclose(f);
	}

	delete[] all;
}

void erase()
{
	FILE* f;

	if (!(f = fopen(FILE_NAME, "rb")))
	{
		cout << "Error\n";
		return;
	}

	student *all;
	int quantity = get_students(f, all);

	fclose(f);

	if (!(f = fopen(FILE_NAME, "wb")))
		cout << "Error\n";
	else
	{
		char name[STR_LEN];
		cout << "Enter last name: ";
		cin.getline(name, STR_LEN);

		for (int i = 0; i < quantity; i++)
		{
			if (strcmp(all[i].name, name))
			{
				fwrite(&all[i], sizeof(student), 1, f);
			}
		}

		fclose(f);
	}

	delete[] all;
}

void sort()
{
	FILE* f;

	if (!(f = fopen(FILE_NAME, "rb")))
	{
		cout << "Error\n";
		return;
	}

	student *all;
	int quantity = get_students(f, all);

	fclose(f);

	student temp;
	for (int i = 0; i < quantity - 1; i++)
	{
		for (int j = 0 ; j < quantity - i - 1; j++)
		{
			if (all[j].name[0] > all[j + 1].name[0])
			{
				temp = all[j];
				all[j] = all[j + 1];
				all[j + 1] = temp;
			}
		}
	}

	if (!(f = fopen(FILE_NAME, "wb")))
		cout << "Error\n";
	else
	{
		fwrite(all, sizeof(student) * quantity, 1, f);

		fclose(f);
	}

	delete[] all;
}

void solve()
{
	FILE* f;

	if (!(f = fopen(FILE_NAME, "rb")))
	{
		cout << "Error\n";
		return;
	}

	student s;
	int group, n = 0;
	double avrg = 0;

	cout << "Enter group number: ";
	cin >> group;

	while (fread(&s, sizeof(student), 1, f))
	{
		if (s.group == group)
		{
			n++;
			avrg += s.average;
		}
	}

	if (n != 0)
	{
		avrg = avrg / n;

		rewind(f);

		cout << endl;
		while (fread(&s, sizeof(student), 1, f))
		{
			if (s.group == group and s.average > avrg)
			{
				cout << s.name << endl;
			}
		}
		cout << endl;
	}

	fclose(f);
}