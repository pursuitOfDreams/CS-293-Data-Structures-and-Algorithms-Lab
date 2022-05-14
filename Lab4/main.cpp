#include <iostream>
#include <string>
#include "BST.cpp"
#include <time.h>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
    BST *T = new BST();
    ifstream f;
    f.open("D:/VS Workspace/CS293/Lab4/random_word.txt");

    int N;
    int num;
    bool b;
    f >> N;
    f >> N;
    char s[6];
    f >> s;
    string y;
    y.append(s);
    struct Node n(y);
    b = T->insert(n);
    cout << T->search(s)->data << endl;
    cout << T->search(s)->height << endl;
    f >> s;
    y = "";
    y.append(s);
    n.data = y;
    b = T->insert(n);
    cout << T->search(s)->data << endl;
    cout << T->search(s)->height << endl;
    char a[6];
    f >> a;
    y = "";
    y.append(a);
    cout << s << endl;
    n.data = y;
    b = T->insert(n);
    cout << T->search(s)->data << endl;
    cout << T->search(s)->height << endl;
    cout << "root height " << T->get_root()->height << endl;
    cout << T->predecessor(T->search(s))->data << endl;
    T->traverse(POST_ORDER, T->get_root());
    cout << endl;
    cout << T->max()->data << endl;
}

