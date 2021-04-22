#include <stdio.h>
#include <stdlib.h>

//线性表-链式存储
typedef struct LNode *List;
struct LNode{
    int data; 
    List next; 
}; 

//建立空表
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof( struct LNode));
    PtrL->data = 0;
    PtrL->next = NULL;
    return PtrL;
}

//返回长度
int Length(List PtrL)
{
    List p = PtrL;
    int l = 0;
    while(p) 
    {
        l++;
        p = p->next;
    }
    return l;
}

//找到第k个元素
List FindKth(int k,List PtrL)
{
    List p = PtrL; 
    int i = 1;
    while(p!=NULL && i<k)
    {
        p=p->next;
        i++;
    }
    if(i==k) return p;
    else return NULL;
}

//找到元素X
List Find(int x, List PtrL)
{
    List p = PtrL;
    while(p!=NULL && p->data!=x)
        p->next;
    return p;
}

//在i位置之后插入元素x
List Insert(int i, int x, List PtrL)
{
    List s;
    if(i == 0) 
    {
        s = (List)malloc(sizeof(struct LNode));
        s->data = x; 
        s->next = PtrL; 
        PtrL = s;  
        return PtrL;
    }
    List p = FindKth(i, PtrL);
    if(p == NULL)
    {
        printf("Cannot Find Kth");
        return PtrL;
    }
    else
    {   
        s = (List)malloc(sizeof(struct LNode));
        s->data = x; 
        s->next = p->next; 
        p->next = s; 
        return PtrL; 
    }
}

//删除链表第i个元素
List Delete(int i, List PtrL)
{
    List p, s; 
    if(i == 1) 
    {
        s = PtrL;
        if(PtrL!=NULL) 
            PtrL= PtrL->next;
        else
            return NULL;
        free(s);
        return PtrL; 
    }
    p = FindKth(i-1, PtrL);
    if(p!=NULL && p->next != NULL) 
    {
        s = p->next;
        p->next  = s->next; 
        free(s);
        return PtrL;
    }
    else
    {
        printf("Cannot Find Kth");
        return PtrL;
    }
}

//带头结点的链表的反转
List Reverse(List L)
{
    List new_head, old_head, temp;
    old_head = L->next; //若不带头结点，old_head = L;
    new_head = NULL;
    while(old_head)
    {
        temp = old_head->next;
        old_head->next = new_head;
        new_head = old_head;
        old_head = temp;
    }
    L->next = new_head; //若不带头结点 L = new_head;
    return L;
}

int main()
{
    int i;
    List L;
    L = MakeEmpty();
    for(i=1;i<=10;i++)
        L = Insert(i, i, L);
    L = Reverse(L);
    return 0;
}
