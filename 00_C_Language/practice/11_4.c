#include <stdio.h>

// 为了配合图片中 quicksort 的签名，我们使用全局数组
int a[] = { 10, 5, 8, 2, 7, 3, 9, 1, 6, 4 };
int LEN = sizeof(a) / sizeof(a[0]);

// 补全的 partition 函数
int partition(int start, int end)
{
    // 1. 选取 a[start] 作为基准值，把它“挖”出来，留出一个坑
    int pivot = a[start]; 
    int i = start;
    int j = end;

    while (i < j) {
        // 2. 从右向左找小于 pivot 的数
        // 只要 a[j] 大于等于 pivot，就继续往左挪
        while (i < j && a[j] >= pivot) {
            j--;
        }
        // 找到后，把 a[j] 填入左边的坑 a[i] 中，此时 a[j] 变成新坑
        if (i < j) {
            a[i] = a[j];
            i++; 
        }

        // 3. 从左向右找大于 pivot 的数
        // 只要 a[i] 小于等于 pivot，就继续往右挪
        while (i < j && a[i] <= pivot) {
            i++;
        }
        // 找到后，把 a[i] 填入右边的坑 a[j] 中，此时 a[i] 变成新坑
        if (i < j) {
            a[j] = a[i];
            j--;
        }
    }
    
    // 4. 循环结束时 i == j，把基准值填回最后的坑里
    a[i] = pivot;
    
    // 返回基准值的最终位置
    return i; 
}

void quicksort(int start, int end)
{
    int mid;
    if (start < end) {
        // 获取基准值的位置，此时数组被分为比它小和比它大的两半
        mid = partition(start, end);
        
        // 递归排序左半部分
        quicksort(start, mid - 1);
        // 递归排序右半部分
        quicksort(mid + 1, end);
    }
}

int main(void)
{
    int i;
    printf("排序前: ");
    for (i = 0; i < LEN; i++) printf("%d ", a[i]);
    printf("\n");

    quicksort(0, LEN - 1);

    printf("排序后: ");
    for (i = 0; i < LEN; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}