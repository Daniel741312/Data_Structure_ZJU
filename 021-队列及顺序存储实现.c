#include<stdio.h>
#define MaxSize 1001
#define ElementType int
#define ERROR -1

typedef struct QNode* Queue;
struct QNode{
    ElementType Data[MaxSize];
    int rear;
    int front;
};

/*入队*/
void AddQ(Queue PtrQ,ElementType item){
    if((PtrQ->rear+1)%MaxSize==PtrQ->front){
        printf("Queue is full\n");
        return;
    }
    PtrQ->rear=(PtrQ->rear+1)%MaxSize;
    PtrQ->Data[PtrQ->rear]=item;
    return;
}

/*出队*/
ElementType DeleteQ(Queue PtrQ){
    if(PtrQ->front==PtrQ->rear){
        printf("queue is empty\n");
        return ERROR;
    }
    else{
        PtrQ->front=(PtrQ->front+1)%MaxSize;
        return PtrQ->Data[PtrQ->front];
    }
}