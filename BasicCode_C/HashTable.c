#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MinTableSize 0
#define max_size 100
#define NotFound -1

typedef struct Cell *PtrC;
struct Cell
{
    int key;
    bool info;    //是否占用
    bool deleted; //是否删除过
};

typedef struct HashTable *PtrH;
struct HashTable
{
    int TableSize;
    PtrC TheCells;
};

//寻找下一个质数
int NextPrime(int TableSize)
{
    int i, j, flag;
    for (i = TableSize;; i++)
    {
        flag = 1;
        for (j = 2; j <= sqrt(TableSize); j++)
            if (!(i % j))
            {
                flag = 0;
                break;
            }
        if (flag)
            break;
    }
    return i;
}
//初始化哈希表：
PtrH InitHash(int TableSize)
{
    PtrH H;
    int i;
    if (TableSize < MinTableSize) //检查TableSize是否小于最小要求
        return NULL;
    H = (PtrH)malloc(sizeof(struct HashTable));
    H->TableSize = NextPrime(TableSize);
    H->TheCells = (PtrC)malloc(sizeof(struct Cell) * H->TableSize);
    //初始化info, deleted
    for (i = 0; i < H->TableSize; i++)
    {
        H->TheCells[i].info = false;
        H->TheCells[i].deleted = false;
    }
    return H;
}
//散列函数
int Hash(int key, int TableSize)
{
    return key % TableSize;
}
//查找:
int FindHash(int key, PtrH H)
{
    int pos0, pos;
    int Cnum = 0;
    pos0 = Hash(key, H->TableSize);
    pos = pos0;
    while (H->TheCells[pos].info && H->TheCells[pos].key != key) //不为空且不等于key
    {
        //平方探测:相对于初始位置变化
        if (Cnum % 2)
            pos = pos0 - (Cnum / 2 + 1) * (Cnum / 2 + 1); //Cnum为奇数时，减
        else
            pos = pos0 + (Cnum / 2 + 1) * (Cnum / 2 + 1); //Cnum为侯树时，加
        //调整位置到0到TableSize-1之间
        while (pos >= H->TableSize)
            pos -= H->TableSize;
        while (pos < 0)
            pos += H->TableSize;
        Cnum++;
    }
    if (H->TheCells[pos].info)
        return pos;
    else
        return NotFound;
}

//插入
void InsertHash(int key, PtrH H)
{
    int pos0, pos, Cnum;
    pos0 = Hash(key, H->TableSize);
    pos = pos0;
    Cnum = 0;
    while (1)
    {
        if (!H->TheCells[pos].info)
        {
            H->TheCells[pos].key = key;
            H->TheCells[pos].info = true;
            break;
        }
        else if (H->TheCells[pos].deleted)
        {
            H->TheCells[pos].key = key;
            H->TheCells[pos].deleted = false;
            break;
        }
        //平方探测
        if (Cnum % 2)
            pos = pos0 - (Cnum / 2 + 1) * (Cnum / 2 + 1); //Cnum为奇数时，减
        else
            pos = pos0 + (Cnum / 2 + 1) * (Cnum / 2 + 1); //Cnum为侯树时，加
        //调整位置到0到TableSize-1之间
        while (pos >= H->TableSize)
            pos -= H->TableSize;
        while (pos < 0)
            pos += H->TableSize;
        Cnum++;
    }
}

//删除
void DeletedHash(int key, PtrH H)
{
    int pos;
    pos = FindHash(key, H);
    if (pos == NotFound)
        return;
    else if (!H->TheCells[pos].deleted)
    {
        H->TheCells[pos].deleted = true;
        return;
    }
}
int main()
{
    PtrH H;
    int i, N, pos;
    int a[9] = {47, 7, 29, 11, 9, 84, 54, 20, 30};
    N = 9;
    H = InitHash(N);
    for(i=0;i<N;i++)
        InsertHash(a[i], H);
    for(i=0;i<N;i++)
        printf("%d ", FindHash(a[i], H));
    return 0;
}