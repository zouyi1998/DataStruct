#include <stdio.h>
#include <stdlib.h>

#define max_size 4
//循环队列-数组实现
typedef struct Queue * PtrQ;
struct Queue
{
    int data[max_size]; //声明项数为max_size的数组，下标从0到max_size-1
    int front,rear; //队首与队尾
};

//创建空队列
PtrQ EmptyQueue(){
    PtrQ p;
    p = (PtrQ)malloc(sizeof(struct Queue));
    p->front = max_size-1; 
    p->rear = max_size-1; 
    return p;
}
//入队
void AddQueue(int x, PtrQ q){
    if( (q->rear+1)%max_size == q->front)
    {
        printf("Full Queue\n");
        return;
    }
    else{
        q->rear = (q->rear+1)%max_size;
        q->data[q->rear] = x;
        return;
    }
}

//出队
int DeleteQueue(PtrQ q){
    int temp;
    if (q->rear == max_size-1 && q->front == max_size-1 )
    {
        printf("Empty Queue\n");
        return -1;
    }
    else if ( (q->front+1)%max_size == q->rear )
    {
        temp = q->data[q->rear]; 
        q->front = q->rear = max_size-1; 
        return temp;
    }
    else
    {
        q->front = (q->front+1)%max_size;
        temp = q->data[q->front]; 
        return temp;
    }
}

int main(){
    PtrQ Q;
    Q = EmptyQueue();
    DeleteQueue(Q);
    AddQueue(1, Q);
    AddQueue(2, Q);
    DeleteQueue(Q);
    AddQueue(3, Q);
    AddQueue(4, Q);
    AddQueue(5, Q);
    AddQueue(6, Q);
    DeleteQueue(Q);
    DeleteQueue(Q);
    DeleteQueue(Q);
    DeleteQueue(Q);
    return 0;
}