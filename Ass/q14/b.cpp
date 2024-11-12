#include<iostream>

using namespace std;

double expon_rec(int b,int p){
  
    if (p >0){
    return b * expon_rec(b,p-1);}
    return 1;
}

int main(){
    int base,power;
    cout << "Enter base: ";
    cin>>base;
    cout << "Enter pow: ";
    cin >> power;
    double ans = expon_rec(base,power);
    cout<< ans;
    return 0;   
}

