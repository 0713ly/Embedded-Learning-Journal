#include <stdio.h>
#include <stdlib.h>
#define N 25

int a[N];
void get_random(int upper_bound)
{
    int i,b;
    i=0;
    while(i<N)
    {
        b=rand()%upper_bound;
        if(b>10)
        {
            a[i]=b;
            i=i+1;
        }
       
    }
}
int main(void)
{
    get_random(20);
    for(int i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}