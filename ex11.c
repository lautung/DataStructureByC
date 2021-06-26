#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;

typedef struct LinkQueue
{
    struct QNode *rear;
    struct QNode *top;
    struct QNode *head;
} LinkQueue;

LinkQueue *initLinkQueue();
void enQueue(LinkQueue *lq, int data);
void deQueue(LinkQueue *lq);
void displayQueue(LinkQueue *lq);

int main()
{
    LinkQueue *myQueue = initLinkQueue();
    enQueue(myQueue, 1000);
    enQueue(myQueue, 1000);
    enQueue(myQueue, 1000);
    enQueue(myQueue, 1000);
    displayQueue(myQueue);
    return 0;
}

LinkQueue *initLinkQueue()
{
    QNode *q = (QNode *)malloc(sizeof(QNode));
    q->next = NULL;
    q->data = 0;
    //
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    queue->head = q;
    queue->rear = q;
    queue->top = q;
    return queue;
}

void enQueue(LinkQueue *lq, int data)
{
    QNode *rear = lq->rear;
    QNode *q = (QNode *)malloc(sizeof(QNode));
    q->next = NULL;
    q->data = data;
    //
    rear->next = q;
    rear = q;
}

void deQueue(LinkQueue *lq)
{
    QNode *top = lq->top;
    QNode *rear = lq->rear;
    QNode *head = lq->head;
    //
    if (top->next == NULL)
    {
        printf("队列为空");
        return;
    }

    QNode *temp = top;
    top = temp->next;
    head = temp->next;

    free(temp);
}

void displayQueue(LinkQueue *lq)
{

    LinkQueue *temp = (LinkQueue *)malloc(sizeof(LinkQueue));
    temp->head = lq->head;
    temp->rear = lq->rear;
    temp->top = lq->top;
    printf("输出队列：");
    while (temp->top->next != temp->rear)
    {
        temp->top = temp->top->next;
        printf(" %d", temp->top->data);
    }

    printf("\n");
}