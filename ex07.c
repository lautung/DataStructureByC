#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *data;
    int top;
    int bottom;
    int capacity;
} stack;

stack *initStack(int num);
void push(stack *myStack, int elem);
int pop(stack *myStack);
void display(stack *myStack);

int main()
{
    printf("输入需要创建栈的大小：");
    int num = 0;
    scanf("%d", &num);
    stack *myStack = initStack(num);
    for (size_t i = 0; i < num; i++)
    {
        push(myStack, i * 10);
    }
    display(myStack);

    //
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    display(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    return -1;
}

stack *initStack(int num)
{
    stack *myStack = (stack *)malloc(sizeof(stack));
    myStack->bottom = -1;
    myStack->top = -1;
    myStack->capacity = num;
    myStack->data = (int *)malloc(sizeof(int) * myStack->capacity);
    return myStack;
}

void push(stack *myStack, int elem)
{
    if (myStack->top != myStack->capacity)
    {
        myStack->top++;
        (myStack->data)[myStack->top] = elem;
    }
    else
    {
        printf("栈已满！！");
    }
}

int pop(stack *myStack)
{

    if (myStack->bottom == myStack->top)
    {
        printf("这是一个空栈");
        return -1;
    }

    int i = (myStack->data)[myStack->top];
    printf("弹栈的元素是：%d\n", i);
    myStack->top--;
    return i;
}

void display(stack *myStack)
{
    if (myStack->bottom == myStack->top)
    {
        printf("这是一个空栈");
        return;
    }

    printf("输出栈的元素：");

    for (size_t i = 0; i <= myStack->top; i++)
    {
        printf("%d ", (myStack->data)[i]);
    }

    printf("\n");
}
