#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3
//srand(time(NULL));
/*
int a[N];

void gen_random(int upper_bound)
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound;
}

int howmany(int value)
{
	int count = 0, i;
	for (i = 0; i < N; i++)
		if (a[i] == value)
			++count;
	return count;
}

int main(void)
{
	int i,j, histogram[10] = {0};

	gen_random(10);
    for (i = 0; i < N; i++)
		histogram[a[i]]++;
    int max=0;
	for (i = 0; i < 10; i++)
    {
        for(j=0;j<10;j++)
        {
            if(histogram[i]<histogram[j]&&histogram[j]>max)
            {
                max = histogram[j];
            }
        }
    }
	for(i = max; i > 0 ; i--)
    {
        for(j=0;j<10;j++)
        {
            if(histogram[j]>=max-i)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
    */
int a[N]={1,2,3};
int num(int i)
{

    printf("%d ",a[i]);
    if(i+2>=N)
    {
        printf("%d ",a[i+2-N]);
    }
    else
    {
        printf("%d ",a[i+2]);
    }
    if(i+1>=N)
    {
        printf("%d ",a[i+1-N]);
    }
    else
    {
    printf("%d ",a[i+1]);
    }
}
int main(void)
{
    int i;
    for(i=0;i<N;i++)
    {
        num(i);
        printf("\n");
    }
    return 0;
}