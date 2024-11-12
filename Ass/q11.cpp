#include<bits/stdc++.h>

using namespace std;

struct Location{
    string area;
    string city;
    double population;

};

void sort(Location arr[],int n){
    for(int i=1;i<n;i++){
        for (int j=i ;j>0;j--){
            if (arr[j].city < arr[j-1].city)
            swap(arr[j],arr[j-1]);
            else
            break;

        }
    }

}
void linear_src(Location arr[],string city,int n){
    for(int i=0;i<n;i++){
        if (arr[i].city == city){
            cout << "Area = "<<arr[i].area<<endl
            << "Population = "<<arr[i].population;
            return;
        }
    }
    cout << "Not found 404";

}

void binary_search(Location arr[],int size,string target)
{
  int start = 0,end=size-1,mid;

  while(start<=end)
  {
    mid = start + (end - start)/2;
    if(arr[mid].city == target){
         cout << "Area = "<<arr[mid].area<<endl
            << "Population = "<<arr[mid].population;
        return ;
    }
    

    else if (arr[mid].city < target)
    start = mid+1;
    else
    end = mid -1;
  } 
   cout << "Not found 404"; 

} 
int main(){
    Location l[3];
    for (int i=0; i<3;i++){
        cout << "Enter city name: ";
        cin >> l[i].city;
        cout << "Enter area name: ";
        cin >> l[i].area;
        cout << "Enter population: ";
        cin >> l[i].population;
        cout<<endl;  
    }
    sort(l,3);
    // for(int i=0 ;i<3;i++)
    // cout << l[i].city<<endl;
    string name;
    cout << "Enter city name (whose details to find): ";
    cin >> name;
    binary_search(l,3,name);
    //linear_src(l,name,3);

    return 0;

}