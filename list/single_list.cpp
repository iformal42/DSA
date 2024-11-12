#include<bits/stdc++.h>

// void insert_last(int d){
//         new_node = new single_list;
//         //new_node->next = NULL;
//         new_node->n = d;
//         new_node->next = NULL;
//         current_node->next = new_node;
//         current_node = new_node;
//     }


using namespace std;
static int len=0;

int length(){
    len++;
    return len;

}
struct single_list
{
    /* data */
    int n;
    single_list *next;
   int list_length= length();
   
};
static single_list *head,*current_node,*new_node;

void insert_pos(int data,int pos){
    if(pos>1 && pos<len){
    new_node = new single_list;
    new_node->n = data;
    new_node->next = NULL;
   
    single_list *prev_node;
    prev_node = head;
    for(int i=2;i<pos;i++) {
            prev_node = prev_node->next;
            
            }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    }
    else{
        cout<<"use insert() for start and end insert"<<endl;
    }

}

void insert(int d,string pos){
        new_node = new single_list;
        new_node->n = d;
        new_node->next = NULL;
        if (pos == "start"){
        new_node->next = head;
        head = new_node;
        }
        if (pos == "end"){
        current_node->next = new_node;
        current_node = new_node;
        }

    }

void delete_pos(int pos){
    single_list *prev_node,*delete_node;
    prev_node = head;
    if(pos>1 && pos<len){
        for(int i=2;i<pos;i++) {
            prev_node = prev_node->next;
            }
        delete_node = prev_node->next;
        prev_node->next = delete_node->next;
        delete delete_node;
         len --;
    }
     else{
        cout<<"use delete_at() for start and end delete"<<endl;
    }
    
}
void delete_at(string pos="end"){
    single_list *prev_node;
    prev_node = head;

    if (pos == "end"){
        for(int i=1;i<len-1;i++) {
            prev_node = prev_node->next;
            }
        delete current_node;
        current_node = prev_node;
        current_node->next = NULL;
         len --;
    }
   
   if (pos == "start"){
    delete head;
    head = prev_node->next;
     len --;
   }
   
}

void update(int d,int pos){
    if(pos>0 && pos<=len){
        single_list *prev_node;
        prev_node = head;
        for (int i=2; i<=pos;i++){
            prev_node = prev_node->next;
        }
        prev_node->n = d;
        return;
    }
    cout<<"Not a valid node"<<endl;
}

void create_list(){
     head = new single_list;
    current_node = head;
    current_node->n = 1;
    current_node->next = NULL;
    for(int i=2;i<6;i++){
        // assigning new memory to temp;
        new_node = new single_list;
        new_node->n = i;
        new_node->next = NULL;
        current_node->next = new_node;
        current_node = new_node;
    }
    
}
void display(single_list *h){
    int count=0;
    while (h)
    {
        cout<<"data "<<h->n<<endl;
        //cout<<"next"<<h->next<<endl;
        h = h->next;
        count++;
    }   

}
int main(){
    string s = "start",e = "end";
    
    // head = new single_list;
    // current_node = head;
    // current_node->n = 1;
    // current_node->next = NULL;
    // for(int i=2;i<6;i++){
    //     // assigning new memory to temp;
    //     new_node = new single_list;
    //     new_node->n = i;
    //     new_node->next = NULL;
    //     current_node->next = new_node;
    //     current_node = new_node;
    // }
    

//     insert(0,s);
//     insert(-1,s);
//     insert(-2,s);
//     insert(60,e);
//     delete_at();
//     delete_at(s);
//     delete_at(s);
//     insert_pos(11,3);
//    delete_pos(7);
    //  update(20,2);
    //  update(30,3);
    //  update(40,4);
    create_list();
    
    display(head);
    cout<<"length "<<len;
    
    
    return 0;
}