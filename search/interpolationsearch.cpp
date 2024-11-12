#include<iostream>

using namespace std;
int interpolation_search(int a[],int start,int end,int target){

    int pos;
    if(start<=end && target>= a[start] && target<=a[end]){

        pos = start + (((double)(end - start)/(a[end] - a[start]))*(target-a[start]));
        
        if (a[pos] == target)
        return pos;

        if(target < a[pos])
        return interpolation_search(a,start,pos-1,target);
        else if (target > a[pos])
        return interpolation_search(a,pos+1,end,target);
    }
    return -1;
}


int main(){
    int a[] = {-9,-5,-4,-3,-2,-1};
    int n = sizeof(a)/sizeof(a[0]);
    int pos = interpolation_search(a,0,n-1,-1);
    cout << pos<<endl;

}
