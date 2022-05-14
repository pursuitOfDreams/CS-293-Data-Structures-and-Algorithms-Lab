#include<iostream>
#include "Dictionary.h"


using namespace std;

Dictionary::Dictionary(){
    N=0;
    A=new Node[N];
    for(int i=0;i<ARRAY_SIZE;++i){
        A[i]=Entry();
    }
}

int Dictionary::hashValue(char *key){
    //This is to calculate the hashValue
    //polynomial accumulation
    int C;
    size_t key_size=strlen(key);
    long double pol_acc=0;
    for(int i=key_size-1;i>=0;--i){
        C=key[i];
        pol_acc=pol_acc*X+C;
        pol_acc=pol_acc*KNUTH_CONSTANT;
        long int j=(long int)pol_acc;
        pol_acc=pol_acc-j;
    }
    //fibonacci compression map
    return floor(ARRAY_SIZE*(pol_acc));
}

int Dictionary::findFreeIndex(char *key){
    if (N==ARRAY_SIZE){
        return -1;
    }
    int hash_value=this->hashValue(key);
    while(A[hash_value].state!=0||A[hash_value].state!=-1){
        hash_value=(hash_value+1)%ARRAY_SIZE;
    }
    

}