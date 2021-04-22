#include <stdio.h>
#include <stdlib.h>

#define max_size 4

//栈-顺序存储
struct Stack {
    int data[max_size]; 
    int top; //记录栈顶下标
}; 

typedef struct Stack *PtrS; 

//创建空栈
PtrS EmptyStack(){
    PtrS p;
    p = (PtrS)malloc(sizeof(struct Stack));
    p->top = -1;
    return p;
}

//入栈
void Push(int x, PtrS s){
    if(s->top == max_size-1)
    {
        printf("Full Stack\n");
        return;
    }
    else
    {
        s->top++;
        s->data[s->top] = x;
        return;
    }
}

//出栈
void Pop(PtrS s){
    if(s->top == -1){
        printf("Empty Stack\n");
        return;
    }
    else{
        s->top--;
        return;
    }
}


int main(){
    PtrS stack;
    stack = EmptyStack();
    Pop(stack);
    Push(1, stack);
    Push(2, stack);
    Push(3, stack);
    Push(3, stack);
    Push(3, stack);
    Push(3, stack);
    Push(3, stack);
    Pop(stack);
    return 0;
}