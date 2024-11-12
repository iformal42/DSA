#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next; 

};
class List:public Node{
    private:
    // Node *head,*last_node,*new_node,*temp;
    int size,i;
    public:
     Node *head,*last_node,*new_node,*temp;
    List(){
        size = 0;
        head = NULL;
    }
    void insert(int data){
        // appending
        
        if(head == NULL){
            head = new Node;
            head->data = data;
            head->next = NULL;
            last_node = head;
        }
        else{
            new_node = new Node;
            new_node->data = data;
            new_node->next = head;
            last_node->next = new_node;
            last_node = new_node;
        }
        size++;
    }
    void insert(int data,int pos){
        // inserting 
        if(pos<1 || pos>size+1){
            cout <<"wrong position"<<endl;
            return;
        }
        if(pos == (size+1))
        return insert(data);
        if (pos == 1){
            //creating new node
            new_node = new Node;
            new_node->data = data;
            // new_node->next = NULL;
            new_node->next = head;
            head = new_node;
            last_node->next = head;
            size++;
        }
        else {
            temp = head;
            for (i=1;i<pos-1;i++){
                temp = temp->next;
            }
            new_node = new Node;
            new_node->data = data;
            new_node->next = NULL;
            new_node->next = temp->next;
            temp->next = new_node;
            size++;
        }
        
    }

    void updateAt(int data,int pos){
        if(size==0){
            cout<<"list is empty"<<endl;
            return;
        }
        if(0<pos && pos<=size){
            temp = head;
            if (pos>1 && pos<= size){
                    for (i=1;i<pos;i++)
                        temp = temp->next;
                }
            temp->data = data;
        }
        else{
            cout<<"wrong position"<<endl;
        }
    }

    void deleteAt(){
        if(size==0){
            cout<<"list is empty"<<endl;
            return;
        }
        temp = head;
        // delete last_node;
        for(i=1;i<size-1;i++)
            temp = temp->next;
        temp->next = NULL;
        delete last_node;
        temp->next = head;
        last_node = temp;
        temp = nullptr;
        size--;
        delete temp;
    }
    
    void deleteAt(int pos){
        if(size==0){
            cout<<"list is empty"<<endl;
            return;
        }
        if(pos<1 && pos>size){
            cout <<"wrong posotion"<<endl;
            return;
        }
        if(pos == size)
           return deleteAt();

        Node *del_node;
        temp = head;
        if (pos == 1)
        {
            temp = temp->next;
            delete head;
            head = temp;
            last_node->next = head;
            size--;
            return;
        }

        for (i=1; i<pos-1;i++)
            temp = temp->next;
        del_node = temp->next;
        temp->next = del_node->next;
        delete del_node;
        size--;
    }
    void display(){
        //displaying all elements
        if(size==0){
            cout<<"list is empty"<<endl;
            return;
        }
        temp = head;
        do{
            cout<<temp->data<<endl;
            temp = temp->next;

        }while(temp != head);
        //cout<<temp->data<<endl;
        // while(temp != head){
        //     cout<<temp->data<<endl;
        //     temp = temp->next;
        // }
        temp = NULL;
        delete temp;        
    }
    int length(){
        return size;
    }

};
int main(){
    List l,g;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(5);
    l.insert(0,1);
    l.insert(4,5);
    l.insert(-1,l.length()+1);
    // l.insert(2,2);
    // l.insert(5);
    // l.insert(6);
    // l.insert(0,1);
    l.deleteAt(1);
    l.deleteAt(3);
    l.deleteAt(3);
    l.deleteAt(3);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.deleteAt();
    // l.deleteAt();
    //  l.deleteAt();
    //  l.deleteAt();
    //cout<<l.head->data<<endl;
    // cout<<l.last_node->data<<endl;
    // l.insert(6);
    // // l.deleteAt(l.size-1);
    // // l.deleteAt(0);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // // if(true && false)

    // // l.deleteAt(1);
    // // l.deleteAt(1);
    // // l.updateAt(-1,1);
    // // l.insert(-2,1);
    l.updateAt(100,3);
    l.updateAt(100,2);
    l.updateAt(100,1);
    // // l.updateAt(8,9);
    l.display();
     cout<<"size: "<<l.length();
    return 0;

}