/*顺序存储实现的链表的插入和删除,承接"012-线性表及顺序存储"*/
#define ElementType int
#define MAXSIZE 10001
typedef struct LNode* List;
struct LNode{
    ElementType Data[MAXSIZE];
    int Last;
};

void Insert(ElementType X,int i,List PtrL){
    int j=0;

    /*参数2的i是在下标为i前一个位置插入一个元素,Last指向的是数组的最后一个元素*/
    if(PtrL->Last==MAXSIZE-1){
        printf("Full\n");
        return;
    }

    /*i<1说明想在0号元素之前插入;i>PtrL->Last+2说明想在PtrL->Last+2位置插入,跳过了一个*/
    if(i<1||i>PtrL->Last+2){
        printf("Wrong position\n");
        return;
    }

    /*从i-1开始向后移动*/
    for(j=PtrL->Last;j>=i-1;j--)
        PtrL->Data[j+1]=PtrL->Data[j];
    
    PtrL->Data[i-1]=X;
    PtrL->Last++;
    return;
}

/*删除的也是i的前一个元素*/
void Delete(int i,List PtrL){
    int j=0;
    if(i<1||i>PtrL->Last+1){
        printf("Wrong Position");
        return;
    }
    for(j=i;j<=PtrL->Last;j++)
        PtrL->Data[j-1]=PtrL->Data[j];
    PtrL->Last--;
    return;
}