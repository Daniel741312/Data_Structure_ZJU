/*堆栈的顺序存储实现*/
#include<stdio.h>
#define ElementType int
#define MaxSize 1001
#define ERROR -1

typedef struct SNode* Stack;
struct SNode{
    ElementType Data[MaxSize];
    int Top;
};

void Push(Stack PtrS,ElementType item){
    if(PtrS->Top==MaxSize-1){
        printf("Stack is full");
        return;
    }
    else{
        PtrS->Data[++(PtrS->Top)]=item;
        return;
    }
}

ElementType Pop(Stack PtrS){
    if(PtrS->Top==-1){
        printf("Stack is empty");
        return ERROR;
    }
    else
        return (PtrS->Data[(PtrS->Top)--]);
}

/*用一个数组实现两个堆栈:分别从两边向中间生长,当两个栈顶指针相遇表示堆栈已满*/
struct DStack{
    ElementType Data[MaxSize];
    int Top1;
    int Top2;
}S;
S.Top1=-1;
S.Top2=MaxSize;

void Push(struct DStack* PtrS,ElementType item,int tag){
    if(PtrS->Top2-PtrS->Top1==1){
        printf("Stack is full");
        return;
    }
    if(Tag==1)
        PtrS->Data[++(PtrS->Top1)]=item;
    else
        PtrS->Data[--(PtrS->Top2)]=item;
    return;
}

ElementType Pop(struct DStack* PtrS,int Tag){
    if(Tag==1){
        if(PtrS->Top1==-1){
            printf("Stack1 is empty\n");
            return;
        }
        else
            return (PtrS->Data[(PtrS->Top1)--]);
    }
    else{
        if(PtrS->Top2==MaxSize){
            printf("Stack2 is empty\n");
            return;
        }
        else
            return (PtrS->Data[(PtrS->Top2)++]);
    }
}