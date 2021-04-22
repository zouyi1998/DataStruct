#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct Queue *PtrQ;
struct Queue{
    int data;
    PtrQ next;
};

typedef struct FrontRear*FR;
struct FrontRear{ //队首队尾结构体
    PtrQ front; //队首指针
    PtrQ rear; //队尾指针
};

//创建空队列
FR EmptyQueue(){
    FR FandR;
    FandR = (FR)malloc(sizeof(struct FrontRear));
    FandR->front = FandR->rear = NULL;
    return FandR;
}  

//入队
void AddQueue(int x, FR fr){
    PtrQ p;
    p = (PtrQ)malloc(sizeof(struct Queue));
    p->data = x;
    p->next = NULL;
    if(fr->front == NULL && fr->rear == NULL)
    {
        fr->rear = p;
        fr->front = p;
    }   
    else 
    {
        fr->rear->next = p; 
        fr->rear = p; 
    }
}
//删除并返回队尾元素
int DeleteQueue(FR fr){
    PtrQ p;
    int temp;
    if(fr->front == NULL && fr->rear == NULL)
    {
        printf("Empty Queue\n");
        return -1;
    }
    else if(fr->front == fr->rear) 
    {
        p = fr->front;
        fr->front = fr->rear = NULL;
        temp = p->data;
        free(p);
        return temp;
    }   
    else 
    {
        PtrQ p = fr->front;
        temp = p->data;
        fr->front = p->next;
        free(p);
        return temp;
    }
}

int main(){
    FR Q;
    int out;
    Q = EmptyQueue();
    DeleteQueue(Q);
    AddQueue(1, Q);
    AddQueue(2, Q);
    out =DeleteQueue(Q);
    AddQueue(3, Q);
    AddQueue(4, Q);
    AddQueue(5, Q);
    AddQueue(6, Q);
    out =DeleteQueue(Q);
    out =DeleteQueue(Q);
    out =DeleteQueue(Q);
    out =DeleteQueue(Q);
    out =DeleteQueue(Q);
    return 0;
}