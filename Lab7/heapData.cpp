#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class heap
{
private:
    int arr[2000000];
    int size = 0;

public:
    heap(){};
    int n_swap = 0;
    bool insert(int n);
    int min();
    void heapify_down(int i);
    void heapify_up(int i);
    bool delete_min();
    int parent_index(int current_index);
    int left_child(int curr_index);
    int right_child(int curr_index);
};

int heap::parent_index(int current_index)
{
    return (current_index - 1) / 2;
}

int heap::left_child(int curr_index)
{
    return 2 * curr_index + 1;
}

int heap::right_child(int curr_index)
{
    return 2 * curr_index + 2;
}

void heap::heapify_down(int i)
{
    int smallest = i;
    int left = left_child(i);
    int right = right_child(i);
    if (left < size)
    {
        if (arr[left] < arr[smallest])
        {
            smallest = left;
        }
    }

    if (right < size)
    {
        if (arr[right] < arr[smallest])
        {
            smallest = right;
        }
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        n_swap++;
        heapify_down(smallest);
    }
}

void heap::heapify_up(int i)
{
    int largest = i;
    int p = (i - 1) / 2;

    if (p >= 0)
    {
        if (arr[p] > arr[largest])
        {
            largest = p;
        }
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        n_swap++;
        heapify_up(largest);
    }
}

bool heap::insert(int n)
{
    if (size == 2000000)
    {
        return false;
    }
    else
    {
        size++;
        arr[size - 1] = n;
        heapify_up(size - 1);
        return true;
    }
}

int heap::min()
{
    if (size == 0)
    {
        return -1;
    }
    else
    {
        return arr[0];
    }
}

bool heap::delete_min()
{
    if (size == 0)
    {
        return false;
    }
    swap(arr[0], arr[size - 1]);
    size--;
    heapify_down(0);
    return true;
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    heap *h=new heap();
    bool b;
    ifstream file("D:\\VS Workspace\\CS293\\Lab7\\input.txt");
    try{
        if (file.is_open())
        {
            string number;
            while (file >> number)
            {
                int n=stoi(number);
                b = h->insert(n);
            }
            file.close();
            cout<<"Min is :"<<h->min()<<endl;
            // file.open("D:\\VS Workspace\\CS293\\Lab7\\input.txt");
            // while (file >> number)
            // {
            //     int n=stoi(number);
            //     b = h->insert(n);
               
            // }
            // heap * y=new heap();

            // cout<<"Min is :"<<h->min()<<endl;
        }
        else
        {
            throw(-1);
        }
    }
    catch(int n){
        cout<<"File couldn't be opened\n";
    }
}