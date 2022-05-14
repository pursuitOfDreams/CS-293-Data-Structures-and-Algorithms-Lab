#include"TreeTraversal.cpp"
#include<iostream>
#include<string>

using namespace std;

int main(){
char pre[6]="42513";
char in[6]="15423";
/* 
Tree:
            1
          /    \
         2      3
       /   \       
      4     5

pre_order:   1->2->4->5->3
post_order:  4->5->2->3->1
in_order:    4->2->5->1->3

*/

Tree *t=new Tree(pre,in,5);
cout<<"pre ";
//finding the pre_order traversal
t->traverse(PRE_ORDER,t->get_root());
cout<<endl<<"in ";
// finding the IN_ORDER traversal
t->traverse(IN_ORDER,t->get_root());
cout << endl<<"post ";
// finding the POST_ORDER traversal
t->traverse(POST_ORDER,t->get_root());
}