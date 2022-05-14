#include "DynamicDequeue.cpp"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){
    DynamicDequeue *d=new DynamicDequeue();
    clock_t t;
    t = clock();
    vector<double> time_taken;
    for(int i=0;i<100000;++i){
        double x=i;
        d->insertRear(x);
        if (i%2000==0&&i>0){
            double t2 = 1000 * ((double)(clock() - t)) / CLOCKS_PER_SEC;
            time_taken.push_back(t2);
        }
    }
    // double time_taken = 1000*((double)(clock() - t)) / CLOCKS_PER_SEC;
    std::ofstream f;
    f.open("D:/VS Workspace/CS293/Exponential.txt");
    for(auto i:time_taken){
        string s=to_string(i);
        f<<s<<endl;
    }
    f.close();
    // std::cout<< time_taken;
    double a=0;
    double *x=&a;
    cout<<endl;
    d->insertRear(20);
    d->insertRear(30);
    d->insertRear(40);
    d->insertRear(20);
    d->insertRear(30);
    d->insertRear(40);
    d->insertRear(20);
    d->insertRear(30);
    d->insertRear(40);
    d->insertRear(20);
    d->insertRear(30);
    d->insertRear(40);
    if (d->front(x)){
        cout<<*x;
        cout<<endl;
    }
    if (d->rear(x)){
        cout<<*x<<endl;
    }
    cout<<d->size()<<endl;
    d->insertRear(40);
    d->insertRear(20);
    d->insertRear(30);
    d->insertRear(40);
    d->insertFront(24);
    if (d->front(x))
    {
        cout << *x;
        cout << endl;
    }
    if (d->removeFront(x)){
        cout<<*x<<endl;
    }
    if (d->removeRear(x))
    {
        cout << *x << endl;
    }

    cout<<d->size()<<endl;
}

