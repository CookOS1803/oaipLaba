#include <iostream>
#include <time.h>

using namespace std;

struct list
{
    int info;
    list *prev = nullptr,
         *next = nullptr;
};

void create_list(list*& b, list*& e, int info);
void in_list_to_begin(list*& b, int info);
void in_list_to_end(list*& e, int info);
void view_list_from_begin(list* b);
void view_list_from_end(list* e);
void delete_list(list*& b, list*& e);
void solve(list*& b, list*& e, list*& tb, list*& te);

int main()
{
    srand(time(0));

    int choice, n;
    bool exit = false;
    list *b = nullptr,
         *e = nullptr,
         *tb = nullptr,
         *te = nullptr;

    while (!exit)
    {
        cout << "1. Create\n2. Add\n3. View\n4. Delete\n5. Solve Task\n6. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (b) cout << "Clear memory first\n\n";
                else
                {
                    cout << "Enter amount: ";
                    cin >> n;
                    if (n < 1) break;

                    create_list(b, e, rand() % 21 - 10);

                    for (int i = 1; i < n; i++)
                    {
                        in_list_to_begin(b, rand() % 21 - 10);
                    }
                }
            break;
            case 2:
                if (!b)
                {
                    cout << "Create list first\n\n";
                    break;
                }

                cout << "Enter amount: ";
                cin >> n;
                
                cout << "1. Add to begin\n2. Add to end\n";
                cin >> choice;

                if (choice == 1)
                {
                    for (int i = 0; i < n; i++)
                    {
                        in_list_to_begin(b, rand() % 21 - 10);
                    }
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        in_list_to_end(e, rand() % 21 - 10);
                    }
                }
            break;
            case 3:
                cout << "1. View from begin\n2. View from end\n";
                cin >> choice;

                if (choice == 1) view_list_from_begin(b);
                else             view_list_from_end(e);
                cout << endl;
            break;
            case 4:
                delete_list(b, e);
                delete_list(tb, te);
            break;
            case 5: solve(b, e, tb, te); break;
            case 6:
                delete_list(b, e);
                delete_list(tb, te);
                exit = true;
            break;
        }
    }

    return 0;
}

void create_list(list*& b, list*& e, int info)
{
    list* t = new list;

    t->info = info;
    b = e = t;
}

void in_list_to_begin(list*& b, int info)
{
    list* t = new list;
    t->info = info;

    t->next = b;
    b->prev = t;
    b = t;
}

void in_list_to_end(list*& e, int info)
{
    list* t = new list;
    t->info = info;

    t->prev = e;
    e->next = t;
    e = t;
}

void view_list_from_begin(list* b)
{
    while (b)
    {
        cout << b->info << " ";
        b = b->next;
    }
    cout << endl;
}

void view_list_from_end(list* e)
{
    while (e)
    {
        cout << e->info << " ";
        e = e->prev;
    }
    cout << endl;
}

void delete_list(list*& b, list*& e)
{
    list* t;

    while (b)
    {
        t = b;
        b = b->next;
        delete t;
    }
    e = nullptr;
}

void solve(list*& b, list*& e, list*& tb, list*& te)
{
    if (tb) delete_list(tb, te);

    in_list_to_begin(b, 0);
    list *t1 = b,
         *buf;

    while (t1->next)
    {
        if (t1->next->info % 2)
        {
            buf = t1->next;
            t1->next = buf->next;

            buf->next = tb;
            buf->prev = nullptr;

            tb = buf;
            te = tb;
            break;
        }
        else t1 = t1->next;
    }

    if (t1->next)
    {
        while (t1->next->next)
        {
            if (t1->next->info % 2)
            {
                buf = t1->next;
                t1->next = buf->next;
                t1->next->prev = t1;

                buf->next = tb;
                buf->next->prev = buf;
                buf->prev = nullptr;

                tb = buf;
            }
            else t1 = t1->next;
        }

        if (t1->next->info % 2)
        {
            if (t1->next = e) e = t1;

            buf = t1->next;
            t1->next = nullptr;

            buf->next = tb;
            buf->next->prev = buf;
            buf->prev = nullptr;

            tb = buf;
        }
    }

    t1 = b;
    b = t1->next;
    if (b) b->prev = nullptr;
    delete t1;
}