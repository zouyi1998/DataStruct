#include <stdio.h>
#include <stdlib.h>
#define max_size 2000
#define Null -1

typedef struct TreeNode *PtrT;
struct TreeNode
{
    int left, right;
};

int queue[max_size];
int front, rear;

struct TreeNode tree[max_size];

int FindNext(int *a, int start, int end)
{
    int lower_bound, upper_bound, i, length, root;
    i = 0;
    lower_bound = 0;
    upper_bound = (lower_bound + 1) * 2 - 1;
    length = end - start + 1;
    if (length >= 2)
    {
        while (1)
        {
            if (length - 1 >= lower_bound * 2 && length - 1 < 2 * upper_bound)
            {
                if (length - 1 == 2 * lower_bound)
                {
                    root = a[start + lower_bound];
                    tree[root].left = Null;
                    tree[root].right = Null;
                    tree[root].left = FindNext(a, start, start + lower_bound - 1);
                    tree[root].right = FindNext(a, start + lower_bound + 1, end);
                    return root;
                }
                else if (length - 1 - lower_bound <= upper_bound)
                {
                    root = a[end - lower_bound];
                    tree[root].left = Null;
                    tree[root].right = Null;
                    tree[root].left = FindNext(a, start, end - lower_bound - 1);
                    tree[root].right = FindNext(a, end - lower_bound + 1, end);
                    return root;
                }
                else if (length - 1 - upper_bound > lower_bound)
                {
                    root = a[start + upper_bound];
                    tree[root].left = Null;
                    tree[root].right = Null;
                    tree[root].left = FindNext(a, start, start + upper_bound - 1);
                    tree[root].right = FindNext(a, start + upper_bound + 1, end);
                    return root;
                }
            }
            else
            {
                i = i + 1;
                lower_bound = 2 * (lower_bound + 1) - 1; //2^i-1
                upper_bound = (lower_bound + 1) * 2 - 1; //2^(i+1)-1
            }
        }
    }
    else if (length == 1)
    {
        root = a[start];
        tree[root].left = Null;
        tree[root].right = Null;
        return root;
    }
    else
        return Null;
}

void sort(int *a, int N)
{
    int i, j, temp;
    for (i = 1; i < N; i++)
    {
        temp = a[i];
        for (j = i; j >= 1 && a[j - 1] > temp; j--)
            a[j] = a[j - 1];
        a[j] = temp;
    }
    return;
}

void LevelOrderTraversal(int root, int N)
{
    int cnt, cur;
    cnt = 0;
    front = rear = -1;
    if (root != Null)
    {
        queue[++rear] = root;
        while (front != rear)
        {
            cur = queue[++front];
            cnt++;
            if (cnt != N)
                printf("%d ", cur);
            else
                printf("%d", cur);
            if (tree[cur].left != Null)
                queue[++rear] = tree[cur].left;
            if (tree[cur].right != Null)
                queue[++rear] = tree[cur].right;
        }
    }
    return ;
}

int main()
{
    int N, i, root;
    int a[max_size];
    int *p;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    p = &a[0];
    sort(p, N);
    root = FindNext(p, 0, N - 1);
    LevelOrderTraversal(root, N);
    return 0;
}