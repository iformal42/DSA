#include<iostream>
using namespace std;
struct Node
{
    char data;
    Node *next;
};

Node**create_list(int n){
    Node **a = new Node*[n];
    Node *temp,*node;
    int i,j,ans;

    for(i=0;i<n;i++)
    {
        a[i] = new Node();
        a[i]->data = 'A' + i;
        temp = a[i];
        temp->next = nullptr; 
        for(j=0;j<n;j++)
        {
            cout<<"Is there any edge between pair of vertices ("
            <<i+1<<","<<j+1<<") ?: ";
            cin>>ans;
            if(ans)
            {
                node = new Node();
                node->data = 'A' + j;
                node->next = nullptr;
                temp->next = node;
                temp = node;         
            }                    
        }
    }
    return a;
}
void display(Node **a,int n){
    
    
    for(int i=0;i<n;i++){
        Node *temp = a[i];
        while(temp){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
        
    }

}
int main(){
    int vertices;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    Node **L = create_list(vertices);
    cout<<endl;
    // Node *p = L[0];
    // p++;
    // cout<<p->next->next->data;
    display(L,vertices);
    return 0;
}