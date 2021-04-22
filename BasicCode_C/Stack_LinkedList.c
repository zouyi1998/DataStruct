#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //定义了布尔类型

typedef struct Stack *PtrS;//给指向栈的指针取别名

//栈-链式存储
struct Stack
{
    int data;
    PtrS next;
};

//创建空栈
PtrS EmptyStack(){
    PtrS p;
    p = (PtrS)malloc(sizeof(struct Stack));
    p->next = NULL;
    return p;
}

//检查栈是否为空
//时间复杂度O(1)
bool IsEmpty(PtrS s){
    if(s->next == NULL)
        return true;
    else
        return false;
}

//入栈:链表实现的栈无需检查是否为满
//时间复杂度O(1)
void Push(int x, PtrS s){
    PtrS p;
    p = (PtrS)malloc(sizeof(struct Stack));
    p->data = x;
    p->next = s->next;
    s->next = p;
    return;
}

//出栈：检查是否为空
//时间复杂度 O(1)
void Pop(PtrS s){
    PtrS p;
    if(IsEmpty(s))
    {
        printf("Empty Stack");
        return;
    }
    else
    {
        p = s->next;
        s->next = p->next;
        free(p);
        return;
    }
}

int main(){
    PtrS stack;
    stack = EmptyStack();
    Pop(stack);
    Push(1,stack);
    Push(2,stack);
    Push(3,stack);
    Push(4,stack);
    Push(5,stack);
    Pop(stack);
    return 0;
}