#include <stdio.h>

#define max_size 10
//顺序查找
//时间复杂度O(n)
int SequentialSearch(int *a, int x){
    int i;
    *a = x; //设置哨兵
    a = a+max_size-1; //ָ从后往前找
    for(i = max_size-1; *a != x;i--)
        a = a-1;
    return i;
}

int main()
{
    int a[max_size];
    int i, out;
    int *p;
    for(i=1;i<max_size;i++) //a0不存数据，用作哨兵
        a[i] = i;
    p = &a[0]; //ָ指向数组首地址
    out = SequentialSearch(p, 0);
    if(out == 0)
        printf("Not Found");
    else
        printf("%d", out);
    return 0;
}