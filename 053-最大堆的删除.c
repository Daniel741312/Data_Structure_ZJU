#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MinData -10000
#define ElementType int
#define MinPQSize 2

typedef struct HeapStruct* MaxHeap;
struct HeapStruct{
    ElementType* Elements;
    int Size;
    int Capacity;
};

void sys_err(const char* str){
    printf(str);
    exit(1);
}
ElementType DeleteMin(MaxHeap H);
bool IsEmpty(MaxHeap H);

int main(){

    return 0;
}

/*最大堆的删除*/
ElementType DeleteMin(MaxHeap H){
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

        H->Elements[Parent]=temp;
    }
    return MaxItem;
}

bool IsEmpty(MaxHeap H){
    return false;
}