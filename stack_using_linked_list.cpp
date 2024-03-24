// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
  
    public:
        int size;
        Node* top;
        
    Stack(){
        this->size = 0;
        this->top = NULL;
    }
    
    void push(int data){
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }
    
    void pop(){
        if(top!=NULL){
            Node* temp = top;
            top = top->next;
            temp->next = NULL;
            size--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }
    
    int peek(){
        if(top!=NULL){
            cout<<top->data<<endl;
            return top->data;
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    
    
};

int main() {
    // Write C++ code here
    
    Stack s;
    s.push(10);
    s.peek();
    s.push(20);
    s.peek();
    s.push(30);
    s.peek();
    s.push(40);
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    s.peek();
    cout<<s.size<<endl;
    s.pop();
    s.peek();
    cout<<s.size<<endl;
    return 0;
}