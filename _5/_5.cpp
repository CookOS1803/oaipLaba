#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

template <typename T> struct stack
{
    T info;
    stack* next = nullptr;
};

template <typename T> stack<T>* in_stack(stack<T>* s, T info);
template <typename T> stack<T>* out_stack(stack<T>* s, T* info);
template <typename T> stack<T>* out_stack(stack<T>* s);
template <typename T> void delete_stack(stack<T>*& s);
char* translate(const char* in, char* out);
double result(const char* str, double* data);
int priority(char c);
int check(const char* str);

int main()
{
    char str[32],
         rpn[32] = "";
    double data[26], res;
    bool input = true;

    while (input)
    {
        cout << "Enter formula: ";
        cin.getline(str, sizeof(str));

        switch (check(str))
        {
            case 1: cout << "Missing brackets\n"; break;
            case 2: cout << "Empty brackets\n";   break;
            case 3: cout << "Missing operator\n"; break;
            case 4: cout << "Missing operand\n";  break;

            default: input = false;
        }
    }

    cout << translate(str, rpn) << endl << endl;

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        if (strchr(rpn, i + 97))
        {
            cout << "Enter " << (char)(i + 97) << ": ";
            cin >> data[i];
        }
    }

    if (isinf(res = result(rpn, data))) cout << "Disvision by zero\n";
    else cout << res << endl;

    system("pause");
    return 0;
}

template <typename T> stack<T>* in_stack(stack<T>* s, T info)
{
    stack<T>* t = new stack<T>;

    t->info = info;
    t->next = s;

    return t;
}

template <typename T> stack<T>* out_stack(stack<T>* s, T* info)
{
    stack<T>* t = s;

    *info = s->info;
    s = s->next;

    delete t;
    return s;
}

template <typename T> stack<T>* out_stack(stack<T>* s)
{
    stack<T>* t = s;

    s = s->next;

    delete t;
    return s;
}

template <typename T> void delete_stack(stack<T>*& s)
{
    stack<T>* t;

    while (s)
    {
        t = s;
        s = s->next;
        delete t;
    }
}

char* translate(const char* in, char* out)
{
    stack<char> *s = nullptr;
    char c,
         a[2];

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
                s = out_stack(s);
            break;
            case '*': case '/': case '+': case '-': case '^':
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

double result(const char* str, double* data)
{
    stack<double> *d = nullptr;
    double op1, op2, res;

    for (int i = 0; i < strlen(str); i++)
    {
        if (!priority(str[i])) d = in_stack(d, data[str[i] - 97]);
        else
        {
            d = out_stack(d, &op1);
            d = out_stack(d, &op2);

            switch (str[i])
            {
                case '+': res = op2 + op1;     break;
                case '-': res = op2 - op1;     break;
                case '*': res = op2 * op1;     break;
                case '/':
                    res = op2 / op1;
                    if (op1 == 0)
                    {
                        delete_stack(d);
                        return res;
                    }
                break;
                case '^': res = pow(op2, op1); break;
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
        case '^':           return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default:            return 0;
    }
}

int check(const char* str)
{
    int len     = strlen(str),
        open    = 0,
        closing = 0,
        i       = 0;
    char c, ct;

    while (i < len)
    {
        if      (str[i] == '(') open++;
        else if (str[i] == ')') closing++;

        i++;
    }
    if (open != closing) return 1;

    i = 0;

    while (i < len and ((str[i] < 'a' or str[i] > 'z') and !priority(str[i]) and str[i] != '(')) i++;
    ct = str[i];
    if (priority(ct)) return 3;
    i++;

    while (i < len)
    {
        c = str[i];

        if (c == '(' and str[i + 1] == ')') return 2;

        if ((c < 'a' or c > 'z') and !priority(c) and c != ')' and c != '(')
        {
            i++;
            continue;
        }

        if ((priority(ct) or ct == '(') and priority(c)) return 4;
        if (!priority(ct) and ct != '(' and !priority(c) and c != '(' and c != ')') return 3;

        ct = c;

        i++;
    }

    if (priority(ct)) return 3;


    return 0;
}