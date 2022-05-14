#include<iostream>
#include "Dictionary.h"
#include<math.h>
#include<string>
#include<cstring>

using namespace std;

#define X 37
#define KNUTH_CONSTANT (sqrt(5)-1)/2

Dictionary::Dictionary()
{   //initialised the Entry Array
    N=0;
    A=new Entry[ARRAY_SIZE];
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
        pol_acc=pol_acc*X+C;//a_0+(...(a_n-1+x(a_n)))
        pol_acc=pol_acc*KNUTH_CONSTANT;
        long int j=(long int)pol_acc;
        pol_acc=pol_acc-j;
    }
    //fibonacci compression map
    return floor(ARRAY_SIZE*(pol_acc));
}

int Dictionary::findFreeIndex(char *key){
    //finds the free index through Linear probing
    int hash_value=hashValue(key);
    for(int i=0;i<ARRAY_SIZE;++i){
        cout<<"state "<<A[hash_value].state<<endl;
        if (A[hash_value].state==0||A[hash_value].state==-1){
            return hash_value;
        }
        else{
            hash_value=(hash_value+1)%ARRAY_SIZE;
        }
    }
    return -1;// returns -1 when
}

struct Entry* Dictionary::get(char* key){
    // This is to find the entry inside the array
    int hash_value=hashValue(key);
    for(int i=0;i<ARRAY_SIZE;++i){
        if (A[hash_value].state == 0)
            break;
        
        if (A[hash_value].state==1){
            if (strcmp(key,A[hash_value].key)==0)
            {
                return &A[hash_value];
            }
            hash_value = (hash_value + 1) % ARRAY_SIZE;
        }
        if (A[hash_value].state==-1) {hash_value=(hash_value+1)%ARRAY_SIZE;}
    }
    struct Entry* e=new Entry();
    return e;
}

bool Dictionary::put(struct Entry e){
    
    char *a=e.key;
    cout<<"Hash Value: "<<hashValue(a)<<endl;
    if (get(a)->key!=NULL){
        get(a)->freq++;
        cout<<"Frequency"<<get(a)->freq<<endl;
        return true;
    }
    int freeIndex = findFreeIndex(e.key);
    if (freeIndex==-1){
        return false;
    }
    else{
        cout<<"Stored at Index "<<freeIndex<<endl;
        char *b=e.key;
        A[freeIndex].key=b;
        A[freeIndex].freq=1;
        A[freeIndex].state=1;
        N++;
        return true;
    }
}

bool Dictionary::remove(char *key){
    if (N==0) {
        return false;
    }
    int hash_value=hashValue(key);
    for(int i=0;i<ARRAY_SIZE;++i){
        if (A[hash_value].state==1){
            if (strcmp(A[hash_value].key,key)==0){
                A[hash_value].state=-1;
                A[hash_value].key=NULL;
                A[hash_value].freq=0;
                N--;
                return true;
            }
            hash_value=(hash_value+1)%ARRAY_SIZE;
        }
        else if (A[hash_value].state==-1){
            hash_value=(hash_value+1)%ARRAY_SIZE;
        }
        else{
            break;
        }
    }
    return false;
}
