#include <iostream>

using namespace std;

struct tree
{
    int info;
    tree *left  = nullptr,
         *right = nullptr;
};

void add_tree(tree* root, int key);
void view_tree(tree* p, int level);
void delete_info(tree*& root, int key);
void delete_tree(tree* root);
void create_balanced(tree*& p, int n, int k, int* a);

int main()
{
    tree* root = nullptr;
    int a[] = {3, 5, 7, -1, 6, 1, 0, -4, -3, -8, -10, -5, -7, 4};
    create_balanced(root, 0, 14, a);
    
    view_tree(root, 0);

    system("pause");
    return 0;
}

void add_tree(tree* root, int key)
{
    tree *prev = nullptr, *t = root;
    bool find = true;

    while (t and find)
    {
        prev = t;
        if (key == t->info) find = false;
        else
            if (key < t->info) t = t->left;
            else               t = t->right;
    }

    if (find)
    {
        t = new tree;
        t->info = key;

        if (key < prev->info) prev->left = t;
        else               prev->right = t;
    }
}

void view_tree(tree* p, int level)
{
    if (p)
    {
        view_tree(p->right, level + 1);
        for (int i = 0; i < level; i++) cout << "\t";
        cout << p->info << endl;
        view_tree(p->left, level + 1);
    }

}

void delete_info(tree*& root, int key)
{
    tree *del = root,
         *pdel = nullptr,
         *r, *pr;

    while (del and del->info != key)
    {
        pdel = del;

        if (del->info > key) del = del->left;
        else                 del = del->right;
    }

    if (del == nullptr) return;

    if      (del->right == nullptr) r = del->left;
    else if (del->left == nullptr) r = del->right;
    else
    {
        pr = del;
        r = del->left;

        while (r->right)
        {
            pr = r;
            r = r->right;
        }

        r->right = del->right;

        if (pr != del)
        {
            pr->right = r->left;
            r->left = pr;
        }
    }

    if      (del == root)            root = r;
    else if (del->info < pdel->info) pdel->left = r;
    else                             pdel->right = r;

    delete del;
}

void delete_tree(tree* root)
{
    if (root)
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

void create_balanced(tree*& p, int n, int k, int* a)
{
    if (n == k)
    {
        p = nullptr;
        return;
    }
    else
    {
        int m = (n + k)/2;

        p = new tree;
        p->info = a[m];

        create_balanced(p->left, n, m, a);
        create_balanced(p->right, m + 1, k, a);
    }
}