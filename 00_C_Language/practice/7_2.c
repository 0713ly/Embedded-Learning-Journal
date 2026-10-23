//打印复数，格式为：x+iy。
#include <stdio.h>
#include <math.h>

struct complex_struct{
    double x,y;
};

double real_part(struct complex_struct z)
{
    return z.x;
}

double imag_part(struct complex_struct z)
{
    return z.y;
}

int main(void)
{
    struct complex_struct z;
    printf("请输入复数的实部和虚部：");
    scanf("%lf %lf",&z.x,&z.y);
    if(z.x==0)
    {
        printf("复数为：%.2fi\n",imag_part(z));
        return 0;
    }
    else 
    {
        if(z.y>0)
        {
            printf("复数为：%.2f+%.2fi\n",real_part(z),imag_part(z));
        }
        else if(z.y<0)
        {
            printf("复数为：%.2f%.2fi\n",real_part(z),imag_part(z));
        }
        else
        {
            printf("复数为：%.2f\n",real_part(z));
        }
    }

}