#include <iostream>

using namespace std;

struct record
{
    int key;
    char name[16];
};

struct tree
{
    record info;
    tree *left  = nullptr,
         *right = nullptr;
};

bool add_tree(tree*& root, record rec);
void view_tree(tree* p, int level);
tree* find_info(tree* root, int choice);
bool delete_info(tree*& root, int key);
void delete_tree(tree*& root);
void create_balanced(tree*& p, int n, int k, record* a);
void tree_to_array(record* a, int& i, tree* p);
void show_preorder(tree* p);
void show_inorder(tree* p);
void show_postorder(tree* p);
tree* solve(tree* root, int n);
double sum(tree* p);
tree* closest(tree* p, double d);

int main()
{
    tree *root = nullptr,
         *temp = nullptr;
    record t, *a;
    bool exit = false;
    int choice, n;
    
    while (!exit)
    {
        cout << "1. Create\n2. Add\n3. Balance\n4. Find\n5. Show tree\n6. Delete info\n7. Delete tree\n8. Solve Task\n9. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (root) cout << "Clear memory first\n\n";
                else
                {
                    cout << "Enter amount: ";
                    cin >> n;
                    if (n < 1) break;

                    for (int i = 0; i < n; i++)
                    {
                        cout << "Enter " << i + 1 << " key: ";
                        cin >> t.key;
                        getc(stdin);

                        cout << "Enter " << i + 1 << " name: ";
                        cin.getline(t.name, sizeof(t.name));

                        if (!add_tree(root, t))
                        {
                            cout << "A record with such key already exists\n\n";
                            i--;
                        }
                    }
                }
            break;
            case 2:
                if (!root) cout << "Create tree first\n\n";
                else
                {
                    cout << "Enter key: ";
                    cin >> t.key;
                    getc(stdin);

                    cout << "Enter name: ";
                    cin.getline(t.name, sizeof(t.name));

                    add_tree(root, t);
                    n++;
                }
            break;
            case 3:
                if (!root) cout << "Create tree first\n\n";
                else
                {
                    a = new record[n];

                    int i = 0;
                    tree_to_array(a, i, root);
                    delete_tree(root);
                    root = nullptr;
                    create_balanced(root, 0, n, a);

                    delete[] a;
                }
            break;
            case 4:
                if (!root) cout << "Create tree first\n\n";
                else
                {
                    cout << "Enter key: ";
                    cin >> choice;

                    temp = find_info(root, choice);

                    if (temp) cout << "Name: " << temp->info.name << endl << endl;
                    else      cout << "There's no such record\n\n";
                }
            break;
            case 5:
                if (!root) cout << "Create tree first\n\n";
                else
                {
                    cout << "1. Pre-order\n2. In-order\n3. Post-order\n";
                    cin >> choice;
                    cout << endl;

                    switch (choice)
                    {
                        default:
                        case 1: show_preorder(root); break;
                        case 2: show_inorder(root);  break;
                        case 3: show_postorder(root); break;
                    }
                    cout << endl;
                }
            break;
            case 6:
                if (!root) cout << "Create tree first\n\n";
                else
                {
                    cout << "Enter key: ";
                    cin >> choice;

                    if (delete_info(root, choice)) n--;
                    else cout << "There's no such record\n\n";
                }
            break;
            case 7:
                delete_tree(root);
                root = nullptr;
            break;
            case 8: cout << solve(root, n)->info.name << endl; break;
            case 9:
                delete_tree(root);
                exit = true;
            break;
        }
    }

    return 0;
}

bool add_tree(tree*& root, record rec)
{
    if (!root)
    {
        root = new tree;
        root->info = rec;
        return true;
    }

    tree *prev = nullptr, *t = root;

    while (t)
    {
        prev = t;
        if (rec.key == t->info.key) return false;
        else
            if (rec.key < t->info.key) t = t->left;
            else                       t = t->right;
    }

    t = new tree;
    t->info = rec;

    if (rec.key < prev->info.key) prev->left = t;
    else                          prev->right = t;

    return true;
}

void view_tree(tree* p, int level)
{
    if (p)
    {
        view_tree(p->right, level + 1);
        for (int i = 0; i < level; i++) cout << "\t";
        cout << p->info.key << endl;
        view_tree(p->left, level + 1);
    }

}


tree* find_info(tree* root, int choice)
{
    while (root and root->info.key != choice)
    {
        if (root->info.key > choice) root = root->left;
        else                         root = root->right;
    }

    return root;
}


bool delete_info(tree*& root, int key)
{
    tree *del = root,
         *pdel = nullptr,
         *r, *pr;

    while (del and del->info.key != key)
    {
        pdel = del;

        if (del->info.key > key) del = del->left;
        else                     del = del->right;
    }

    if (del == nullptr) return false;

    if      (del->right == nullptr) r = del->left;
    else if (del->left == nullptr)  r = del->right;
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

    if      (del == root)                    root = r;
    else if (del->info.key < pdel->info.key) pdel->left = r;
    else                                     pdel->right = r;

    delete del;
    return true;
}

void delete_tree(tree*& p)
{
    if (p)
    {
        delete_tree(p->left);
        delete_tree(p->right);
        delete p;
    }
}

void create_balanced(tree*& p, int n, int k, record* a)
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

void tree_to_array(record* a, int& i, tree* p)
{
    if (!p) return;
        
    tree_to_array(a, i, p->left);
    a[i++] = p->info;
    tree_to_array(a, i, p->right);
}

void show_preorder(tree* p)
{
    if (!p) return;
    
    cout << p->info.key << ": " << p->info.name << endl;
    show_preorder(p->left);
    show_preorder(p->right);
}

void show_inorder(tree* p)
{
    if (!p) return;

    show_inorder(p->left);
    cout << p->info.key << ": " << p->info.name << endl;
    show_inorder(p->right);
}

void show_postorder(tree* p)
{
    if (!p) return;

    show_postorder(p->left);
    show_postorder(p->right);
    cout << p->info.key << ": " << p->info.name << endl;
}

tree* solve(tree* root, int n)
{
    return closest(root, sum(root)/n);
}

double sum(tree* p)
{
    if (!p) return 0;

    return p->info.key + sum(p->left) + sum(p->right);
}

tree* closest(tree* p, double d)
{
    if (d < p->info.key)
    {
        if (!p->left) return p;

        tree* c = closest(p->left, d);
        if (abs(c->info.key - d) > abs(p->info.key - d))
        {
            return p;
        }
        return c;
    }
    else
    {
        if (!p->right) return p;

        tree* c = closest(p->right, d);
        if (abs(c->info.key - d) > abs(p->info.key - d))
        {
            return p;
        }
        return c;
    }
}

//0
//0
//2
//2
//1
//1
//10
//10
//5
//5
//4
//4
//3
//3
//8
//8
//-3
//-3
//-10
//-10
//-1
//-1
//-5
//-5