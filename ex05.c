#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} person;

person *initLinkAndData(int number);
void displayLink(person *p);
void findAndKill(person *ptr, int k, int m);

int main()
{
    printf("请输入人数：");
    int number = 0;
    scanf("%d", &number);
    person *p = initLinkAndData(number);
    displayLink(p);
    findAndKill(p, 3, 2);
    return 0;
}

person *initLinkAndData(int number)
{
    person *ptr = (person *)malloc(sizeof(person));
    ptr->data = 0;
    ptr->next = NULL;
    //
    person *temp = ptr;
    for (size_t i = 1; i <= number; i++)
    {
        person *temp1 = (person *)malloc(sizeof(person));
        temp1->data = i;
        temp1->next = NULL;
        //
        temp->next = temp1;
        temp = temp->next;
    }

    temp->next = ptr->next;

    return ptr;
}

void displayLink(person *p)
{
    printf("输出双向列表：");
    person *temp = p;
    do
    {
        temp = temp->next;
        printf("%d --> ", temp->data);
    } while (p->next != temp->next);

    printf("%d \n", p->next->data);
}

void findAndKill(person *ptr, int k, int m)
{
    person *temp = ptr;
    //起始节点
    person *currentNode = temp->next;
    //找到编号为K的人
    while (temp->data != k)
    {
        temp = temp->next;
        currentNode = temp;
    }

    //从编号K开始计数。
    while (currentNode->next != currentNode)
    {
        // 从 1 开始计数，到 m 为止。
        for (size_t i = 1; i < m; i++)
        {
            temp = currentNode;
            currentNode = currentNode->next;
        }
        temp->next = currentNode->next;
        printf("出列人的编号为:%d\n", currentNode->data);
        free(currentNode);
        currentNode = temp->next;
    }
    printf("优胜者的编号为:%d\n", currentNode->data);
    free(currentNode);
}