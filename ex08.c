#include <stdio.h>
#include <stdlib.h>
// 节点结构体
typedef struct Node
{
    int data;
    struct Node *next;
} node;

// 栈
typedef struct Stack
{
    node *link;
    int top;
} stack;

stack *initStack();
void push(stack *myStack, int elem);
int pop(stack *myStack);
void diaplay(stack *myStack);

int main()
{
    stack *myStack = initStack();
    for (size_t i = 0; i < 10; i++)
    {
        push(myStack, i * 10);
    }

    diaplay(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    diaplay(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    diaplay(myStack);
    return 0;
}

stack *initStack()
{
    stack *myStack = (stack *)malloc(sizeof(stack));
    node *stackNode = (node *)malloc(sizeof(node));
    stackNode->data = 0;
    stackNode->next = NULL;
    myStack->link = stackNode;
    myStack->top = -1;
    return myStack;
}

void push(stack *myStack, int elem)
{
    myStack->top++;
    node *stackNode = (node *)malloc(sizeof(node));
    stackNode->data = elem;
    stackNode->next = myStack->link->next;
    myStack->link->next = stackNode;
}

int pop(stack *myStack)
{

    if (myStack->link->next == NULL)
    {
        printf("空栈\n");
        return -1;
    }

    int i = myStack->link->data;
    myStack->link->next = myStack->link->next->next;
    myStack->top--;
    return i;
}

void diaplay(stack *myStack)
{
    printf("打印链栈元素：");

    if (myStack->link->next == NULL)
    {
        printf("空栈\n");
        return;
    }

    node *temp = myStack->link;
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}