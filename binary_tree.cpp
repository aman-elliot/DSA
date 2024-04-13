// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;

class Node{
    
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(){
    cout<< "Enter data: ";
    int data;
    cin>>data;
    
    Node* root = new Node(data);
    
    if(data==-1){
        return NULL;
    }
    
    cout<<" Enter data for left node of "<<data<<endl;
    root->left = buildTree();
    cout<<" Enter data for right node of "<<data<<endl;
    root->right = buildTree();
    
    return root;
}

void levelOrderTraversal(Node* root){
    
    queue<Node*>q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        
        Node* temp = q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            
        }
        
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorderTraversal(Node* root){
    
    if(root == NULL){
        return;
    }
    
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
  
}

void preorderTraversal(Node* root){
    
    if(root == NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  
}

void postorderTraversal(Node* root){
    
    if(root == NULL){
        return;
    }
    
   
    postorderTraversal(root->left);
    postorderTraversal(root->right);\
    cout<<root->data<<" ";
  
}

int main() {
    // Write C++ code here
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = buildTree();
    cout<<"--------- tree complete---------"<<endl;
    cout<<"--------- levelOrderTraversal --------"<<endl;
    levelOrderTraversal(root);
    cout<<"--------- inorderTraversal --------"<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"--------- preorderTraversal --------"<<endl;
    preorderTraversal(root);
    cout<<endl;
    cout<<"--------- postorderTraversal --------"<<endl;
    postorderTraversal(root);
    cout<<endl;
    return 0;
}