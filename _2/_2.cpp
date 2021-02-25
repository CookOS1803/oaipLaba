#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

const char* FILE_NAME = "records.dat";

struct record
{
	int flight_number;
	char aircraft_type[32];
	char destination[64];
	char departure_time[13];
};

void show_record(const record& r);
void create();
void view();
void add();
void selection_sort();
void quick_sort();
void linear_search();
void binary_search();

int main()
{
	int choice;
	bool exit = false;

	while (!exit)
	{
		cout << "1. Create\n2. View\n3. Add\n4. Selection Sort\n"
			 << "5. Quick Sort\n6. Linear Search\n7. Binary Search\n"
			 << "8. Exit\n";
		cin >> choice;
		fgetc(stdin);

		switch (choice)
		{
			case 1: create();		  break;
			case 2: view();			  break;
			case 3: add();			  break;
			case 4: selection_sort(); break;
			case 5: quick_sort();	  break;
			case 6: linear_search();  break;
			case 7: binary_search();  break;
			case 8: exit = true;	  break;
		}
	}

	return 0;
}

void show_record(const record& r)
{
	cout << "Flight Number: "	<< r.flight_number
		 << "\nAircraft Type: " << r.aircraft_type
		 << "\nDestination: "	<< r.destination
		 << "\nDeparture Time: "
		 << r.departure_time[0] << r.departure_time[1]
		 << ":" << r.departure_time[2] << r.departure_time[3]
		 << ", " << r.departure_time[4] << r.departure_time[5]
		 << "." << r.departure_time[6] << r.departure_time[7]
		 << "." << r.departure_time[8] << r.departure_time[9]
		 << r.departure_time[10] << r.departure_time[11]
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

	record r;

	while (fread(&r, sizeof(record), 1, f))
	{
		show_record(r);
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

	record r;

	cout << "Enter flight number: ";
	cin >> r.flight_number;
	fgetc(stdin);

	cout << "Enter aircraft type: ";
	cin.getline(r.aircraft_type, sizeof(r.aircraft_type));

	cout << "Enter destination: ";
	cin.getline(r.destination, sizeof(r.destination));

	cout << "Enter departure time (format: hhmmDDMMYYYY): ";
	cin.getline(r.departure_time, sizeof(r.departure_time));

	fwrite(&r, sizeof(record), 1, f);

	fclose(f);
}

void selection_sort()
{
	FILE *f;

	if (!(f = fopen(FILE_NAME, "r+b")))
	{
		cout << "Error\n";
		return;
	}

	fseek(f, 0, SEEK_END);
	int n = ftell(f) / sizeof(record);
	rewind(f);

	int m;
	record r1, r2;

	for (int i = 0; i < n - 1; i++)
	{	

		fseek(f, sizeof(record) * i, SEEK_SET);
		fread(&r1, sizeof(record), 1, f);

		m = i;

		for (int j = i + 1; fread(&r2, sizeof(record), 1, f); j++)
		{
			if (r2.destination[0] < r1.destination[0])
			{
				r1 = r2;
				m = j;
			}
		}

		if (m != i)
		{
			fseek(f, sizeof(record) * i, SEEK_SET);
			fread(&r2, sizeof(record), 1, f);
			fseek(f, sizeof(record) * i, SEEK_SET);
			fwrite(&r1, sizeof(record), 1, f);
			fseek(f, sizeof(record) * m, SEEK_SET);
			fwrite(&r2, sizeof(record), 1, f);
		}
	}

	fclose(f);
}

void quick_sort()
{
	FILE *f;

	if (!(f = fopen(FILE_NAME, "r+b")))
	{
		cout << "Error\n";
		return;
	}

	fseek(f, 0, SEEK_END);
	int i = 0,
		j = ftell(f) / sizeof(record) - 1;
	
	record r1, r2;
	fseek(f, sizeof(record) * (j / 2 + 1), SEEK_SET);
	fread(&r1, sizeof(record), 1, f);
	char key[sizeof(r1.destination)];
	strcpy(key, r1.destination);

	while (i <= j)
	{
		fseek(f, sizeof(record) * i, SEEK_SET);		
		while (fread(&r1, sizeof(record), 1, f) and r1.destination[0] < key[0]) i++;

		fseek(f, sizeof(record) * j, SEEK_SET);
		while (fread(&r2, sizeof(record), 1, f) and r2.destination[0] > key[0])
		{
			fseek(f, sizeof(record) * --j, SEEK_SET);
		}

		if (i <= j)
		{
			fseek(f, sizeof(record) * i, SEEK_SET);
			fwrite(&r2, sizeof(record), 1, f);
			fseek(f, sizeof(record) * j, SEEK_SET);
			fwrite(&r1, sizeof(record), 1, f);
			i++; j--;
		}
	}

	fclose(f);
}

void linear_search()
{
	FILE *f;

	if (!(f = fopen(FILE_NAME, "rb")))
	{
		cout << "Error\n";
		return;
	}

	char sought[sizeof(record::destination)];
	cout << "Enter destination: ";
	cin.getline(sought, sizeof(sought));

	record r;

	while (fread(&r, sizeof(record), 1, f))
	{
		if (!strcmp(r.destination, sought))
		{
			cout << "\nResult:\n";
			show_record(r);
			fclose(f);
			return;
		}
	}

	cout << "\nThere is no such record\n\n";
	fclose(f);

}

void binary_search()
{
	FILE *f;

	if (!(f = fopen(FILE_NAME, "rb")))
	{
		cout << "Error\n";
		return;
	}

	char sought[sizeof(record::destination)];
	cout << "Enter destination: ";
	cin.getline(sought, sizeof(sought));

	fseek(f, 0, SEEK_END);
	int i = 0,
		j = ftell(f) / sizeof(record) - 1,
		m;

	record r;

	while (i < j)
	{
		m = (i + j) / 2;

		fseek(f, sizeof(record) * m, SEEK_SET);
		fread(&r, sizeof(record), 1, f);

		if (r.destination[0] < sought[0]) i = m + 1;
		else j = m;
	}

	fseek(f, sizeof(record) * i, SEEK_SET);
	fread(&r, sizeof(record), 1, f);
	if (!strcmp(r.destination, sought))
	{
		cout << "\nResult:\n";
		show_record(r);
	}
	else cout << "\nThere is no such record\n\n";

	fclose(f);
}
