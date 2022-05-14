// In this lab you will be implementing binary tree traversal, and also the algorithm to deduce the tree given pre-order and in-order traversal
// For these, we will be implementing a tree where each node stores a character
#include<iostream>
using namespace std;

enum TraversalType_e
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

struct Node
{
    // Complete the definition of struct Node
    char data;
    Node* right,*left;
    
    Node(){
        this->data='\0';
        this->right=nullptr;
        this->left=nullptr;
    }
    Node(char c){
        this->data=c;
        this->right=nullptr;
        this->left=nullptr;
    }


    // Functions external, left, below, right are the same as what is defined in the lecture video under generic binary tree traversal
    void external(TraversalType_e tt)
    {   //if the node is a leaf or an external node then simply print the data
        cout << this->data << " ";
    }
    void left1(TraversalType_e tt){
        // if the traversal type is PRE_ORDER
        // then we output the data of the given node
        if (tt==PRE_ORDER){
            cout<<this->data<<" ";
            return;
        }
        //and in other cases we don't do anything
        else if (tt==POST_ORDER){
            return;
        }
        else
        {
            return;
        }    
    }

    void below(TraversalType_e tt)
    {   // if the traversal type is IN_ORDER
        // then we output the data of the given node
        // and we simply return in other cases
        if (tt == PRE_ORDER)
        {
            return;
        }
        else if (tt == POST_ORDER)
        {
            return;
        }
        else
        {
            cout << this->data << " ";
        }
    }

    void right1(TraversalType_e tt)
    {   // if the traversal type is POST_ORDER
        // then we output the data of the given node
        // and we simply return in other cases
        if (tt == PRE_ORDER)
        {
            return;
        }
        else if (tt == POST_ORDER)
        {
            cout << this->data << " ";
        }
        else
        {
            return;
        }
    }
};



class Tree
{
private:
    struct Node *root;

public:
    Tree(); // Default constructor to construct empty tree

    // Notes for your learning
    // Beware of memory leaks: ideally the tree should also have a suitable destructor
    // But you will not be implementing a destructor here
    // Java is a better programming language than C++ in this regard, as you do not have to bother about memory leaks; Java has a dynamic garbage collector

    Tree(char *pre_order, char *in_order, int N)
    {
        root = deduce_tree(pre_order, in_order, N);
    }

    // This will deduce the binary tree given the pre_order and in_order traversals
    // The first N characters of each string pre_order and in_order are relevant (this will be convenient for a recursive call)
    // You are to return NULL if there is no tree possible with the given pre and in order traversals
    struct Node *deduce_tree(char *pre_order, char *in_order, int N);

    // Traverse the tree as per the given traversal type; this function must be recursive
    void traverse(TraversalType_e tt, struct Node* r);

    // function returns the node of 
    struct Node* get_root();
};

// Implement the above in TreeTraversal.cpp
// Also include the main() function in TreeTraversal.cpp
// In the main function, you can read two strings; you can assume that they each have unique characters, but check that their lengths are the same
// The first string will represent the pre-order traversal of the tree and the second will represent the in-order traversal
// You have to construct the tree using the suitable non-default constructor
// Then print its post-order traversal as a string
// Beware of null termination before printing strings!
