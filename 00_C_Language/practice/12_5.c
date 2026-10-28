#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
#define MAX_QUEUE_SIZE 20 // 环形队列容量

// 1. 结构体精简：不需要记录前驱了，只存坐标
struct point { int row, col; };

// 定义环形队列和头尾指针
struct point queue[MAX_QUEUE_SIZE];
int head = 0;
int tail = 0;

// 判断队空
int is_empty(void) {
    return head == tail;
}

// 判断队满（保留一个空位来区分队空和队满）
int is_full(void) {
    return (tail + 1) % MAX_QUEUE_SIZE == head;
}

// 入队（核心：取模运算实现环绕）
void enqueue(struct point p) {
    if (is_full()) {
        printf("Queue is full!\n");
        return;
    }
    queue[tail] = p;
    tail = (tail + 1) % MAX_QUEUE_SIZE; // 指针到末尾就回到 0
}

// 出队（核心：取模运算实现环绕）
struct point dequeue(void) {
    struct point p = queue[head];
    head = (head + 1) % MAX_QUEUE_SIZE; // 指针到末尾就回到 0
    return p;
}

// 迷宫地图
int maze[MAX_ROW][MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

// 探索相邻点并入队
void visit(int row, int col) {
    struct point visit_point = { row, col };
    maze[row][col] = 2; // 标记为已走过
    enqueue(visit_point);
}

int main(void) {
    struct point p = { 0, 0 }; // 起点
    maze[p.row][p.col] = 2;    // 起点标记
    enqueue(p);                // 起点入队

    int found = 0; // 标记是否找到终点

    while (!is_empty()) {
        p = dequeue(); // 出队一个点

        // 如果这个点是终点
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
            found = 1;
            break;
        }

        // 探索右、下、左、上四个方向
        if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0)
            visit(p.row, p.col + 1);
        if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0)
            visit(p.row + 1, p.col);
        if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0)
            visit(p.row, p.col - 1);
        if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0)
            visit(p.row - 1, p.col);
    }

    // 输出结论
    if (found) {
        printf("Yes, path exists!\n");
    } else {
        printf("No path!\n");
    }

    return 0;
}