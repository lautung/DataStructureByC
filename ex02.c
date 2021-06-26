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
int selectTable(table t, int elem);
table updateTable(table t , int elem , int newElem);

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

    table  = updateTable(t,3,100);
    displayTable(t1); 

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
    printf("【%d,%d】", t.length, t.size);
    printf("\n");
}

//查找函数，其中，elem 表示要查找的数据元素的值
int selectTable(table t, int elem)
{
    for (size_t i = 0; i < t.length; i++)
    {
        if (t.head[i] == elem)
        {
            return i;
        }
    }
    // 返回 -1 表示未找到。
    return -1;
}

// t 顺序表 ； elem 旧元素 ； newElem 新元素；
table updateTable(table t , int elem , int newElem){
    int index = selectTable(t,elem);
    t.head[index] = newElem;
    return t;
}
