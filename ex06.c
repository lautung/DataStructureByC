#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prior;
    int data;
    struct Node *next;
} node;

node *initLink();
void initData(node *, int);
void displayLink(node *);

int main()
{
    int num = 0;
    scanf("%d", &num);
    node *myLink = initLink();
    initData(myLink, num);
    displayLink(myLink);
    return -1;
}

node *initLink()
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 0;
    head->next = NULL;
    head->prior = NULL;
    return head;
}

void initData(node *head, int num)
{
    node *temp = head;
    for (size_t i = 0; i < num; i++)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = i * 10;
        newNode->next = NULL;
        newNode->prior = NULL;
        //
        temp->next = newNode;
        newNode->prior = temp;
        temp = temp->next;
    }
    //连接首尾，实现闭环，完成双向循环链表
    temp->next = head->next;
    head->next->prior = temp;
}

void displayLink(node *head)
{
    node *temp = head;
    do
    {
        temp = temp->next;
        printf("%d --> ", temp->data);
    } while (temp->next != head->next);

    printf("%d", head->next->data);
    printf("\n");
}