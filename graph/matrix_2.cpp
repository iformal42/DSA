#include<iostream>

using namespace std;

int main(){
    int n,p,q,i,j;
    cout<<"Enter number of vertces: ";
    cin>>n;
    int a[n][n] = {0};
    a[0][n-1] = 0;
    string pair;
    while(true){
        cout<<"enter 0 to stop: ";
        cin>> pair;
        p = pair[0] - '0';
        q = pair[2] - '0';
        if(p==0||q==0)
        break;
        p--;
        q--;
        cout<<p<<q<<endl;
        a[p][q]++;
    }
    // cout<<a[0][n-1]<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<a[i][j]<<"  ";
        cout<<endl;
    }

}