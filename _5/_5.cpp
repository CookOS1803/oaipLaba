#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct stack_c
{
    char info;
    stack_c* next = nullptr;
};

struct stack_d
{
    double info;
    stack_d* next = nullptr;
};

stack_c* in_stack(stack_c* s, char info);
stack_c* out_stack(stack_c* s, char* info);
stack_d* in_stack(stack_d* s, double info);
stack_d* out_stack(stack_d* s, double* info);
char* translate(char* in);
double result(char* str, double* data);
int priority(char c);

int main()
{
    char str[32];// = "(a-b)/(c+d)*e";
    double data[5];

    cout << "Enter formula: ";
    cin.getline(str, sizeof(str));

    strcpy(str, translate(str));
    cout << str << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter " << (char)(i + 97) << ": ";
        cin >> data[i];
    }
    cout << endl;
    cout << result(str, data) << endl;

    system("pause");
    return 0;
}

stack_c* in_stack(stack_c* s, char info)
{
    stack_c* t = new stack_c;

    t->info = info;
    t->next = s;

    return t;
}

stack_c* out_stack(stack_c* s, char* info)
{
    stack_c* t = s;

    if (info) *info = s->info;
    s = s->next;

    delete t;
    return s;
}

stack_d* in_stack(stack_d* s, double info)
{
    stack_d* t = new stack_d;

    t->info = info;
    t->next = s;

    return t;
}

stack_d* out_stack(stack_d* s, double* info)
{
    stack_d* t = s;

    if (info) *info = s->info;
    s = s->next;

    delete t;
    return s;
}

char* translate(char* in)
{
    stack_c *s = nullptr;
    char c,
         a[2],
         out[32] = "";

    a[1] = '\0';

    for (int i = 0; i < strlen(in); i++)
    {
        c = in[i];

        if (c >= 'a' and c <= 'z')
        {
            a[0] = c;
            strcat(out, a);
        }
        else switch (c)
        {
            case '(':
                s = in_stack(s, c);
            break;
            case ')':
                while (s->info != '(')
                {
                    s = out_stack(s, a);
                    strcat(out, a);
                }
                s = out_stack(s, nullptr);
            break;
            case '*': case '/': case '+': case '-':
                while (s and priority(s->info) >= priority(c))
                {

                    s = out_stack(s, a);
                    strcat(out, a);
                }
                s = in_stack(s, c);
            break;
        }
    }

    while (s)
    {
        s = out_stack(s, a);
        strcat(out, a);
    }
    
    return out;
}

double result(char* str, double* data)
{
    stack_c *s = nullptr;
    stack_d *d = nullptr;
    char c, t;
    double op1, op2, res;

    for (int i = 0; i < strlen(str); i++)
    {
        c = str[i];

        if (!priority(c)) s = in_stack(s, c);
        else
        {
            if (!d)
            {
                s = out_stack(s, &t);
                op1 = data[t - 97];
                s = out_stack(s, &t);
                op2 = data[t - 97];
            }
            else if (!d->next)
            {
                s = out_stack(s, &t);
                op1 = data[t - 97];
                d = out_stack(d, &op2);
            }
            else
            {
                d = out_stack(d, &op1);
                d = out_stack(d, &op2);
            }

            switch (c)
            {
                case '+': res = op2 + op1; break;
                case '-': res = op2 - op1; break;
                case '*': res = op2 * op1; break;
                case '/': res = op2 / op1; break;
            }
            
            d = in_stack(d, res);
        }
    }

    d = out_stack(d, &res);
    return res;
}

int priority(char c)
{
    switch (c)
    {
        case '*': case '/': return 3;
        case '+': case '-': return 2;
        case '(':           return 1;
        default:            return 0;
    }
}