#include<iostream>

using namespace std;
int binary_search(int arr[],int size,int target)
{
  int start = 0,end=size-1,mid;

  while(start<=end)
  {
    mid = start + (end - start)/2;
    if(arr[mid] == target)
    return mid;

    else if (arr[mid] < target)
    start = mid+1;
    else
    end = mid -1;
  }  
  return -1;
}

int main()
{
    int arr[] = {1,2,6,7,9,11,13,16,20,24};
    int target = 0,size=sizeof(arr)/sizeof(arr[0]);
    int index = binary_search(arr,size,target);
    cout<<"index of "<<target<<" is"<<index;
    
    return 0;

}