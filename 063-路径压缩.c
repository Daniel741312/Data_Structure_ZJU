/*
    *路径压缩算法通过一次递归极大地减小了树的高度,后面就很省力了
    *当然这么牛逼的算法在数据集很小的情况下是体现不出优越性的
    *路径压缩的思想:
        *先找到集合的根
        *把根变成X的父节点
        *再返回根
*/
#define MaxSize 1001
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];

SetName Find(SetType S,ElementType X){
    if(S[X]<0)
        return X;                   //递归终点:返回根节点
    else
        return S[X]=Find(S,S[X]);   //返回时会将调用者的父节点改为根节点
}