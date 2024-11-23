#include<iostream>

using namespace std;
void print_lcs(string X,char b[][7],int i,int j)
{
    if (i == 0 || j==0)
    return ;
    if (b[i][j] == '\\')
    {
        print_lcs(X,b,i-1,j-1);
        cout<<X[i-1]<<" ";
    }
    else if(b[i][j] == '<')
    print_lcs(X,b,i,j-1);
    else 
    print_lcs(X,b,i-1,j);


}
void LCS(string X,string Y)
{
    int row,col,i,j;
    row = X.length()+1;
    col = Y.length()+1;
    int c[row][col];
    char b[row][7] = {0};
    for(i=0; i<row;i++)
    c[i][0] = 0;
    for(i=0; i<col;i++)
    c[0][i] = 0;

    for(i=1;i<row;i++)
    {
        for(j=1;j<col;j++)
        {
            if(X[i-1] == Y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = '\\';
            }
            else if(c[i-1][j]>= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = '^';
            }
            else 
            {
                c[i][j] = c[i][j-1];
                b[i][j] = '<';
            }
        }
    }
    for(i=0;i<row;i++)
    {   
    for(j=0;j<col;j++)
         cout<<b[i][j]<<" ";
    cout<<endl;
    }
    
    print_lcs(X,b,row-1,col-1);


}
int main()
{
    string X="ABCBDAB";
    string Y="BDCABA";
    LCS (X,Y);
    // cout<<'\\';

    return 0;
}