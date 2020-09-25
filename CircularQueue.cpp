#include<iostream>
#define SIZE 5

using namespace std;

class Queue{
private:
    int items[SIZE],front,rear;
public:
Queue(){
    front= -1;
    rear = -1;
}

bool isFull(){
    if(front == 0 && rear == SIZE -1){
     return true;
    }
    if (front == rear+1){
        return true;
    }
    return false;
}
bool isEmpty(){
    if(front == -1)
     return true;
    else 
     return false;
}

//Adding the elemnet in the quque
int enQueue(int element){
    if(isFull()){
        cout<<"The queue is full. Unable to insert";
        cout<<endl;
    }
    else{
        if(front == -1) front = 0;
        rear = (rear+1)%SIZE;
        items[rear] = element;
        cout<<endl
            <<"Inserted"<<element<<endl;
    }
}
//Removing element from teh quque
int deQueue(){
    int element;
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return(-1);
    }else{
        element = items[front];
        if(front==rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%SIZE;
        }
        return(element);
    }
 }

void display(){
    int i;
    if(isEmpty()){
        cout<<endl
        <<"Empty queue"<<endl;
    }else{
        cout<<"Front-->"<<front;
        cout<<endl;
        cout<<"Items-->";
        for(i=front;i!=rear;i=(i+1)%SIZE)
            cout<<items[i];
        cout<<items[i];
        cout<<endl
             <<"Rear-->"<<rear<<endl;
        
        
    }
}
};
int main(){
    Queue q;
    
    //Fails because front = -1
    q.deQueue();
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    
    //Fails
    q.enQueue(6);
    
    q.display();
    int elem = q.deQueue();
    if(elem != 1)
        cout<<endl
         <<"Deleted Element is"<<elem;
    q.display();
    
    q.enQueue(7);
    
    q.display();
    
    //Fails to enQueue because front == rear +1
    q.enQueue(8);
    
    return 0;
}