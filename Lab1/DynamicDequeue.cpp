#include "DynamicDequeue.h"
#include<iostream>

using namespace std;
DynamicDequeue::DynamicDequeue(){
    N=INIT_SIZE;
    A=new double[N];
    f=0;
    r=0;
}
bool DynamicDequeue::isEmpty(){
    if (f==r){
        return true;
    }
    return false;
}
bool DynamicDequeue::isFull(){
    if (f>r&&(N-f+r)==N-1){
        return true;
    }
    else if (r-f==N-1){
        return true;
    }
    else return false;
}

void DynamicDequeue::grow(){

    // double *x = new double[nextSizeLinear()];
    double *x = new double[nextSizeExponential()];

    int a=f;
    for(int i=0;i<N-1;++i){
        a=(a+i)%N;
        x[f+i]=A[a];
    }
    r=f+N-1;
    delete[] A;
    // N=nextSizeLinear();
    N=nextSizeExponential();
    A=new double[N];
    for(int i=f;i<r;++i){
        A[i]=x[i];
    }
    delete[] x;
}
unsigned int DynamicDequeue::size(){
    if (f>r){
        return (N-f+r);
    }
    else{
        return (r-f);
    }
}
void DynamicDequeue::insertFront(double x){
    if (!isFull()){
        if (f==0){
            A[N-1]=x;
            f=N-1;
        }
        else {
            A[f-1]=x;
            f=f-1;
        }
    }
    else {
       grow(); 
       if (f==0){
            A[N-1]=x;
            f=N-1;
        }
        else {
            A[f-1]=x;
            f=f-1;
        }
    }
}
void DynamicDequeue::insertRear(double x){
    if (!isFull()){
        A[r]=x;
        r=(r+1)%N;
    }
    else {
        grow();
        A[r]=x;
        r=(r+1)%N;
    }
}
bool DynamicDequeue::removeFront(double *x){
    if (isEmpty()){
        return false;
    }
    else {
        *x=A[f];
        f=(f+1)%N;
        return true;
    }
}
bool DynamicDequeue::removeRear(double *x){
    if (isEmpty()){
        return false;
    }
    else{
        if (r==0){
          *x=A[N-1];
           r=N-1;  
        }
        else {
            *x=A[r-1];
            r=(r-1);
        }
        return true;
    }
}
bool DynamicDequeue::front(double *x){
    if (isEmpty()){
        return false;
    }
    *x=A[f];
    return true;
}

bool DynamicDequeue::rear(double *x){
    
    if (isEmpty()){
        return false;
    }
    else if (!isEmpty()){
        *x =A[r-1];
        return true;
    }
    
}

// int main(){
//     return 0;
// }
