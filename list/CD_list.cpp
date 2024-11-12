#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        Node *prev;
        int data;
        Node *next; 

};
class D_List{
    private:
    Node *head,*last_node,*new_node,*temp;
    int size,i;
    public:
    D_List(){
        size = 0;
        head = NULL;
    }
    void insert(int data){
        // appending
        
        if(head == NULL){
            head = new Node;
            head->prev = NULL;
            head->data = data;
            head->next = NULL;
            last_node = head;
        }
        else{
            new_node = new Node;
            new_node->data = data;
            new_node->prev = NULL;
            new_node->next = NULL;

            last_node->next = new_node;
            new_node->prev = last_node;
            last_node = new_node;
            last_node->next = head;
            head->prev = last_node;
        }
        size++;
    }
    void insert(int data,int pos){
        // inserting 
        if(pos == (size+1))
        return insert(data);
        if (pos == 1){
            new_node = new Node;
            new_node->data = data;
            new_node->prev = NULL;
            new_node->next = head;

            head->prev = new_node;
            head = new_node;
            head->prev = last_node;
            last_node->next = head;
            size++;
        }
        else if (pos>1 && pos<= size){
            temp = head;
            for (i=1;i<pos-1;i++){
                temp = temp->next;
            }
            new_node = new Node;
            new_node->data = data;
            new_node->next = temp->next;
            new_node->next->prev = new_node;
            temp->next = new_node;
            new_node->prev = temp;
            temp = nullptr;
            size++;
        }
        else{
            cout<<"!!for position "<<pos<<" use another method or it is wrong postion"<<endl;
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
        if(size == 1){
            delete head;
            size--;
            return;
        }
        temp = last_node->prev;
        
        temp->next = nullptr;
        delete last_node;
        last_node = temp;
        last_node->next = head;
        head->prev = last_node;
        temp = nullptr;
        size--;
        delete temp;
    }
    
    void deleteAt(int pos){
        if(size==0){
            cout<<"list is empty"<<endl;
            return;
        }
        if(pos<1 || pos>size){
            cout <<"wrong position"<<endl;
            return;
        }
        if(pos == size){
            deleteAt();
            return;
        }
         
        Node *del_node;
        temp = head;
        if (pos == 1)
        {
            head = temp->next;
            head->prev = last_node;
            last_node->next = head;
            delete temp;
            // delete head;
            // head = temp->next;
            size --;
            return;
        }

        for (i=1; i<pos-1;i++)
            temp = temp->next;
        del_node = temp->next;
        temp->next = del_node->next;
        del_node->next->prev = temp;
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
            cout<<temp->data<<"<->";
            temp = temp->next;
        }while(temp!=head);
        cout<<"\nreverse:- "<<endl;
        temp = last_node;
        do{
            cout<<temp->data<<"<->";
            temp = temp->prev;
        }while(temp!=last_node);
        temp = NULL;
        delete temp;        
    }
    int length(){
        return size;
    }

};
int main(){
    D_List l,g;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    
    l.insert(5);
    l.insert(6);
    l.insert(0,1);
    //l.insert(100,7);
    //l.deleteAt();
    // l.deleteAt();
    // l.deleteAt();
    // l.deleteAt();
    // l.deleteAt();
    l.deleteAt(5);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.deleteAt(1);
    //l.deleteAt();
    // l.insert(1002,5);
    // l.insert(101,4);
    // l.insert(100,3);
    // // l.deleteAt(l.size-1);
     
    // if(true && false)

    // l.deleteAt(1);
    // l.deleteAt(1);
    l.updateAt(-1,6);
    // l.insert(-2,1);
    // l.updateAt(100,8);
    // l.updateAt(8,9);
    l.display();
    cout<<"\nsize: "<<l.length();
    return 0;

}