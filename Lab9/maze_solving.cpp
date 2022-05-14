#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<iterator>
#include<bits/stdc++.h>

using namespace std;


class cell{
    private:
        int vertex;
    public:
        int pos[2];
        int adj_hor[2];
        int adj_ver[2];
        cell(){
            this->vertex=-1;
        }
        cell(int V){
            this->vertex=V;
        }

        int getVertex(){
            return this->vertex;
        }
};

class Graph{
    private:
        cell **cells;
    public:
        bool **visited;
        int rows;
        int cols;
        Graph(int hor[][4],int ver[][3],int rows,int cols){
            cells =new cell*[rows];
            visited =new bool*[rows];
            this->rows=rows;
            this->cols=cols;
            for(int i=0;i<rows;++i){
                cells[i]=new cell[cols];
                visited[i]=new bool[cols];
            }
           for(int i=0;i<rows;i++){
               for(int j=0;j<cols;++j){
                    visited[i][j]=false;

                    cells[i][j]=cell((i)*cols+j);
                    
                    cells[i][j].pos[0]=i;
                    cells[i][j].pos[1]=j;

                    cells[i][j].adj_hor[0]=hor[i][j];
                    cells[i][j].adj_hor[1]=hor[i][j+1];
                    cells[i][j].adj_ver[0]=ver[i][j];
                    cells[i][j].adj_ver[1]=ver[i+1][j];
               }
           }
        }

        list<vector<int>> adj_cells(int i,int j){
            list<vector<int>> ans;
            if (cells[i][j].adj_hor[1]==0){
                vector<int> p1;
                if (j<cols-1){
                    p1.push_back(i);
                    p1.push_back(j+1);
                    ans.push_back(p1);
                }
            }

             if (cells[i][j].adj_ver[1]==0){
                vector<int> p3;
                if (i<rows-1){
                    p3.push_back(i+1);
                    p3.push_back(j);
                    ans.push_back(p3);
                }
            }

            if (cells[i][j].adj_hor[0]==0){
                vector<int> p2;
                if (j>0){
                    p2.push_back(i);
                    p2.push_back(j-1);
                    ans.push_back(p2);
                }
            }

           
            if (cells[i][j].adj_ver[0]==0){
                vector<int> p4;
                if (i>0){
                    p4.push_back(i-1);
                    p4.push_back(j);
                    ans.push_back(p4);
                }
            }

            return ans;
        }

        void find_path(){
            int i=0;
            int j=0;

            // map<cell,cell> parent;
            vector<cell> queue;

            int p[rows*cols];
            queue.push_back(cells[i][j]);
            visited[i][j]=true;

            while(!queue.empty()){
                cell c=queue.front();
                cout<<"("<<c.pos[0]<<","<<c.pos[1]<<") -> ";
                queue.erase(queue.begin());

                list<vector<int>> adj=adj_cells(c.pos[0],c.pos[1]);

                bool b=false;
                for(auto k: adj){
                    if (!visited[k[0]][k[1]]){
                        visited[k[0]][k[1]]=true;
                        // parent.insert(pair<cell,cell>(cells[k[0]][k[1]],c));
                        p[cells[k[0]][k[1]].getVertex()]=c.getVertex();
                        // if (k[0]==rows-1&&k[1]==cols-1){
                        //     b=true;
                        //     break;
                        // }
                        queue.push_back(cells[k[0]][k[1]]);
                    }
                }

                if (b){
                    break;
                }

            }
            cout<<endl;
            i=rows;
            j=cols;
            stack<vector<int>> shortest_path;
            while(true){
                // const cell ci=cells[i][j];
                // auto it=parent.find(ci);

                // auto c=it->second;
                // cout<<"("<<c.pos[0]<<","<<c.pos[1]<<") -> ";
                
                vector<int> v;
                int n=p[i*j-1];
                i=n/cols;
                j=n%cols;
                v.push_back(i);
                v.push_back(j);
                shortest_path.push(v);
                if (n==0){
                    break;
                }
            }

            // printing the shortest path
            while(!shortest_path.empty()){
                auto c=shortest_path.top();
                shortest_path.pop();
                cout<<"("<<c[0]<<","<<c[1]<<") -> ";
            }
        }

};

int main(){

// int rows=3,cols=4;

int horizontal[3][4];
int vertical[4][3];

// for(int i=0;i<rows;i++){
//     for(int j=0;j<cols+1;++j){
//         cin>>horizontal[i][j];
//     }
// }
// for(int i=0;i<rows+1;i++){
//     for(int j=0;j<cols;++j){
//         cin>>vertical[i][j];
//     }
// }

// int horizontal[rows][cols+1];
// int vertical[rows+1][cols];

for(int i=0;i<3;i++){
    for(int j=0;j<3+1;++j){
        cin>>horizontal[i][j];
    }
}
for(int i=0;i<3+1;i++){
    for(int j=0;j<3;++j){
        cin>>vertical[i][j];
    }
}


Graph g=Graph(horizontal,vertical,3,3);
g.find_path();

}