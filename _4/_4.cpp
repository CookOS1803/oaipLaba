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
void in_list(bool tobegin, list*& p, int info);
void view_list(bool frombegin, list* p);
void delete_list(list*& b);
void solve(list* b, list* e);

int main()
{
    srand(time(0));

    int choice, n;
    bool exit = false;
    list *b = nullptr,
         *e = nullptr;

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

                    create_list(b, e, rand() % 21 - 10);

                    for (int i = 1; i < n; i++)
                    {
                        in_list(true, b, rand() % 21 - 10);
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
                        in_list(true, b, rand() % 21 - 10);
                    }
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        in_list(false, e, rand() % 21 - 10);
                    }
                }
            break;
            case 3:
                cout << "1. View from begin\n2. View from end\n";
                cin >> choice;

                if (choice == 1) view_list(true, b);
                else             view_list(false, e);
                cout << endl;
            break;
            case 4: delete_list(b); break;
            case 5: solve(b, e);        break;
            case 6: exit = true;     break;
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

void in_list(bool tobegin, list*& p, int info)
{
    list* t = new list;
    t->info = info;

    if (tobegin)
    {
        t->next = p;
        p->prev = t;
        p = t;
    }
    else
    {
        t->prev = p;
        p->next = t;
        p = t;
    }
}

void view_list(bool frombegin, list* p)
{
    if (frombegin)
    {
        while (p)
        {
            cout << p->info << " ";
            p = p->next;
        }
    }
    else
    {
        while (p)
        {
            cout << p->info << " ";
            p = p->prev;
        }
    }
    cout << endl;
}

void delete_list(list*& b)
{
    list* t;

    while (b)
    {
        t = b;
        b = b->next;
        delete t;
    }
}

void solve(list* b, list* e)
{
    in_list(true, b, 0);
    list *t1 = b,
         *t2b = nullptr,
         *t2e = nullptr,
         *buf;

    while (t1->next != nullptr)
    {
        if (t1->next->info % 2)
        {
            if (t1->next == e) e = t1;
            else if (t1->next == e->prev) e->prev = t1;
            buf = t1->next;
            buf->prev = nullptr;
            t1->next = buf->next;
            if (t1->next) t1->next->prev = t1;
            buf->next = t2b;
            if (buf->next) buf->next->prev = buf;
            t2b = buf;
            if (!t2e) t2e = t2b;
        }
        else t1 = t1->next;
    }
    t1 = b;
    b = t1->next;
    b->prev = nullptr;
    delete t1;

    cout << "Even (from begin): "; view_list(true, b);
    cout << "Odd (from begin): ";  view_list(true, t2b);
    cout << "Even (from end): ";   view_list(false, e);
    cout << "Odd (from end): ";    view_list(false, t2e);
}