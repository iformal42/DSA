#include<iostream>
using namespace std;
void tree(int a[],int n,int i,int node){
    //this function insert node in tree
    if(node<=a[i]){
        int l = 2*i+1;
        if(l>n-1){
            cout<<node<<"goes out of range\n";
            return;
            }
        if (a[l]==-1){
            a[l] = node;
            return;
        }
        else
        return tree(a,n,l,node);
       
    }
    else if(node>a[i]){
       int r = 2*i + 2;
       if(r>n-1){
            cout<<"out of range";
            return;
            }
       if (a[r]==-1){
           a[r] = node;
            return;
        }
        else
        return tree(a,n,r,node);
    }
   

}
void create_tree(int a[],int n){
    // this function accepts and create a tree 
    int node;
    cout<<"Enter root node:";
    // creating a root node
    cin>>a[0];
    for(int i=1;i<n;i++){
        cout<<"Enter node: ";
        cin>>node;
        //calling function to create a tree
        
        tree(a,n,0,node);
        
    }

}
void in_order(int a[],int n,int i){
    if(i>n-1 || a[i] == -1)
    return;
    in_order(a,n,2*i+1);
    cout<<a[i]<<",";
    in_order(a,n,2*i+2);
}
int main(){
    int n = 15;
    int arr[n] = {70,60,80,58,62,78,90,40,59,61,63,76,79,81,100};
    int i;
    // for( i=0;i<n;i++)
    //     arr[i] = -1;
    
    // create_tree(arr,n);
    in_order(arr,n,0);
    // for( i=0;i<n;i++)
    //     cout<<arr[i]<<",";


}