#include <bits/stdc++.h>
using namespace std;

class student {
public:
    int roll;
    int marks;
    student()
    {
        roll = 0;
        marks = 0;
    }
};

void sort_students(vector<student> arr)
{
    //comparator lambda function
    auto comp = [](student a, student b) {
        //comparison logic
        if (a.marks > b.marks)
            return false;
        else if (a.marks < b.marks)
            return true;
        else { // when marks are same
            if (a.roll < b.roll) {
                return false;
            }
            else
                return true;
        }
    };

    priority_queue<student, vector<student>, decltype(comp)> pq(comp);

    for (auto& ij : arr) {
        pq.push(ij);
    }
    //printing the sorted list
    cout << "roll marks\n";
    while (!pq.empty()) {
        cout << pq.top().roll << " " << pq.top().marks << endl;
        pq.pop();
    }
}

int main()
{

    int n;
    
    cout << "Enter number of students\n";
    cin >> n;
    
    vector<student> arr(n);
    cout << "Enter roll and marks for each student\n";
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i].roll = x;
        arr[i].marks = y;
    }
    
    cout << "sorting students according to marks and roll no: \n";
    
    sort_students(arr);
    
    return 0;
}
