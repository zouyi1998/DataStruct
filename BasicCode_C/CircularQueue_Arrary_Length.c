#include <stdio.h>
#include <stdlib.h>

#define max_size 4 //最大长度
//循环队列-顺序存储-设置队长length区分满和空
typedef struct Queue * PtrQ; 
struct Queue
{
    int data[max_size]; //max_size为数组总长度，下标从0到max_size-1
    int front,rear; //队首，队尾
    //在循环队列可以认为front指向待出队的元素的前一个位置。
    //因此出队操作为front向后移动一个单位，输出当前位置的值
    int length; //长度
};

//创建空队列
PtrQ EmptyQueue(){
    PtrQ p;
    p = (PtrQ)malloc(sizeof(struct Queue));
    p->front = 0; 
    p->rear = 0; 
    p->length = 0; //长度
    return p;
}

//入队：判断队伍是否为满，将元素x加入队尾
void AddQueue(int x, PtrQ q){
    if(q->length == max_size) //判断队列是否满
    {
        printf("Full Queue\n");
        return ;
    }
    else
    {
        q->rear = (q->rear+1)%max_size;
        q->data[q->rear] = x;
        q->length++;
        return ;
    }
}

//出队：判断队伍是否为空，将队首元素出队
int DeleteQueue(PtrQ q){
    int temp;
    if(q->length == 0)
    {
        printf("Empty Queue\n");
        return -1;
    }
    else
    {
        q->front = (q->front+1)%max_size;
        temp = q->data[q->front];
        q->length--;
        return temp;
    }
}
int main(){
    PtrQ Q;
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