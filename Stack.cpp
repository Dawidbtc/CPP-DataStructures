#include<iostream>

class Stack{
    int *ptr;
    int top;
    int size;
    public:
        Stack();
        Stack(int size);
        bool isEmpty();
        bool isFull();
        int pop();
        void push(int c);
        ~Stack();
};

Stack::Stack(){
    ptr=new int[5];
    for(int i=0;i<5;i++){
        ptr[i]=0;
    }
    top=-1;
    size=5;
}
Stack::Stack(int size){
    ptr=new int[size];
    for(int i=0;i<size;i++){
        ptr[i]=0;
    }
    top=-1;
    this->size=size;
}
bool Stack::isEmpty(){
    if(top=-1){
        return true;
    }else{
        return false;
    }
}
bool Stack::isFull(){
    if(top==size-1){
        return true;
    }else{
        return false;
    }
}
int Stack::pop(){
    if(this->isEmpty()){
        throw 100;
    }else{
        int temp=ptr[top];
        ptr[top]=0;
        top--;
        return temp;
    }
}
void Stack::push(int c){
    if(this->isFull()){
        throw 200;
    }else{
        top++;
        ptr[top]=c;
    }
}
Stack::~Stack(){
    delete []ptr;
}

int main(){
    Stack c(4);
    try{
        c.push(4);
        c.push(3);
        c.push(1);
        c.push(2);
        c.push(5);
    }catch(int e){
    switch(e){
        case 100:
            std::cout<<"Stack Underflow";
            break;
        case 200:
            std::cout<<"Stack overflow";
            break;
    }
}
}