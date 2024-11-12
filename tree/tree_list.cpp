#include<iostream>

using namespace std;

struct Node{
        Node *left;
        int data;
        Node *right;           
};
void tree(Node *parent,Node *node){
    if(node->data<= parent->data){
        if(parent->left != nullptr)
        return tree(parent->left,node);
        parent->left = node;
        return;
    }
    if(parent->right != nullptr)
        return tree(parent->right,node);  
    parent->right = node;

}
Node *create_node(){
    Node *new_node;
    new_node = new Node;
    cout<<"Enter root Node data: ";
    cin>>new_node->data;
    new_node->left=nullptr;
    new_node->right = nullptr;
    return new_node;

}
void insert(Node *root){
    Node *new_node;
    new_node = create_node();
    tree(root,new_node);

}
Node *create_tree(int n){
    Node *root;
    root = create_node();
    for(int i=1;i<n;i++){
        insert(root);
    }
    return root;


}
void in_order(Node *root){
    if(root == nullptr)
    return;
    in_order(root->left);
    cout<<root->data<<",";
    in_order(root->right);
}
void post_order(Node *root){
    if(root == nullptr)
    return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<",";
}
void level(Node*root ,int i){
    if(root == nullptr)
    return;
    if(i==1)
    cout<<root->data<<",";
    else if(i>1){
        level(root->left,i-1);
        level(root->right,i-1);
    }
}
void pre_order(Node *root){
    if(root == nullptr)
    return;
    cout<<root->data<<",";
    pre_order(root->left);
    pre_order(root->right);
   

}
int main(){
    int n;
    cout<<"Enter number Nodes: ";
    cin>>n;
    Node *root = create_tree(n);
    cout<<"\n level wise :-\n";
    for(int i=1;i<=4;i++)
    level(root,i);

    cout<<"\n in order:-\n";
    in_order(root);
    cout<<"\n post order:-\n";
    post_order(root);
    cout<<"\n pre order:-\n";
    pre_order(root);
    
    return 0;

}