#include<iostream>

using namespace std;

int fibbonacci(int r){
  
    if (r == 0 || r == 1)
    {   
        return 1;}
    return  fibbonacci(r-1) + fibbonacci(r-2);
    
}

int main(){
    int base,power;
    for (int i=0 ;i<5;i++)
    cout << fibbonacci(i);
    // cout << "Enter base: ";
    // cin>>base;
    // cout << "Enter pow: ";
    // cin >> power;
    // double ans = expon_rec(base,power);
    // cout<< ans;
    return 0;   
}

