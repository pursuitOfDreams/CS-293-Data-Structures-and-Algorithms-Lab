#include"BST.h"
#include<iostream>
#include<cstring>
#include<string>
// #include<bits/stdc++.h>

using namespace std;
int height(struct Node* x){
    if (x==NULL){
        return 0;
    }
    else{
        return x->height;
    }
}

int max1(int a,int b){
    if (a>b){
        return a;
    }
    return b;
}

BST::BST(){
    root=new Node();
}

BST::BST(string d){
    root=new Node(d);
}

struct Node* BST::min(){
    struct Node* temp=root;

    if (root==nullptr){
        return nullptr;
    }

    while(temp->left!=nullptr){
        temp=temp->left;
    }
    return temp;
}

struct Node* BST::max(){
    struct Node* temp=root;

    if (root==nullptr){
        return nullptr;
    }

    while(temp->right!=nullptr){
        temp=temp->right;
    }

    return temp;
}

struct Node* BST::search(char* s){
    struct Node* temp=root;

    if (root->data==""){
        return nullptr;
    }

    while(temp!=nullptr){
        if (strcmp(s, temp->data.c_str()) == 0)
        {
            return temp;
        }
        else if (strcmp(s, temp->data.c_str()) == 1)
        {
            temp=temp->right;
        }
        else {
            temp=temp->left;
        }
    }
    return nullptr;
}

bool BST::insert(struct Node n){
    
    bool t;

    if (root->data==""){
        root->data=n.data;
        t=true;
    }

    struct Node* temp=root;
    while(temp!=nullptr){
        if (strcmp(n.data.c_str(),root->data.c_str())==0){
            return false;
        }
        else if (strcmp(n.data.c_str(),root->data.c_str())==1){
            if (temp->right==nullptr){
                temp->right=new Node(n.data);
                temp->right->parent=temp;
                t=true;
                break;
            }
            else {
                temp=temp->right;
            }
        }
        else{
            if (temp->left==nullptr){
                temp->left=new Node(n.data);
                temp->left->parent=temp;
                t=true;
                break;
            }
            else{
                temp=temp->left;
            }
        }
    }
    while(temp!=nullptr){
        temp->height=1+std::max(height(temp->right),height(temp->left));
        temp=temp->parent;
    }

    return t;
}

bool BST::remove( char* s){
    struct Node* r=search(s);
    bool t;

    if (r==nullptr){
        t=false;
    }
    else{
        struct Node *y = new Node();
        struct Node *x = new Node();
        if (r->left == nullptr || r->right == nullptr)
        {
            y=r;
        }
        else
        {
            y=successor(r);
        }

        if (y->left != nullptr)
        {
            x=y->left;
        }
        else
        {
            x=y->right;
        }

        if (x != nullptr)
        {
            x->parent = y->parent;
        }

        if (y->parent == nullptr)
        {
            this->root=x;
        }
        else {
            if (y==y->parent->left){
                y->parent->left=x;
            }
            else{
                y->parent->right=x;
            }
        }
        delete r;
        t=true;
    }
   return t;

}

struct Node* BST::successor(struct Node*n){
    if (n->right!=nullptr){
        struct Node* temp=n->right;
        while(temp->left!=nullptr){
            temp=temp->left;
        }
        return temp;
    }

    struct Node* p=n->parent;
    while(p!=nullptr&&n==p->right){
        n=p;
        p=p->parent;
    }
    return p;
}

struct Node* BST::predecessor(struct Node* n){
    if (n->left!=nullptr){
        struct Node* temp=n->left;
        while(temp->right!=nullptr){
            temp=temp->right;
        }
        return temp;
    }
    
    struct Node* p=n->parent;
    while(p!=nullptr&&n==p->right){
        n=p;
        p=p->parent;
    }
    return p;
}

void BST::traverse(TraversalType_e tt,struct Node* r){
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
