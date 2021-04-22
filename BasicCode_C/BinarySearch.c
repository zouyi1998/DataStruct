#include <stdio.h>

#define max_size 10
#define NotFound -1
//二分查找
//时间复杂度O(log(n))
int BinarySearch(int x, int *a){
    int left, right, mid;
    left = 0;
    right = max_size-1;
    while(left <= right)
    {
        mid = (left+right)/2;
        if(x > *(a+mid))
            left = mid+1;
        else if (x < *(a+mid))
            right = mid-1;
        else 
            return mid;
    }
    return NotFound;
}

int main(){
    int a[max_size];
    int i, out;
    int *p;
    for(i=0;i<max_size;i++)
        a[i] = i;
    p = &a[0]; //指向数组首地址
    out = BinarySearch(9, p);
    if(out == NotFound)
        printf("Not Found");
    else
        printf("%d", out);
    return 0;
}