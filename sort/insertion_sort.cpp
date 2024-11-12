#include<iostream>
using namespace std;

void insertion_sort(int arr[],int size){
    int j,key;
    for(int i=1;i<size; i++){
        j = i-1;
        key = arr[i];

        while (j >= 0 && arr[j]>key)
        {   
            swap(arr[j+1],arr[j]);
            key = arr[j];
            j--;
            
        }
       
        
        
        
        }
    }




void printarr(int arr[],int size){
    for (int i = 0 ; i<size ;i++){
        cout<<arr[i]<<",";
    }

}
int main(){
    int a[] = {32,2,31,94,10,1};
    int size = sizeof(a)/sizeof(a[0]);
    insertion_sort(a,size);
    printarr(a,size);

    return 0;
}