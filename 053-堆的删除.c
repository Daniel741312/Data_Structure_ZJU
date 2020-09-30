/*最大堆的删除*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MaxData 10001
#define ElementType int
#define MinPQSize 2

/*定义一个最大堆*/
typedef struct HeapStruct* MaxHeap;
struct HeapStruct{
    ElementType* Elements;
    int Size;
    int Capacity;
};

void sys_err(const char* str);
ElementType DeleteMax(MaxHeap H);
bool IsEmpty(MaxHeap H);

/*错误处理函数*/
void sys_err(const char* str){
    printf(str);
    exit(1);
}

/*最大堆的删除*/
ElementType DeleteMax(MaxHeap H){
    int Parent,Child;
    ElementType MaxItem,temp;
    if(IsEmpty(H))
        sys_err("Empty");
    MaxItem=H->Elements[1];

    temp=H->Elements[H->Size--];
    for(Parent=1;Parent*2<=H->Size;Parent=Child){
        Child=Parent*2;
        if((Child!=H->Size)&&(H->Elements[Child]<H->Elements[Child+1]))
            Child++;
        if(temp>=H->Elements[Child])
            break;
        else
            H->Elements[Parent]=H->Elements[Child];
    }
    /*从循环跳出来,找到了合适的Parent位置*/

    H->Elements[Parent]=temp;
    return MaxItem;
}

bool IsEmpty(MaxHeap H){
    return false;
}