#include <stdio.h>
#include <stdlib.h> //malloc函数
#define MAXSIZE 10

//线性表-顺序存储
typedef struct LNode *List; 
struct  LNode
{
    int Data[MAXSIZE]; 
    int Last; 
};
// struct LNode L; 结构体，用 . 访问成员
// List PrtL; 结构体指针，用 -> 访问成员

//建立空表
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode)); 
    //malloc产生大小和struc LNode相同的空间并强制转换为List类型
    PtrL->Last = -1; //记录最后一个数的下标
    return PtrL;
}

//查找元素X
int Find(int X, List PtrL)
{
    int i = 0;
    while( i<=PtrL->Last && PtrL->Data[i] != X  )
        i++;
    if (i > PtrL->Last ) return -1;
    else return i;
}

//在pos位置前插入一个元素
void Insert(int X, int pos, List PtrL)
{
    int j;
    if (PtrL->Last == MAXSIZE-1) 
        printf("Full List\n"); 
    for(j = PtrL->Last;j >= pos-1;j--) 
        PtrL->Data[j+1] = PtrL->Data[j];
    PtrL->Data[pos-1] = X;
    PtrL->Last++; 
    return;
}

//删除pos位置的元素
void Delete(int pos, List PtrL)
{
    int j;
    if(PtrL->Last == -1)
    { 
        printf("Empty List\n");
        return;
    } 
    if(pos < 1 || pos > PtrL->Last+1)
    { 
        printf("Invalid\n");
        return;
    } 
    for(j = pos-1;j <= PtrL->Last; j++) 
        PtrL->Data[j] = PtrL->Data[j+1];
    PtrL->Last--;
    return;
}

int main()
{
    int m;
    List L;
    L = MakeEmpty();
    Insert(2,1,L); //0
    Insert(5,2,L); //1
    Insert(4,3,L); //2
    m = Find(5,L);
    Delete(1,L);
    printf("%d \n",L->Data[1]);
    printf("%d \n",L->Last);
    printf("%d \n",m);
    printf("���");
    return 0;
}


