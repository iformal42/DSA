#include<iostream>
using namespace std;
int fibo_search(int a[],int n,int target){

    // if (n<1)
    // return -1;
    // if (n==1)
    // return 0;
    int fm2,fm1,fm;
    fm2 = 0,fm1=1;
    fm=fm2+fm1;
    while(fm<n){
        fm2 = fm1;
        fm1 = fm;
        fm = fm1 + fm2;
    }
    int offset = -1;
    while(fm>1){
        int i = min(fm2+offset,n-1);
        if (a[i] == target)
        return i;

        if (a[i] < target){
            fm = fm1;
            fm1 = fm2;
            fm2 = fm - fm1; 
            offset = i;
        }
        else if (a[i] > target){
            fm = fm2;
            fm1 -= fm2;
            fm2 = fm - fm1; 
        }

    }

    if (fm1 && a[offset+1]==target)
    return offset+1;
    return -1;

}

int main(){
    int a[] = {2,3,4,6,8,10,14,18,30};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<fibo_search(a,n,30);

}