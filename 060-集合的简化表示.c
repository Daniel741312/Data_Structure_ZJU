/*
    *集合的简化表示:
    *任何有限集合的(N个)元素都可以被一一映射为整数0~N-1
    *用数组下标表示这个元素本身(如果是unsigned int就正好)
    *而数组中存的内容是他的双亲位置
*/

#define MaxSize 1000

SetName Find(SetType S,ElementType X);
void Union(SetType S,SetName Root1,SetName Root2);

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];
/*int SetType[1000]*/

SetName Find(SetType S,ElementType X){
    for(;S[X]>=0;X=S[X]);
    return X;
}

void Union(SetType S,SetName Root1,SetName Root2){
    S[Root2]=Root1;
    return;
}
