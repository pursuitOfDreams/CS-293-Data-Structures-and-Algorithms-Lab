#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
#define MARKER "$"
// str.substr(starting_index, end_index)
int lenCommon(string one, string two)
{
    /* Used to find the length of the common substring */
    int m = min(one.length(), two.length());
    int length = 0;
    for (int i = 0; i < m; ++i)
    {
        if (one[i] == two[i])
        {
            length++;
        }
        else
        {
            break;
        }
    }
    return length;
}

class Node
{
    /* class to define the node of the trie tree */
public:
    vector<Node *> children; // container to store the children of the parent node
    int label[3];            // to store 3-tuple integer
    bool isEnding = false;   // to check if a word ends at a node
    bool isRoot = false;     // to check if a node is root or not
    string stored_value;     // used to store the value of the string at the node
    Node(int i, int start, int end, string word)
    {
        this->label[0] = i;
        this->label[1] = start;
        this->label[2] = end;
        this->stored_value = word;
    }
    bool hasChildren()
    {
        return !children.empty();
    }
    void change_labels(int start, int end)
    {
        /* used to change the labels of the node */
        label[1] = start;
        label[2] = end;
    }
    void change_stored_value(string s)
    {
        /* will change the stored value of the node*/
        stored_value = s;
    }
};

class Trie
{
    /* will define the trie tree structure to store the string inside it */
public:
    Node *root;                     // root node which is empty
    Trie();                         // constructor
    int newWord = -1;               // index of the newword that is stored
    bool insert(string word);       // this function will insert strings inside the trie
    int find(string word);          // it is used to return the first occurrence of the longest prefix
    string findPrefix(string word); // it will return the longest prefix common with the given argument word
};

Trie::Trie()
{
    root = new Node(-1, -1, -1, "");
    root->isRoot = true;
}

bool Trie::insert(string word)
{
    if (!root->hasChildren())
    {
        // if the root is itself empty
        root->children.push_back(new Node(++newWord, 0, word.length() - 1, word));
        return true;
    }
    else
    {
        // if the root is not empty
        string s = word;
        int l = -1;
        Node *temp = root;
        while (true)
        {
            // to check if we were able to find a substring inside one of the children
            bool does_children_contain_sub = false;

            // check the children of the parent node
            for (auto i : temp->children)
            {
                int len = lenCommon(i->stored_value, s);
                if (len > 0)
                {
                    // if the string is
                    if (len == i->stored_value.length() && s.length() > len)
                    {
                        temp = i;
                        l += len;
                        s = s.substr(len, s.length() - len);
                        does_children_contain_sub = true;
                        break;
                    }
                    else if (len == i->stored_value.length() && s.length() == len)
                    {
                        does_children_contain_sub = true;
                        i->isEnding = true;
                        return true;
                    }
                    // if the string is a substring of the string in the Node
                    // we will split ex: sub and su
                    else if (len == s.length() && len < i->stored_value.length())
                    {
                        // creating a new child node
                        Node *newNode = new Node(i->label[0], i->label[1] + len, i->label[2], i->stored_value.substr(len, i->stored_value.length() - len));
                        newNode->isEnding = i->isEnding;
                        // because a word inserted ends at that node
                        i->isEnding = true;
                        // copying the children from the parent to the child's container
                        for (auto j : i->children)
                        {
                            newNode->children.push_back(j);
                        }
                        // to delete all the entries of the parents child container
                        i->children.clear();
                        i->stored_value = i->stored_value.substr(0, len);
                        i->label[2] = i->label[1] + len - 1;
                        // pushing the new node to the container of parent
                        i->children.push_back(newNode);
                        return true;
                    }
                    else
                    {
                        // we will split the parent node into two childs
                        // new node which had substring which example (sub and sud)
                        Node *newNode = new Node(i->label[0], i->label[1] + len, i->label[2], i->stored_value.substr(len, i->stored_value.length() - len));
                        newNode->isEnding = i->isEnding;
                        i->isEnding = false;
                        for (auto j : i->children)
                        {
                            newNode->children.push_back(j);
                        }
                        l += len;
                        Node *newNode2 = new Node(++newWord, l, word.length(), s.substr(len, s.length() - len));
                        newNode2->isEnding = true;
                        i->children.clear();
                        i->stored_value = i->stored_value.substr(0, len);
                        i->label[2] = i->label[1] + len - 1;
                        i->children.push_back(newNode);
                        i->children.push_back(newNode2);
                        return true;
                    }
                }
                else
                {
                    continue;
                }
            }
            // if we couldn't find any children with common substring then we will push another node to the parent
            if (!does_children_contain_sub)
            {
                temp->children.push_back(new Node(++newWord, 0, l, s));
                return true;
            }
        }
    }
    return false;
}

int Trie::find(string word)
{
    if (!root->hasChildren())
    {
        return -1;
    }
    else
    {
        Node *temp = root;
        bool end = false;
        string s = word;
        int l = -1;
        bool parent_got_match = false;
        while (!end)
        {
            bool found_a_substring = false;
            for (auto i : temp->children)
            {
                int len = lenCommon(i->stored_value, s);
                // if the match is found
                if (len > 0)
                {   
                    // if the stored value is
                    if (len < i->stored_value.length())
                    {
                        return i->label[0];
                    }
                    else if (len == i->stored_value.length())
                    {
                        parent_got_match = true;
                        temp = i;
                        l += len;
                        s = s.substr(0, len);
                        break;
                    }
                }
            }
            if ((!found_a_substring && parent_got_match) || s.length() == 0)
            {
                return temp->label[0];
            }
            if (!found_a_substring)
            {
                return -1;
            }
        }
    }

    return -1;
}

string Trie::findPrefix(string word)
{
    string ans = "";
    if (!root->hasChildren())
    {
        return "";
    }
    else
    {
        Node *temp = root;
        bool end = false;
        string s = word;

        int l = -1;
        bool parent_got_match = false;
        while (!end)
        {
            bool found_a_substring = false;
            for (auto i : temp->children)
            {
                int len = lenCommon(i->stored_value, s);
                // if the substring was found
                if (len > 0)
                {
                    // if subs su
                    if (len < i->stored_value.length())
                    {
                        l += len;
                        ans += i->stored_value.substr(0, len);
                        return ans;
                    }
                    //
                    else if (len == i->stored_value.length())
                    {
                        parent_got_match = true;
                        temp = i;
                        found_a_substring = true;
                        ans += i->stored_value;
                        l += len;
                        s = s.substr(len, s.length() - len);
                        break;
                    }
                }
            }
            if ((!found_a_substring && parent_got_match) || s.length() == 0)
            {
                return ans;
            }
            else if (!found_a_substring)
            {
                return ans;
            }
        }
    }

    return ans;
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Trie *T = new Trie();
    bool b;
    ifstream file("D:\\VS Workspace\\CS293\\Lab6\\test.txt");
    try{
        if (file.is_open())
    {
        string word;
        while (file >> word)
        {
            b = T->insert(word);
        }
        int t;
        cin >> t;
        while (t--)
        {
            string w;
            cin >> w;
            string prefix = T->findPrefix(w);
            if (prefix == "")
            {
                cout << "Prefix couldn't be found" << endl;
            }
            else
            {
                cout << "Longest prefix found is: " << prefix << endl;
            }
        }
    }
    else
    {
        throw(-1);
    }
    }
    catch(int n){
        cout<<"File couldn't be opened\n";
    }
    
}