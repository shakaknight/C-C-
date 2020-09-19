#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX 10
int size = 0;

//creating a stack

struct stack{
    int items[MAX];
    int top;
};
typedef struct stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}
//check if the stack is full.
int isfull(st *s)
{
    if(s->top == MAX - 1)
    return 1;
 else
    return 0;
}


//check if the stack is Empty
int isempty(st *s){
    if (s->top == -1)
     return 1;
    else
     return 0;
}

//add elements into stack ;
void push(st *s, int newitem) {
    if(isfull(s)){
    cout<<"Stack is full";
    }
    else{
        s->top++;
        s->items[s->top] = newitem;
    }
    size++;
}

void pop(st *s){
    if(isempty(s)){
        cout<<"Stack is empty";
    }
    else{
        cout<<"Item popped="<<s->items[s->top];
        s->top--;
    }
    size--;
    cout<<endl;
}

//Print elemnts of Stack;
void printStack(st *s){
    cout<<"Stack:";
    for(int i=0;i<size;i++){
        cout<<s->items[i]<<"";
    }
    cout<<endl;
}
int main(){
    st *s = (st*)malloc(sizeof(st));
    
     createEmptyStack(s);
     
     push(s,1);
     push(s,2);
     push(s,3);
     push(s,4);
     
     printStack(s);
     
     pop(s);
     
     cout<<"\nAfter popping out\n";
     printStack(s);
}