/*线性表的链式存储实现及查找*/
#define ElementType int
#include<stdlib.h>
#include<stdio.h>

typedef struct LNode* List;
struct LNode{
    ElementType Data;
    List Next;
};
struct LNode L;
List PtrL;

/*按序号查找*/
List FindKth(int K,List PtrL){
    List p=PtrL;
    int i=0;
    while(p!=NULL&&i<K){
        p=p->Next;
        i++;
    }
    if(i==K)
        return p;
    else
        return NULL;
}

/*按值查找*/
List Find(ElementType X,List PtrL){
    List p=PtrL;
    while(p!=NULL&&p->Data!=X)
        p=p->Next;
    return p;
}

/*求表长*/
int Length(List PtrL){
    int j=0;
    List p=PtrL;
    while(p){
        p=p->Next;
        j++;
    }
    return j;
}