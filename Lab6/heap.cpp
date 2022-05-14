#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

void swap(int &a ,int &b){
    int temp=a;
    a=b;
    b=temp;
}

class heap{
private:
    
public:
int arr[2000000];
    int size=0;
    heap(){};
    int n_swap=0;
    bool insert(int n);
    int min();
    void heapify_down(int i);
    void heapify_up(int i);
    bool delete_min();
    int parent_index(int current_index);
    int left_child(int curr_index);
    int right_child(int curr_index);
};


int heap::parent_index(int current_index){
    return (current_index-1)/2;
}


int heap::left_child(int curr_index){
    return 2*curr_index+1;
}


int heap::right_child(int curr_index){
    return 2*curr_index+2;
}


void heap::heapify_down(int i){
    int smallest=i;
    int left=left_child(i);
    int right=right_child(i);
    if (left<size){
        if (arr[left]<arr[smallest]){
            smallest=left;
        }
    }

    if (right<size){
        if (arr[right]<arr[smallest]){
        smallest=right;
        }
    }

    if (smallest!=i){
        swap(arr[i],arr[smallest]);
        n_swap++;
        heapify_down(smallest);
    }
}

void heap::heapify_up(int i){
    int largest=i;
    int p=(i-1)/2;
    
    if (p>=0){
        if (arr[p]>arr[largest]){
            largest=p;
        }
    }

    if (largest!=i){
        swap(arr[largest],arr[i]);
        n_swap++;
        heapify_up(largest);
    }
}


bool heap::insert(int n){
    if (size==2000000){
        return false;
    }
    else{
        size++;
        arr[size-1]=n;
        heapify_up(size-1);
        return true;
    }   
}


int heap::min(){
    if (size==0){
        return -1;
    }
    else{
        return arr[0];
    }
}


bool heap::delete_min(){
    if (size==0){
        return false;
    }
    swap(arr[0],arr[size-1]);
    size--;
    heapify_down(0);
    return true;
}


int main(){
    
    srand(time(0));
    int N=1000;

    while(N!=1000000){
        heap* h=new heap();
        long long int insert_swaps=0;
        long long int delete_swaps=0;
        int inserts=0;
        int deletes=0;
        bool b;
        for(int i=0;i<N;++i){
            int a=rand();
            b=h->insert(a);
            h->n_swap=0;
        }

        for(int i=0;i<N/5;++i){
            int f=rand()%2;
            if (f==1){
                int a=rand();
                b=h->insert(a);
                insert_swaps+=h->n_swap;
                h->n_swap=0;
                inserts++;
            }
            else if (f==0){
                b=h->delete_min();
                delete_swaps+=h->n_swap;
                h->n_swap=0;
                deletes++;
            }
        }
        float avg_inserts=0;
        if (inserts!=0){
            avg_inserts=insert_swaps/inserts;
        }

        float avg_deletes=0;
        if (deletes!=0){
            avg_deletes=delete_swaps/deletes;
        }
        
    
        cout<<"for N="<<N<<endl;
        cout<<"Avg Number of swaps in insert operations were: "<<avg_inserts<<endl;
        cout<<"Avg Number of swaps in delete operations were: "<<avg_deletes<<endl<<endl;
        N*=10;
    }
}