/*并查集问题*/
#define ElementType int
#define MaxSize 1000

/*
    *一个结构数组,每一个结构里包含一个数据域和一个Parent(指针)域
    *Parent指向他的父节点的数组下标
*/
typedef struct{
    ElementType Data;
    int Parent;
}SetType;

int Find(SetType S[],ElementType X);
void Union(SetType S[],ElementType X1,ElementType X2);

/*找到他的根节点*/
int Find(SetType S[],ElementType X){
    int i=0;
    /*先遍历这个结构数组,找到X的位置*/
    for(i=0;(i<MaxSize)&&(S[i].Data!=X);i++)
    if(i>=MaxSize)
        return -1;
    /*找到S[i]的父节点*/
    for(;S[i].Parent>=0;i=S[i].Parent);
    return i;
}