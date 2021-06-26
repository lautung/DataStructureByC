#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int rear;
    int front;
    int capacity;
} queue;

queue *initQueue(int num);
void initData(queue *q, int num);
void displayQueue(queue *q);
void enQueue(queue *q, int elem);
int deQueue(queue *q);

int main()
{
    queue *myQueue = initQueue(10);
    initData(myQueue, 5);
    displayQueue(myQueue);
    enQueue(myQueue, 1000);
    enQueue(myQueue, 1000);
    enQueue(myQueue, 1000);
    enQueue(myQueue, 1000);
    enQueue(myQueue, 1000);
    displayQueue(myQueue);
    printf("出队元素：%d\n", deQueue(myQueue));
    printf("出队元素：%d\n", deQueue(myQueue));
    printf("出队元素：%d\n", deQueue(myQueue));
    displayQueue(myQueue);
    return 0;
}

queue *initQueue(int num)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = num;
    q->data = (int *)malloc(sizeof(int) * q->capacity);
    q->front = 0;
    q->rear = 0;
    return q;
}

void initData(queue *q, int num)
{

    if (num > q->capacity)
    {
        printf("注意，输入的参数不能大于队列的最大容量！");
    }

    for (size_t i = 0; i < num; i++)
    {
        *((q->data) + q->rear) = i * 10;
        q->rear++;
    }
}

void enQueue(queue *q, int elem)
{
    printf("入队元素：%d\n", elem);
    if (q->rear - q->front == q->capacity)
    {
        printf("栈已满");
    }

    *(q->data + q->rear) = elem;
    q->rear++;
}

int deQueue(queue *q)
{
    if (q->front >= q->rear)
    {
        return -1;
        printf("栈空");
    }
    int i = *(q->data + q->front);
    q->front++;
    printf("");
    return i;
}

void displayQueue(queue *q)
{
    printf("输出队列：");
    int *data = q->data;
    int top = q->front;
    int rear = q->rear;
    while (top != rear)
    {
        printf("%d ", *(data + top));
        top++;
    }
    printf("\n");
}