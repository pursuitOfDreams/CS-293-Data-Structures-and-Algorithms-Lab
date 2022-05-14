#include"TreeTraversal.h"
#include<iostream>

using namespace std;

//helper functions

//helps to search for an element in an array
int search_index(char c[],int size,char x){
    // finds the character x in array c and returns its index
    for(int i=0;i<size;i++){
        if (c[i]==x){
            return i;
        }
    }
    return -1;
}


Tree::Tree(){
    //empty tree declared
    this->root=new Node();
}

struct Node *Tree::deduce_tree(char *pre_order, char *in_order, int N){
    // helps to deduce the binary tree from the given pre_order and post order traversal
    if (N==0){
        // if the number of elements in the char array inorder is 0
        return NULL;
    }
    // used to find the index of the first element in pre_order
    int root_index=search_index(in_order,N,pre_order[0]);

    //if the preorder and inorder arrays are different
    //then no such tree would exist
    if (root_index==-1){
        return NULL;
    }
    // defined a root node for the tree
    struct Node* r=new Node(pre_order[0]);

    //finding the left sub tree of the given root node
    r->left=deduce_tree(pre_order+1,in_order,root_index);

    //finding right sub tree of the given root node
    r->right=deduce_tree(pre_order+1+root_index,in_order+root_index+1, N-root_index-1);

    return r;
}

void Tree::traverse(TraversalType_e tt,struct Node* r){
    //traverses the given tree in the order specified
    if (r!=NULL){
        if(r->right == nullptr && r->left == nullptr) {
            r->external(tt);
        }
        else{
            r->left1(tt);

            traverse(tt,r->left);
            
            r->below(tt);
        
            traverse(tt, r->right);
        
            r->right1(tt);
        }
    }
    return;
}

struct Node* Tree::get_root()
{ // to get the root node of the treee
    return this->root;
}