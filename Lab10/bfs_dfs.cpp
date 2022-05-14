#include<bits/stdc++.h>

using namespace std;

enum TraversalType
{
    BFS,
    DFS
};

void traversal(TraversalType t, vector<int> adj[], int N){
    // using deque to manage both BFS and DFS operations
    deque<int> d;
    bool visited[N];
    // boolean array to check if the array was visited or not

    for(int i=0;i<N;++i){
        visited[i]=false;
    }

    d.push_back(0);
    visited[0]=true;

    while(!d.empty()){

        // to store the front element in the queue
        int c;

        if (t==BFS){
            c=d.front();
            d.pop_front();
        }
        else{
            c=d.back();
            d.pop_back();
        }
        cout<<c<<"->";

        vector<int> li=adj[c];
        for(int i=0;i<li.size();i++){
            if (!visited[li[i]]){
                visited[li[i]]=true;
                d.push_back(li[i]);
            }
        }
    }  
}


bool is_bipartite(int vertex,vector<int> adj_list[],vector<bool> &visited, vector<int> &color){
    for(auto i:adj_list[vertex]){
        if (!visited[i]){
            visited[i]=true;
            color[i]=!color[vertex];
            if (!is_bipartite(i,adj_list,visited,color)){
                return false;
            }
        }
        else if (color[i]==color[vertex]){
            return false;
        }
    }
    return true;
}

int main(){
    srand(time(0));
    int i=0;
    int N;
    cin>>N;

    int edgeList[2*N][2];

    while(i<2*N){
        edgeList[i][0]=rand()%N;
        edgeList[i][1]=rand()%N;

        if (edgeList[i][0]==edgeList[i][1]){
            continue;
        }
        else{
            for(int j=0;j<i;j++){
                if ((edgeList[i][0]==edgeList[j][1]&&edgeList[i][1]==edgeList[j][0])||(edgeList[i][1]==edgeList[j][1]&&edgeList[i][0]==edgeList[j][0])){
                    i--;
                }
            }
        }
        i++;
    }

    vector<int> adj_list[N];
    
    for(int j=0;j<2*N;j++){
        adj_list[edgeList[j][0]].push_back(edgeList[j][1]);
        adj_list[edgeList[j][1]].push_back(edgeList[j][0]);
    }

    cout<<"EdgeList"<<endl;

    for(int j=0;j<2*N;++j){
        cout<<"("<<edgeList[j][0]<<","<<edgeList[j][1]<<")"<<endl;
    }

    vector<bool> visited;
    vector<int> color;
    for(int j=0;j<N;j++){
        visited.push_back(false);
    }

    visited[0]=true;
    color.push_back(1);
    cout<<is_bipartite(0,adj_list,visited,color);

    traversal(BFS,adj_list,N);
    cout<<endl;
    traversal(DFS,adj_list,N);

}


