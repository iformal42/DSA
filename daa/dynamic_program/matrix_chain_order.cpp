#include<iostream>

using namespace std;
void matrix_order(int n,int p[],int m[][7],int s[][7])
{
    int i,l,j,k,q;
    // int n = sizeof(p)/sizeof(p[0]) - 1;
    // no need of this loop
    for(i=1;i<=n;i++)
    m[i][i] = 0;
    for(l=2;l<=n;l++)
    {
        for(i=1 ;i<=n-l+1;i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q  = m[i][k] +m[k+1][j] + p[i-1]*p[j]*p[k];
                if (q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }   
            }
        }
    }
}

void printMatrix(int i,int j,int s[][7])
{
    if (i == j)
    cout<<"A"<<i<<" ";
    else 
    {
        cout<<"( ";
        printMatrix(i,s[i][j],s);
        printMatrix(s[i][j]+1,j,s);
         cout<<" )";


    }

}
int main()
{
    int p[] = {30,35,15,5,10,20,25};
    int n = sizeof(p)/sizeof(p[0]) - 1;    
    int m[7][7] = {0};
    int s[7][7] = {0};
    matrix_order(n,p,m,s);
    printMatrix(1,n,s);
    // for(int i=1;i<7;i++){
    //     for(int j=1;j<7;j++)
    //     {
    //         cout<<s[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}