/*链表的插入和删除,在第i个元素之前插入元素*/

/*插入*/
List Insert(ElementType X,int i,List PtrL){
    List p,s;
    if(i==1){
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=PtrL;
        return s;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("Error\n");
        return NULL;
    }
    else{
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=p->Next;
        p->Next=s;
        return PtrL;
    }
}

/*删除(没太懂)*/
List Delete(int i,List PtrL){
    List p,s;
    if(i==1){
        s=PtrL;
        if(PtrL!=NULL)
            PtrL=PtrL->Next;
        else
            return NULL;
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("第%d个结点不存在\n",i-1);
        return NULL;
    }
    else if(p->Next==NULL){
        printf("第%d个结点不存在\n",i);
        return NULL;
    }
    else{
        s=p->Next;
        p->Next=s->Next;
        free(s);
        return PtrL;
    }
}