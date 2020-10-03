/*顺序存储结构的线性表实现以及初始化和查找函数的实现*/
#include<stdlib.h>
#include<stdio.h>
#define ElementType int
#define MAXSIZE 10001

typedef struct LNode* List;
struct LNode{
    ElementType Data[MAXSIZE];
    int Last;
};
struct LNode L;
List PtrL;

/*初始化:建立一个空表*/
List MakeEmpty(){
    List PtrL;
    PtrL=(List)malloc(sizeof(struct LNode));
    PtrL->Last=-1;
    return PtrL;
}

/*查找*/
int Find(ElementType X,List PtrL){
    int i=0;
    while(i<PtrL->Last&&PtrL->Data[i]!=X)
        i++;
    if(i>PtrL->Last)
        return -1;
    else
        return i;
}