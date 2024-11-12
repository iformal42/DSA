#include<iostream>


using namespace std;


class Node{
    public:
        Node *left;
        int data;
        Node *right;
            
};

class BST{
    private:
        Node *root;
    public:
       
        int count;
        BST(){
                root = nullptr;
                
                count=0;
            }
    private:
        bool search(Node *parent,int key){
            count++;
            if(key == parent->data)
                return true;
            
            else if(key< parent->data){
                if(parent->left == nullptr)
                    return false;
                return search(parent->left,key); 
            }
            else {
                if(parent->right == nullptr)
                    return false; 
                return search(parent->right,key); 
            }
        }
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

        void pre_order(Node *root){
            if(root == nullptr)
            return;
            cout<<root->data<<",";
            pre_order(root->left);
            pre_order(root->right);  
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
    public:
        
        void find(int key){
            if (search(root,key))
                cout<<key<<" Node found "<<endl;
            else
                cout<<key<<" Node not found "<<endl;

        }

        Node *create_node(){
            Node *new_node;
            new_node = new Node;
            cout<<"Enter  Node data: ";
            cin>>new_node->data;
            new_node->left=nullptr;
            new_node->right = nullptr;
            return new_node;
        }
        void insert(){
            Node *new_node;
            if(root == nullptr)
                root = create_node(); 
            else{
                new_node = create_node();
                tree(root,new_node);
            }
        }

        void create_tree(int n){
            for(int i=0;i<n;i++)
                insert();
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
        void level_wise(int h){
            cout<<"\n level wise :-\n";
            for(int i=1;i<=h;i++)
            level(root,i);
            cout<<endl;
        }
        void pre_order(){
            cout<<"\n pre order:-\n";
            pre_order(root); 
            cout<<endl; 
        }
        void in_order(){
            cout<<"\n in order:-\n";
            in_order(root);
            cout<<endl; 

        }
        void post_order(){
            cout<<"\n post order:-\n";
            post_order(root);
            cout<<endl; 

        }

        auto root_data(){
            return root->data;
        }         
};







int main(){
    BST tree,f;
    int n;
    cout<<"Enter number Nodes: ";
    cin>>n;
    f.create_tree(n);
    cout<<f.root_data()<<endl;
    
    // tree.level_wise(3);
    // tree.in_order();
    // tree.post_order();
    // tree.pre_order();
    // cout<<"enter node value to search";
    // cin>>n;
    // tree.find(n);
    // cout<<tree.count<<" steps require to search "<<n;
    // tree.find(75);

    
    // tree.insert();
    // cout<<"\n level wise :-\n";
    // tree.level_wise(3);

    // cout<<"\n in order:-\n";
    // in_order(root);
    // cout<<"\n post order:-\n";
    // post_order(root);
    // cout<<"\n pre order:-\n";
    // pre_order(root);
    
    return 0;

}