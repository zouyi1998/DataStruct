#include <stdio.h>

int main(){
    int N, input, max, sum, max_total, max_first, max_last, temp_first, temp_last; 
    int a1,aN;
    int   max_first_value, max_last_value, temp_first_value, temp_last_value;
    scanf("%d", &N);
    sum = 0; //当前子列和
    max = 0; //当前最大子列和
    max_total = 0; //最大子列和
    max_first = -1; //最大子列和起始下标
    max_last = -1; //最大子列和结束下标
    temp_first = -1; //当前最大子列和起始下标
    temp_last = -1; //当前最大子列和结束下标
    for(int i =0; i<N; i++)
    {
        scanf("%d", &input);
        if(i == 0) a1 = input;//记录第一个数
        if(i == N-1) aN = input;//记录最后一个数
        sum = sum + input;
        if(sum <0)
        {
            sum = 0;
            if(temp_first == -1) //寻找第一个不为零的输入
            {
                continue;
            }
            else if(temp_first != -1 && temp_last != -1)//有存下完整的最大子列
            {
                if(max_first == -1)//第一次无论如何存下来
                {
                    max_first = temp_first; 
                    max_last = temp_last;
                    max_total = max;
                    max_first_value = temp_first_value;
                    max_last_value = temp_last_value;
                }
                else if(max > max_total) //对比当前非零串与此前记录的最大值
                {
                    max_first = temp_first; 
                    max_last = temp_last;
                    max_total = max;
                    max_first_value = temp_first_value;
                    max_last_value = temp_last_value;
                }
            }
            else if(temp_first != -1 ){ //存下单个非零数
                if(max_first == -1)//第一次无论如何存下来
                {
                    max_first = temp_first; 
                    max_last = temp_first;
                    max_total = max;
                    max_first_value = temp_first_value;
                    max_last_value = temp_first_value;
                }
                else if(max > max_total) //对比当前非零串与此前记录的最大值
                {
                    max_first = temp_first; 
                    max_last = temp_first;
                    max_total = max;
                    max_first_value = temp_first_value;
                    max_last_value = temp_first_value;
                }
            }
            max = 0;  
            temp_first = temp_last = -1;
        }
        else if(sum >= max)
        {
            if(temp_first == -1) //寻找到第一个不为零的输入，更新temp_first
            {
                temp_first = i;
                temp_first_value = input;
            } 
            else 
            {
                if(temp_last == -1)
                {
                    temp_last = i;
                    temp_last_value = input; 
                    
                }
                else if(sum > max)
                {
                    temp_last_value = input;
                    temp_last = i;
                }
            }//寻找到当前非零串中的最大值，更新temp_last
            max = sum;
        }
        if(i == N-1 && temp_first != -1) //当处理到最后一项时也需要更新
        { 
            if(temp_last != -1)
            {
                if(max_first == -1)//第一次无论如何存下来
            {
                max_first = temp_first; 
                max_last = temp_last;
                max_total = max;
                max_first_value = temp_first_value;
                max_last_value = temp_last_value;
            }
            else if(max > max_total) //对比当前非零串与此前记录的最大值
            {
                max_first = temp_first; 
                max_last = temp_last;
                max_total = max;
                max_first_value = temp_first_value;
                max_last_value = temp_last_value;
            }
            }
             else{
             if(max_first == -1)//第一次无论如何存下来
                {
                    max_first = temp_first; 
                    max_last = temp_first;
                    max_total = max;
                    max_first_value = temp_first_value;
                    max_last_value = temp_first_value;
                }
                else if(max > max_total) //对比当前非零串与此前记录的最大值
                {
                    max_first = temp_first; 
                    max_last = temp_first;
                    max_total = max;
                    max_first_value = temp_first_value;
                    max_last_value = temp_first_value;
                }
            }   
        }
       
            
    }

    if(max_first == -1) //未更新过全局最大，也即未找到非零项
        printf("%d %d %d", 0, a1, aN);
    else
        printf("%d %d %d", max_total, max_first_value, max_last_value);
    return 0;
}