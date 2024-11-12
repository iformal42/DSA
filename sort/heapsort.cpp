#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i){
    int largest = i;
    //left child index
    int l = 2*i +1;
    //right child index
    int r = l+1;

    if(l<n && a[l]>a[largest])
    largest = l;

    if(r<n && a[r]>a[largest])
    largest = r;

    if(largest != i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
void build_heap(int a[],int n){
    int i;
    //nodes which have child from 0 to begin 
    int begin = (n/2)-1;
    for(i=begin;i>=0;i--)
        heapify(a,n,i);
}
void sort_array_for_heap(int arr[],int n){
    for(int i=n-1; i>0; i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}

int main(){
    int a[] = {14,15,53,43,23,2,57,45,52,90};
    int n = sizeof(a)/sizeof(a[0]);
    build_heap(a,n);
    sort_array_for_heap(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}