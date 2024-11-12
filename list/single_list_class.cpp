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
    Node *head,*current_node,*new_node,*temp;
    int size,i;
    public:
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
            current_node = head;
        }
        else{
            new_node = new Node;
            new_node->data = data;
            new_node->next = NULL;
            current_node->next = new_node;
            current_node = new_node;
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
            new_node->next = NULL;
            new_node->next = head;
            head = new_node;
            size++;
        }
        else if (pos>1 && pos<= size){
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
        temp = head;
        delete current_node;
        for(i=1;i<size-1;i++)
            temp = temp->next;
        temp->next = nullptr;
        current_node = temp;
        size--;
        temp = nullptr;
        delete temp;
    }
    
    void deleteAt(int pos){
        if(size==0){
            cout<<"list is empty"<<endl;
            return;
        }
        if(pos<1 || pos>size){
            cout <<"wrong posotion"<<endl;
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
        while(temp){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
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
    l.insert(3);
    l.insert(4);
    l.insert(2,2);
    l.insert(5);
    l.insert(6);
    l.insert(0,1);
    // l.deleteAt();
    l.insert(6);
    // l.deleteAt(l.size-1);
    // l.deleteAt(0);
    l.deleteAt();
    l.deleteAt();
    l.deleteAt();
    // if(true && false)

    // l.deleteAt(1);
    // l.deleteAt(1);
    // l.updateAt(-1,1);
    // l.insert(-2,1);
    // l.updateAt(100,8);
    // l.updateAt(8,9);
    l.display();
    cout<<"size: "<<l.length();
    return 0;

}