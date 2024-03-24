// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Stack{
    
    public:
        int * arr;
        int top;
        int size;
        
    Stack(int size){
        this->size=size;
        arr = new int[size];
        top = -1;
    }
    
    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"stack overflow<<endl";
        }
    }
    
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow";
        }
    }
    
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"<stack is empty"<<endl;
            return -1;
        }
    }
    
    bool isEmpty(){
        if(top<0){
            return true;
        }
        return false;
    }
};

int main() {
    // Write C++ code here
    Stack s(5);
    s.push(20);
    cout<<s.peek()<<endl;
    s.push(30);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    s.pop();
    cout<<s.isEmpty()<<endl;
    s.pop();
    return 0;
}