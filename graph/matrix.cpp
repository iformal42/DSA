#include<iostream>
using namespace std;
int main(){
    int n,i,j,count_out_deg=0;
    cout<<"Enter number of vertices: ";
    cin>>n;
    int a[n][n];
    int out_degree[n],in_degree[n] = {0};
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<"Is there any edge between pair of vertices ("
            <<i+1<<","<<j+1<<") ?: ";
            cin>>a[i][j];
            count_out_deg+=a[i][j];
            in_degree[j]+=a[i][j];
        }
        out_degree[i]=count_out_deg;
        count_out_deg = 0;
    }
    cout<<"Matrix representation : "<<endl<<"  ";
    for(i=1;i<=n+1;i++){
        if(i==n+1){
            cout<<" Out Degree: "<<endl;
            break;
        }
        cout<<" v"<<i;      
    }
    for(i=0;i<n;i++){
        cout<<"v"<<i+1<<"  ";
        for(j=0;j<n;j++)
            cout<<a[i][j]<<"  ";
        cout<<"  "<<out_degree[i]<<endl;
    }
    cout<<"\nin  ";
    for(i=0;i<n;i++)
    cout<<in_degree[i]<<"  ";

    return 0;

}