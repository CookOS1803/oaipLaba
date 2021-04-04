#include <iostream>
#include <time.h>
using namespace std;

struct stack
{
    int info;
    stack* next = nullptr;
};

stack* in_stack(stack* s, int info);
stack* out_stack(stack* s, int* info);
stack* out_stack(stack* s);
void view_stack(stack* s);
void delete_stack(stack*& s);
void sort_p(stack*& s);
void sort_info(stack* s);
void solve(stack* s);

int main()
{
    srand(time(0));

    int choice, n;
    bool exit = false;
    stack* s = nullptr;

    while (!exit)
    {
        cout << "1. Create\n2. Add\n3. View\n4. Delete\n5. Solve Task\n6. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (s != nullptr)
                {
                    cout << "Clear memory first\n\n";
                    break;
                }
            case 2:
                cout << "Enter amount: ";
                cin >> n;

                for (int i = 0; i < n; i++)
                {
                    s = in_stack(s, rand() % 21 - 10);
                }

            break;
            case 3:
                cout << "Stack: ";
                view_stack(s);
                cout << endl;
            break;
            case 4: delete_stack(s); break;
            case 5: solve(s);        break;
            case 6: exit = true;     break;
        }
    }

    return 0;
}

stack* in_stack(stack* s, int info)
{
    stack* t = new stack;
    
    t->info = info;
    t->next = s;

    return t;
}

stack* out_stack(stack* s, int* info)
{
    stack* t = s;

    if (info != nullptr) *info = s->info;
    s = s->next;

    delete t;
    return s;
}

stack* out_stack(stack* s)
{
    return out_stack(s, nullptr);
}

void view_stack(stack* s)
{
    while (s != nullptr)
    {
        cout << s->info << " ";
        s = s->next;
    }

    cout << endl;
}

void delete_stack(stack*& s)
{
    stack* t;

    while (s != nullptr)
    {
        t = s;
        s = s->next;
        delete t;
    }
}

void sort_p(stack*& s)
{
    stack *t = nullptr, *t1, *r;

    if (s->next->next == nullptr) return;

    s = in_stack(s, 0);

    do
    {
        for (t1 = s; t1->next->next != t; t1 = t1->next)
        {
            if (t1->next->info > t1->next->next->info)
            {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        }
        
        t = t1->next;

    } while (s->next->next != t);

    s = out_stack(s);
}

void sort_info(stack* s)
{
    stack *t = nullptr, *t1;
    int r;

    do
    {
        for (t1 = s; t1->next != t; t1 = t1->next)
        {
            if (t1->info > t1->next->info)
            {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        }

        t = t1;

    } while (s->next != t);
}

void solve(stack* s)
{
    s = in_stack(s, 0);
    stack *t1 = s,
          *t2 = nullptr,
          *buf;

    while (t1->next != nullptr)
    {
        if (t1->next->info % 2)
        {
            buf = t1->next;
            t1->next = buf->next;
            buf->next = t2;
            t2 = buf;
        }
        else t1 = t1->next;
    }
    t1 = s;
    s = t1->next;
    delete t1;

    cout << "Even: "; view_stack(s);
    cout << "Odd: ";  view_stack(t2);
}