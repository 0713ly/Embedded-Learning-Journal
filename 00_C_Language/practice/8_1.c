//编写一个程序，定义两个类型和长度都相同的数组，将其中一个数组的所有元素拷贝给另一个。
#include<stdio.h>
int a[4] = {1,2,3,4};
int b[4];
int main(void)
{
    for(int i =0;i<4;i++)
    {
        b[i]=a[i];
        printf("b[%d]=%d ",i,b[i]);
    }
    return 0;
}