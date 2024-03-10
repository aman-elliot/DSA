// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    
    public:
        int data;
        Node* next;
        Node* prev;
    
    Node(int data){
        this-> data = data;
        this-> next = NULL;
        this-> prev = NULL;
    }
    
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void printLL(Node* head){
    Node* temp = head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head, int data){
    
    Node* newNode = new Node(data);
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &tail, int data){
    
    Node* newNode = new Node(data);
    newNode -> prev = tail;
    tail -> next = newNode;
    tail = newNode;
}

void insertAtPos(Node* &head, int data, int pos){
    
    if(pos==1){
        insertAtHead(head, data);
        return;
    }
    
    Node* temp = head;
    int c=1;
    while(c!=pos-1){
        temp = temp->next;
        c++;
    }

    Node* newNode = new Node(data);
    newNode -> prev = temp;
    newNode -> next = temp -> next;
    temp->next = newNode;
}

void deleteAtPos(Node* &head, int pos){
    if(pos==1){
        Node* temp = head;
        temp->next->prev=NULL;
        head = temp->next;
        temp->next=NULL;
        delete temp;
    }
    
    Node* temp = head;
    
    int c=1;
    
    while(c<pos){
        temp = temp->next;
        c++;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
    
}
int main() {
    // Write C++ code here
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;
    printLL(newNode);
    insertAtHead(head, 20);
    printLL(head);
    insertAtTail(tail, 30);
    printLL(head);
    insertAtTail(tail, 40);
    printLL(head);
    insertAtPos(head, 50, 5);
    printLL(head);
    deleteAtPos(head,4);
    printLL(head);
    return 0;
}