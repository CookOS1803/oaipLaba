﻿#define _CRT_SECURE_NO_DEPRECATE
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
void create();
void view();
void add();
void solve();

int main()
{
	int choice;
	bool exit = false;
	
	while (!exit)
	{
		cout << "1. Create\n2. View\n3. Add\n4. Solve Task\n5. Exit\n";
		cin >> choice;

		switch (choice)
		{
			case 1: create();    break;
			case 2: view();      break;
			case 3: add();       break;
			case 4: solve();     break;
			case 5: exit = true; break;
		}
	}

	return 0;
}

void show_student(const student& s)
{
	cout << "Last name: " << s.name
		<< "\nGroup number: " << s.group
		<< "\nPhysic score: " << s.phys
		<< "\nMath score: " << s.math
		<< "\nInformatics score: " << s.inf
		<< "\nAverage score: " << s.average
		<< endl << endl;
}

void create()
{
	FILE *f;

	if (!(f = fopen(FILE_NAME, "wb")))
		cout << "Error\n";
	else
		fclose(f);
}


void view()
{
	FILE *f;

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
	FILE *f;

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

		while (fread(&s, sizeof(student), 1, f))
		{
			if (s.group == group and s.average > avrg)
			{
				cout << s.name << endl;
			}
		}
	}

	fclose(f);
}
