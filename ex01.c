#include <stdio.h>
#include <stdlib.h>

typedef struct Table
{
    int *head;  //声明了一个名为head的长度不确定的数组，也叫“动态数组”
    int length; //记录当前顺序表的长度
    int size;   //记录顺序表分配的存储容量
} table;

table initTable(int);
void displayTable(table);
table addTable(table t, int elem, int index);

int main()
{
    table t = initTable(5);
    for (size_t i = 0; i < 5; i++)
    {
        t.head[i] = i;
        t.length++;
    }
    printf("输出顺序表元素\n");
    displayTable(t);


    printf("addTable(t,100,0);\n");
    table t1 = addTable(t,100,0);
    printf("输出顺序表元素\n");
    displayTable(t1);

    printf("addTable(t1,101,2);\n");
    table t2 = addTable(t1,101,2);
    printf("输出顺序表元素\n");
    displayTable(t2);

    printf("addTable(t2,102,t2.length);\n");
    table t3 = addTable(t2,102,t2.length);
    printf("输出顺序表元素\n");
    displayTable(t3);
    return 1;
}

table initTable(int size)
{
    table t;
    t.head = (int *)malloc(size * sizeof(int));
    if (!t.head)
    {
        printf("初始化失败");
        exit(0);
    }
    t.length = 0;
    t.size = size;
    return t;
}

//输出顺序表中元素的函数
void displayTable(table t)
{
    for (int i = 0; i < t.length; i++)
    {
        printf("%d ", t.head[i]);
    }
    printf("【%d,%d】",t.length,t.size);
    printf("\n");
}

// 插入函数，t 顺序表 ；elem 元素 ； index 索引 以 0 开头。
table addTable(table t, int elem, int index)
{
    //判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者插入的位置本身不存在，程序作为提示并自动退出）
    if (index > t.length + 1 || index < 0)
    {
        printf("插入位置有问题\n");
        return t;
    }

    //做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
    if(t.length == t.size){
        t.head = (int *)realloc(t.head,(t.size+1)*sizeof(int));
        if (!t.head)
        {
            printf("存储内存分配失败\n");
            return t;
        }
        t.size+=1;
    }

    //插入操作，需要将从插入位置开始的后续元素，逐个后移
    for (int i = t.length-1; i >= index; i--)
    {
        t.head[i+1] = t.head[i];
    }

    //后移完成，插入元素
    t.head[index] = elem;
    t.length++;
    return t;
    
}