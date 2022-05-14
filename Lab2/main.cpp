#include "Dictionary.cpp"
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
    Dictionary d;
    char c[32]="hello";
    bool f;
    struct Entry y=Entry(c);
    f= d.put(y);
    f = d.put(y);
    f = d.put(y);
    struct Entry *r=d.get(c);
    cout<<r->freq<<endl;
    
    char k[32]="help";
    struct Entry v=Entry(k);
    f = d.put(v);
    f = d.put(v);
    struct Entry *z=d.get(k);
    cout<<z->freq<<endl;

    f=d.remove(k);
    struct Entry *s=d.get(k);
    cout<<s->freq<<endl;


}