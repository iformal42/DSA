#include<iostream>

using namespace std;
int natural_num(int n){
    int g = n*(n+1);
    return g/2;
}

// int sum_of_arr(int arr[]){

// }
int main(){
    // [0,1]
    //[9,6,4,2,3,5,7,0,1]
    int arr[] = {9,6,4,2,3,5,7,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum=0;

    for(int i=0;i<n;i++)
    sum +=arr[i];
    // cout<<sum;
    // cout<<natural_num(n);

    int miss = natural_num(n) - sum;

    cout << miss;


}