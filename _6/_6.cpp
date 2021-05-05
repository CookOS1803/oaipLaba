#include <iostream>

using namespace std;

struct tree
{
    int info;
    tree *left  = nullptr,
         *right = nullptr;
};

void add_tree(tree* root, int key);
void view_tree(tree* root, int level);

int main()
{
    tree* root = new tree;
    root->info = 2;

    add_tree(root, 3);
    add_tree(root, 5);
    add_tree(root, 7);
    add_tree(root, -1);
    add_tree(root, 6);
    add_tree(root, 1);
    add_tree(root, 0);
    add_tree(root, -4);
    add_tree(root, -3);
    add_tree(root, -8);
    add_tree(root, -10);
    add_tree(root, -5);
    add_tree(root, -7);
    add_tree(root, 4);
    
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

void view_tree(tree* root, int level)
{
    if (root)
    {
        view_tree(root->right, level + 1);
        for (int i = 0; i < level; i++) cout << "\t";
        cout << root->info << endl;
        view_tree(root->left, level + 1);
    }

}