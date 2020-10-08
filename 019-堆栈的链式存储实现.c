#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#define ElementType int
#define ERROR -1
#define bool _Bool

typedef struct SNode* Stack;
struct SNode{
    ElementType Data;
    struct SNode* Next;
};

bool IsEmpty(Stack S){
    return (S->Next==NULL);
}

Stack CreateStack(){
    Stack S;
    S=(Stack)malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}

/*插入和删除只能在头节点进行,若在尾部删除,就找不到前驱作为Top了*/
void Push(ElementType item,Stack S){
    struct SNode* TmpCell;
    TmpCell=(struct SNode*)malloc(sizeof(struct SNode));
    TmpCell->Data=item;
    /*S是一个空结点,S->Next才是栈顶(链表的第一个元素)*/
    TmpCell->Next=S->Next;
    S->Next=TmpCell;
    return;
}

ElementType Pop(Stack S){
    struct SNode* FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("Stack is empty\n");
        return ERROR;
    }
    else{
        FirstCell=S->Next;
        S->Next=FirstCell->Next;
        TopElem=FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}