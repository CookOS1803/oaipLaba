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
char* delete_whitespaces(const char* in, char* out);
char* translate(const char* in, char* out);
double result(const char* str, double* data);
int priority(char c);
int check(const char* str);

enum ERRORS {SUCCESS, MISSING_BRACKETS, EMPTY_BRACKETS, MISSING_OPERAND, WRONG_SYMBOL};

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
        delete_whitespaces(str, str);

        switch (check(str))
        {
            case MISSING_BRACKETS: cout << "Missing brackets\n"; break;
            case EMPTY_BRACKETS:   cout << "Empty brackets\n";   break;
            case MISSING_OPERAND:  cout << "Missing operand\n";  break;
            case WRONG_SYMBOL:     cout << "Wrong symbol\n";     break;

            case SUCCESS: input = false;
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

char* delete_whitespaces(const char* in, char* out)
{
    int k = 0;
    for (int i = 0; i < strlen(in); i++)
    {
        if (in[i] != ' ') out[k++] = in[i];
    }
    out[k] = '\0';

    return out;
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
            if (i != 0 and ((in[i - 1] >= 'a' and in[i - 1] <= 'z') or in[i - 1] == ')')) s = in_stack(s, '*');
            a[0] = c;
            strcat(out, a);
        }
        else switch (c)
        {
            case '(':
                if (i != 0 and ((in[i - 1] >= 'a' and in[i - 1] <= 'z') or in[i - 1] == ')')) s = in_stack(s, '*');
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
    int len      = strlen(str),
        brackets = 0;
    char c1, c2;

    if (priority(str[0])) return MISSING_OPERAND;

    for (int i = 0; i < len; i++)
    {
        c1 = str[i];
        if (!priority(c1) and c1 != '(' and c1 != ')' and (c1 < 'a' or c1 > 'z')) return WRONG_SYMBOL;
        c2 = str[i + 1];

        if (c1 == '(')
        {
            if (c2 == ')') return EMPTY_BRACKETS;
            brackets++;
        }
        else if (c1 == ')') brackets--;
        else if (priority(c1) and priority(c2)) return MISSING_OPERAND;
    }

    if (priority(str[len - 1])) return MISSING_OPERAND;
    
    if (brackets != 0) return MISSING_BRACKETS;

    return SUCCESS;
}
