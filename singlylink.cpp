#include <iostream>
//Catch 100- Cant pop node because no node present(Seg Fault)
//Catch 101- Use pop_front not pop_back if only one node present.(Seg fault)

class Node{
    int data;
    Node *next; 
    friend class LinkedList;
};

class LinkedList{
    Node *head;

    public:
        LinkedList();
        void push_back(int d);
        int size();
        void display(); 
        void push_front(int d);
        int pop_front();
        int pop_back();
};
LinkedList::LinkedList(){
    head=NULL;
}
//Adds node to back
void LinkedList::push_back(int d){
        if(head==NULL){
            Node *temp = new Node;
            temp->data=d;
            temp->next=NULL;
            head=temp;
            temp=nullptr;
        }else{
            Node *temp = head;
            Node *nextNode = new Node;
            nextNode->data=d;
            nextNode->next=NULL;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nextNode;
        }
}
//Returns size of linkedlist
int LinkedList::size(){
    if(head==NULL){
        return 0;
    }else{
        Node *temp = head;
        int count=1;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
}
//Displays Linked List
void LinkedList::display(){
    Node *temp = head;
    for(int i=0;i<this->size();i++){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}
//pushes node to front
void LinkedList::push_front(int d){
    Node *firstNode =new Node;
    firstNode->data=d;
    firstNode->next=head;
    head=firstNode;

}
//gets rid of front node
int LinkedList::pop_front(){
    if(this->size()==0){
        throw 100;
    }else{
    Node *temp;
    temp=head->next;
    Node *del;
    del=head;
    int ret = del->data;
    del->next=NULL;
    head=temp;
    return ret;
    }
}
//gets rid of back node
int LinkedList::pop_back(){
    if(this->size()<2){
        throw 101;
    }else{
    Node *last=head;
    for(int i=0;i<this->size()-2;i++){
        last=last->next;
    }
    Node *lastVal=last->next;
    int val=lastVal->data;
    last->next=NULL;
    return val;
    }
}

int main(){
    LinkedList l;
    l.push_back(4);
    l.pop_back();
}
