// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this -> next = NULL;
        }
        
    }
};

void deleteNode(Node* &head, int pos){
    Node* temp = head;
    if(pos==1){
        head = head -> next;
        temp->next = NULL;
        delete temp;
        return;
    }
    
    int count = 1;
    Node* curr = temp;
    Node* prev = NULL;
    
    while(count<pos){
        prev = curr;
        curr = curr -> next;
        count++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
void insertAtHead(Node* &head, int data){
    
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &tail, int data){
    
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

void printHead(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp -> next;
    }
}

void insertAtPos(Node* &tail, Node* &head, int pos, int data){
    
    if(pos==1){
        insertAtHead(head, data);
        return;
    }
    
    Node* temp = head;
    
    int count = 1;
    while(count<pos-1){
        temp = temp -> next;
        count++;
    }
    
    if(temp -> next == NULL){
        insertAtTail(tail, data);
        return;
    }
    
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
    
    
}
void printTail(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp -> next;
    }
}

int main() {
    // Write C++ code here
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;
    
    insertAtHead(head, 20);
    printHead(head);
    cout<<"---1 ---"<<endl;
    
    insertAtTail(tail, 30);
    printHead(head);
    cout<<"---2 ---"<<endl;
    
    insertAtPos(tail, head, 4, 40);
    printHead(head);
    cout<<"---3 ---"<<endl;
    
    deleteNode(head,4);
    printHead(head);
    cout<<"---4---"<<endl;
    return 0;
}