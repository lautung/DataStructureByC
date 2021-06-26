#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int data;          //数据域
    struct Link *next; // 指向下一个节点的指针变量
} link;

link *initLink();
void initData(link *);
void displayLink(link *);
void insertLink(link *l, int elem, int index);
void delElem(link *l, int index);
int selectIndex(link *l, int elem);
void updateElem(link *l, int newElem, int index);

int main()
{
    link *myLink = initLink();
    initData(myLink);
    displayLink(myLink);
    insertLink(myLink, 1000, 4);
    insertLink(myLink, 1000, 10);
    displayLink(myLink);
    delElem(myLink, 5);
    displayLink(myLink);

    printf("index: %d", selectIndex(myLink, 1000));

    updateElem(myLink, 999, 4);
    displayLink(myLink);
    return 1;
}

link *initLink()
{
    printf("创建链表\n");
    link *p = NULL;                            //头指针
    link *node = (link *)malloc(sizeof(link)); //首元节点

    //初始化首元节点
    node->data = 0;
    node->next = NULL;

    p = node; //使得头指针指向首元节点

    return p; //返回头指针
}

void initData(link *l)
{
    printf("初始化数据\n");
    link *temp = l;
    for (size_t i = 0; i < 50; i += 2)
    {
        // 创建新节点
        link *node = (link *)malloc(sizeof(link));
        node->data = i;
        node->next = NULL;
        // 使得头指针指向下一个节点。
        temp->next = node;

        temp = temp->next;
    }
}

void displayLink(link *l)
{
    printf("输出链表\n");
    link *temp = l;
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}

void insertLink(link *l, int elem, int index)
{
    link *temp = l;
    for (size_t i = 0; i < index; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("插入位置无效！");
        }
    }

    // 创建新的节点
    link *newNode = (link *)malloc(sizeof(link));
    newNode->data = elem;
    newNode->next = temp->next;
    //
    temp->next = newNode;
}

void delElem(link *l, int index)
{
    printf("执行 delElem(link *l, int index):void 函数，参数为 %d,%d\n", l, index);
    link *temp = l;
    for (size_t i = 0; i < index; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("无节点");
        }
    }

    link *indexNode = temp->next;  //单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next; //删除某个结点的方法就是更改前一个结点的指针域
    free(indexNode);               //手动释放该结点，防止内存泄漏
}

int selectIndex(link *l, int elem)
{
    link *temp = l;
    int index = 0;
    while (temp != NULL)
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

void updateElem(link *l, int newElem, int index)
{
    printf("执行 updateElem(link *l, int newElem, int index):void,参数为 %p,%d,%d", l, newElem, index);
    link *temp = l;
    for (size_t i = 0; i <= index; i++)
    {
        temp = temp->next;
    }

    temp->data = newElem;
}
