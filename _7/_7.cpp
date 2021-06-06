#include <iostream>

using namespace std;

struct record
{
	int flight_number;
	int departure_time;
	char destination[64];
};

struct stack
{
    record info;
    stack* next = nullptr;
};

void show_record(record r);
stack* in_stack(stack* s, record info);
void delete_stack(stack*& s);
void add_hashtable(stack **hashtable, record info, int m);
record find_info(stack **hashtable, int key, int m);
void delete_hashtable(stack **&hashtable, int m);

int main()
{
    int n, m, choice;
    record *arr = nullptr,
            t;
    stack **hashtable = nullptr,
           *temp;
    bool exit = false;    

    while (!exit)
    {
        cout << "1. Create array\n2. Create hashtable\n3. Find info\n4. Show\n5. Delete\n6. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (arr) cout << "Clear memory first\n\n";
                else
                {
                    cout << "Enter amount: ";
                    cin >> n;
                    if (n < 1) break;

                    arr = new record[n];

                    for (int i = 0; i < n; i++)
                    {
                        cout << "Enter " << i + 1 << " flight number: ";
                        cin >> arr[i].flight_number;

                        cout << "Enter " << i + 1 << " departure time: ";
                        cin >> arr[i].departure_time;
                        getc(stdin);

                        cout << "Enter " << i + 1 << " destination: ";
                        cin.getline(arr[i].destination, sizeof(arr[i].destination));                        
                    }
                }
            break;
            case 2:
                if (!arr) cout << "Create array first\n\n";
                else
                {
                    if (hashtable) delete_hashtable(hashtable, m);

                    cout << "Enter amount: ";
                    cin >> m;
                    if (m < 1) break;

                    hashtable = new stack*[m];
                    for (int i = 0; i < m; i++)
                        hashtable[i] = nullptr;

                    for (int i = 0; i < n; i++)
                        add_hashtable(hashtable, arr[i], m);
                }
            break;
            case 3:
                if (!hashtable) cout << "Create hashtable first\n\n";
                else
                {
                    cout << "Enter departure time: ";
                    cin >> choice;

                    t = find_info(hashtable, choice, m);

                    if (t.departure_time == -1) cout << "There is no such record\n\n";
                    else show_record(t);
                }
            break;
            case 4:
                if (!arr) cout << "Create array first\n\n";
                else
                {
                    cout << "Array: \n";
                    for (int i = 0; i < n; i++)
                    {
                        cout << i << ":\n";
                        show_record(arr[i]);
                    }

                    if (hashtable)
                    {
                        cout << "Hashtable: \n";
                        for (int i = 0; i < m; i++)
                        {
                            cout << i << ":\n";

                            temp = hashtable[i];
                            while (temp)
                            {
                                show_record(temp->info);
                                temp = temp->next;
                            }
                        }
                    }
                }
            break;
            case 6: exit = true;
            case 5:
                delete[] arr;
                arr = nullptr;
                delete_hashtable(hashtable, m);
            break;
        }
    }

    return 0;
}

void show_record(record r)
{
    cout << "\tFlight number: "  << r.flight_number  << endl;
    cout << "\tDeparture time: " << r.departure_time << endl;
    cout << "\tDestination: "    << r.destination    << endl << endl;
}

stack* in_stack(stack* s, record info)
{
    stack* t = new stack;

    t->info = info;
    t->next = s;

    return t;
}

void delete_stack(stack*& s)
{
    stack* t;

    while (s)
    {
        t = s;
        s = s->next;
        delete t;
    }
}

void add_hashtable(stack** hashtable, record info, int m)
{
    int i = info.departure_time % m;

    hashtable[i] = in_stack(hashtable[i], info);
}

record find_info(stack** hashtable, int key, int m)
{
    stack *t = hashtable[key % m];

    while (t and t->info.departure_time != key) t = t->next;

    if (t) return t->info;

    return {-1, -1, '\0'};
}

void delete_hashtable(stack**& hashtable, int m)
{
    for (int i = 0; i < m; i++)
        delete_stack(hashtable[i]);
    delete[] hashtable;
    hashtable = nullptr;
}

//4
//4
//4
//75
//75
//75
//23
//23
//23
//20
//20
//20
//11
//11
//11
//21
//21
//21
//73
//73
//73
//101
//101
//101
//66
//66
//66
//99
//99
//99