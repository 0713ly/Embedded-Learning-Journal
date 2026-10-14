# include <stdio.h>
int main(void)
{
int x = 17, n = 4;
printf("Ceiling of %d/%d is: %d\n", x, n, (x + n - 1) / n); // Êä³ö 5

x = 16;
printf("Ceiling of %d/%d is: %d\n", x, n, (x + n - 1) / n); // Êä³ö 4

return 0;
}