#include <stdio.h>
#include <stdlib.h>

#define max_size 10
#define NotFound -1

typedef struct Set *PtrSet;
struct Set
{
    int data; //数据
    int root; //1. root指向父节点 2. root为负值时说明该节点为根节点 3.节点为根节点时，root的相反数为集合大小
};
//合并集合
void Union(int x, int y, PtrSet s)
{
    int p,q, sizep, sizeq;
    p = Find(x, s);
    q = Find(y, s);
    if(p == NotFound || q == NotFound)
        return;
    else
    {
        sizep = -s[p].root;
        sizeq = -s[q].root;
        if(sizep >= sizeq) //比较集合大小将小集合合并到大集合中
        {
            s[q].root = p;
            s[p].root = -(sizep+sizeq);
        }
        else
        {
            s[p].root = q;
            s[q].root = -(sizep+sizeq);
        }
        return;
    }
}
//查找x元素所在集合：也即查找根节点
int Find(int x, PtrSet s)
{
    int i;
    for (i = 0; i < max_size && s[i].data != x; i++)
        ;
    if (i != max_size)
    {
        for (; s[i].root >= 0; i = s[i].root)
            ;
        return i;
    }
    else
        return NotFound;
}

int main()
{
    return 0;
}