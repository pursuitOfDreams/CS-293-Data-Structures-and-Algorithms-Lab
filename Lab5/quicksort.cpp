#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<fstream>


using namespace std;

int count1=0;
int count2=0;
int count3=0;
int swaps1=0;
int swaps2=0;
int swaps3=0;
int comp1=0;
int comp2=0;
int comp3=0;

void swap(double &A,double &B){
	double temp=A;
	A=B;
	B=temp;
}

int partition(double A[],int start,int end){
	double p=A[start]; //p is pivot
	int i=start-1;
	swap(A[start],A[end]);

	for(int j=start;j<end;++j){
		if (A[j]<p){
			i++;
			swap(A[i],A[j]);
	
		}
	}
	swap(A[i+1],A[end]);
	return i+1;

}
int randomized_partition(double A[],int start,int end){
	int i=rand()%(end-start);
	i=i+start;
	swap(A[start],A[i]);
	return partition(A,start,end);
}
void QSP1(double A[],int start,int end){
	if (start<end){
		int q=partition(A,start,end);
		QSP1(A,start,q);
		QSP1(A,q+1,end);
	}
}

void QSRP(double A[],int start, int end){
    if (start<end){
            int q=randomized_partition(A,start,end);
            QSRP(A,start,q);
            QSRP(A,q+1,end);
    }
}

void BuSo(double A[],int start,int end){
    for(int i=0;i<end-1;++i){
       for(int j=0;j<end-i-1;++j){
        if (A[j]>A[j+1]){
        	// swaps3++;
            swap(A[j],A[j+1]);
        }
            // comp3++;
       }
    }
}


int main(int argc, char const *argv[])
{	
    srand(time(0));
    double *d;

    vector<double> time_taken1;
    vector<double> time_taken2;
    vector<double> time_taken3;

    vector<int> swap_count1;
    vector<int> swap_count2;
    vector<int> swap_count3;

    vector<int> comp_count1;
    vector<int> comp_count2;
    vector<int> comp_count3;

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        double a[N];
        double b[N];
        double c[N];
        for(int i=0;i<N;++i){
            cin>>a[i];
            b[i]=a[i];
            c[i]=a[i];
        }
        QSP1(a,0,N-1);
        QSRP(b,0,N-1);
        BuSo(c,0,N);
        for(int i=0;i<N;++i){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<N;++i){
            cout<<b[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<N;++i){
            cout<<c[i]<<" ";
        }
        cout<<endl;




    }
    // for(int i=0;i<20;++i){
        // d=new double[500*(i+1)];
        // for(int j=0;j<500*(i+1);j++){
        //     d[j]=rand();
        // }

        // for(int j=0;j<500*(i+1);j++){
        //     d[j]=j;
        // }

        // for(int j=0;j<25*(i+1);++j){
        // 	swap(d[rand()%500*(i+1)],d[rand()%500*(i+1)]);
        // }

        // for(int j=0;j<500*(i+1);j++){
        //     d[j]=500*(i+1)-j-1;
        // }

        // for(int j=0;j<25*(i+1);++j){
        // 	swap(d[rand()%500*(i+1)],d[rand()%500*(i+1)]);
        // }

        // s1=true;
        // clock_t t;
        // t = clock();
        // QSRP(d,0,500*(i+1));
        // double t1 = 1000 * ((double)(clock() - t)) / CLOCKS_PER_SEC;
        // time_taken1.push_back(t1);
        // swap_count1.push_back(swaps1);
        // comp_count1.push_back(comp1);
        // swaps1=0;
        // comp1=0;


        // d=new double[500*(i+1)];
        // for(int j=0;j<500*(i+1);j++){
        //     d[j]=rand();
        // }

        // for(int j=0;j<500*(i+1);j++){
        //     d[j]=j;
        // }

        // for(int j=0;j<25*(i+1);++j){
        // 	swap(d[rand()%500*(i+1)],d[rand()%500*(i+1)]);
        // }


        // for(int j=0;j<500*(i+1);j++){
        //     d[j]=500*(i+1)-j-1;
        // }

        // for(int j=0;j<25*(i+1);++j){
        // 	swap(d[rand()%500*(i+1)],d[rand()%500*(i+1)]);
        // }

        // s1=false;
        // t = clock();
        // QSP1(d,0,500*(i+1));
        // double t2 = 1000 * ((double)(clock() - t)) / CLOCKS_PER_SEC;
        // time_taken2.push_back(t2);
        // swap_count2.push_back(swaps2);
        // comp_count2.push_back(comp2);
        // swaps2=0;
        // comp2=0;

        // d=new double[500*(i+1)];

        // for(int j=0;j<500*(i+1);j++){
        //     d[j]=rand();
        // }

        // for(int j=0;j<500*(i+1);j++){
        //     d[j]=j;
        // }

        // for(int j=0;j<25*(i+1);++j){
        // 	swap(d[rand()%500*(i+1)],d[rand()%500*(i+1)]);
        // }


    //     for(int j=0;j<500*(i+1);j++){
    //         d[j]=500*(i+1)-j-1;
    //     }

    //     for(int j=0;j<25*(i+1);++j){
    //     	swap(d[rand()%500*(i+1)],d[rand()%500*(i+1)]);
    //     }

    //     t = clock();
    //     BuSo(d,0,500*(i+1));
    //     double t3 = 1000 * ((double)(clock() - t)) / CLOCKS_PER_SEC;
    //     time_taken3.push_back(t3);
    //     swap_count3.push_back(swaps3);
    //     comp_count3.push_back(comp3);
    //     swaps3=0;
    //     comp3=0;


    // }
    // cout<<"QSP1 ";
    // for(auto i: time_taken1){
    // 	cout<<i<<",";
    // }

    // cout<<endl;

    // for(auto i: swap_count1){
    // 	cout<<i<<",";
    // }

    // cout<<endl;
    // for(auto i: comp_count1){
    // 	cout<<i<<",";
    // }
    // cout<<endl<<endl;

    // cout<<"QSRP ";
    // for(auto i: time_taken2){
    // 	cout<<i<<",";
    // }

    // cout<<endl;

    // for(auto i: swap_count2){
    // 	cout<<i<<",";
    // }

    // cout<<endl;
    // for(auto i: comp_count2){
    // 	cout<<i<<",";
    // }

    // cout<<endl<<endl;

    // cout<<"BuSo ";
    	
    // for(auto i: time_taken3){
    // 	cout<<i<<",";
    // }

    // cout<<endl;

    // for(auto i: swap_count3){
    // 	cout<<i<<",";
    // }

    // cout<<endl;
    // for(auto i: comp_count3){
    // 	cout<<i<<",";
    // }

    return 0;
}


