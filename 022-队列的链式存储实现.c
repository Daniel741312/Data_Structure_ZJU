#include<stdlib.h>
#include<stdio.h>
#define ElementType int
#define ERROR -1

struct Node{
    ElementType Data;
    struct Node* Next;
};

struct QNode{
    struct Node* rear;
    struct Node* front;
};
typedef struct QNode* Queue;

/*出队*/
ElementType DeleteQ(Queue PtrQ){
    struct Node* FrontCell;
    ElementType FrontElem;
    if(PtrQ->front==NULL){
        printf("Queue is empty\n");
        return ERROR;
    }
    FrontCell=PtrQ->front;
    if(PtrQ->front==PtrQ->rear)
        PtrQ->front=PtrQ->rear=NULL;
    else
        PtrQ->front=PtrQ->front->Next;
    FrontElem=FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}