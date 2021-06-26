#include <stdio.h>
#include <stdlib.h>

// 双向链表结构体
typedef struct dNode
{
    struct dNode *prior; //指向前驱结点的指针
    int data;            //数据域
    struct dNode *next;  //指向后继结点的指针
} dnode;

dnode *initDLink();
void initData(dnode *);
void displayDLink(dnode *);
void insertElem(dnode *, int, int);
void delElem(dnode *, int);
int selectElem(dnode *, int);
void updateElem(dnode *, int, int);

int main()
{
    dnode *dlink = initDLink();
    initData(dlink);
    displayDLink(dlink);
    insertElem(dlink, 1000, 0);
    insertElem(dlink, 1000, 4);
    insertElem(dlink, 1000, 6);
    delElem(dlink, 1000);
    delElem(dlink, 10);
    delElem(dlink, 90);
    printf("index = %d\n", selectElem(dlink, 1000));
    printf("index = %d\n", selectElem(dlink, 40));
    displayDLink(dlink);
    updateElem(dlink, 3, 999);
    return 0;
}

// 初始化双向链表
dnode *initDLink()
{
    dnode *head = (dnode *)malloc(sizeof(dnode));

    head->data = 0;
    head->next = NULL;
    head->prior = NULL;

    return head;
}

// 给双向链表初始化数据
void initData(dnode *d)
{
    dnode *temp = d;
    for (size_t i = 0; i < 10; i++)
    {
        //创建新的节点并初始化
        dnode *newNode = (dnode *)malloc(sizeof(dnode));
        newNode->prior = NULL;
        newNode->data = i * 10;
        newNode->next = NULL;
        //新节点与链表最后一个节点建立关系
        temp->next = newNode;
        newNode->prior = temp;
        //temp永远指向链表中最后一个节点
        temp = temp->next;
    }
}

void displayDLink(dnode *d)
{
    printf("输出双向链表：");
    dnode *temp = d;
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}

void insertElem(dnode *d, int elem, int index)
{
    printf("在下标%d处插入元素%d", index, elem);
    dnode *newNode = (dnode *)malloc(sizeof(dnode));
    newNode->next = NULL;
    newNode->data = elem;
    newNode->prior = NULL;

    if (index == 0)
    {
        // newNode->next = d->next;
        // d->prior = newNode;
        // d->next = newNode;
        newNode->next = d->next;
        d->next->prior = newNode;
        d->next = newNode;
        newNode->prior = d;
    }
    else
    {
        dnode *temp = d;
        for (size_t i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            newNode->next = NULL;
            temp->next = newNode;
            newNode->prior = temp;
        }
        else
        {
            newNode->next = temp->next;
            temp->next->prior = newNode;
            //
            temp->next = newNode;
            newNode->prior = temp;
        }
    }
    //输出
    displayDLink(d);
}

void delElem(dnode *d, int data)
{
    printf("删除数据为%d元素", data);
    //
    dnode *temp = d;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (temp->data == data)
        {
            if (temp->prior != NULL && temp->next != NULL)
            {
                temp->prior->next = temp->next;
                temp->next->prior = temp->prior;
            }
            else
            {
                temp->prior->next = NULL;
            }
            free(temp);
            //输出
            displayDLink(d);
            return;
        }
    }
    printf(" 链表中无该数据元素\n");
}

int selectElem(dnode *d, int elem)
{
    printf("查找元素%d的索引：", elem);

    int index = 0;
    dnode *temp = d;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (temp->data == elem)
        {
            return index;
        }
        index++;
    }

    return -1;
}

void updateElem(dnode *d, int index, int elem)
{
    int i = 0;
    dnode *temp = d;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (i == index)
        {
            temp->data = elem;
            displayDLink(d);
            return;
        }
        i++;
    }
}
