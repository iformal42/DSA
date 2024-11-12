#include<iostream>
using namespace std;

void merge_sort(int arr1[],int arr2[]){
    


}

void divide(int arr[],int size){
    int one_half = size/2;
    int other_half = size - one_half;
    int arr1[one_half],arr2[other_half];
    if(size <= 1)
      return;
    
    for (int i = 0 ; i <one_half; i++){
        arr1[i] = arr[i];
    }
    for (int i=one_half; i<other_half;i++){
        arr2[i] = arr[i];
    }
   
    divide(arr1,one_half);
    divide(arr2,other_half);
    
    cout << arr1[0] <<","<< arr2[0] <<endl;
}

void merge_sort(int arr[],int begin, int end){
    if (begin <= end) return;
    int mid = begin - (end - begin)/2;

    merge_sort(arr,begin,mid);
    merge_sort(arr,mid+1,end);

}

void printarr(int arr[],int size){
    for (int i = 0 ; i<size ;i++){
        cout<<arr[i]<<",";
    }

}
int main(){
    int a[] = {32,2,31,94,10,1};
    int size = sizeof(a)/sizeof(a[0]);
    divide(a,size);
  
    // printarr(a,size);

    return 0;
}