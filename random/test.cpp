//Write a C++ code that takes integer as an input and returns the position name as output.
// in 51 -> 51st,52 -> 52nd,11 -> 11th
#include<iostream>

using namespace std;

int  binarysearch(int arr[],int s,int e,int target){
    int mid,end = e,start=s;


    while(start<=end){
        mid = start+end;
        mid /=2;

        if(arr[mid] == target)
         return mid;

        else if (arr[mid] > target)
        end = mid-1;

        else 
        start = mid+1;

    }
    return -1;

}

int main(){
    
    // int arr[] = {2,3,4,8,9,11,16,18,34};

    // n = sizeof(arr)/sizeof(arr[0]);
    // int p = binarysearch(arr,0,n-1,16);
    
    // cout <<p;
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int last_digit;

    last_digit = n%10;
    int last_digit_2 = n%100;

    if (last_digit == 1 and last_digit_2 != 11)
    cout<<n<<"st";
    else if (last_digit == 2 and last_digit_2 != 12)
    cout<<n<<"nd";
    else if (last_digit == 3 and last_digit_2 != 13)
    cout<<n<<"rd";
    else 
       cout<<n<<"th";

    // // if (last_digit == 1 and (10>n || n>20))
    // // cout<<n<<"st";
    // // else if (last_digit == 2 && (10>n || n>20))
    // //  cout<<n<<"nd";

    // // else if(last_digit == 3 && (10>n || n>20))
    // // cout<<n<<"rd";
    
    // // else 
    // // cout<<n<<"th";

}