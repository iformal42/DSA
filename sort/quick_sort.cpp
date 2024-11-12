#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
    int pivot = arr[end];
    int low = start - 1;
    for (int i = start; i<end; i++){
        if (arr[i] < pivot){
            low ++;
            swap(arr[low],arr[i]);
        }
    }
   swap(arr[end],arr[low+1]);
   return low + 1;

}
void quick_sort(int arr[],int start,int end){
    if (start >= end) return ;
    int p = partition(arr,start,end-1);
    quick_sort(arr,start,p);
    quick_sort(arr,p+1,end);
    

   
    }




void printarr(int arr[],int size){
    for (int i = 0 ; i<size ;i++){
        cout<<arr[i]<<",";
    }

}
int main(){
    int a[] = {20,80,30,90,40,10,1,20,100,21};
    int size = sizeof(a)/sizeof(a[0]);
    quick_sort(a,0,size);
    printarr(a,size);

    return 0;
}