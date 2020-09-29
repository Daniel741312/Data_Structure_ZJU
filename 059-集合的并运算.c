/*
    *集合的并运算(相关的定义在"058-集合的表示及查找"里面):
    *1.分别找到X1和X2两个元素所在集合树的根节点
    *2.若他们是不同根的,则将其中一个根节点的父结点指针设置为另一个根节点的数组下标
    *3.当然这样会导致集合树越来越高
*/
void Union(SetType S[],ElementType X1,ElementType X2){
    int Root1=0;
    int Root2=0;
    Root1=Find(S,X1);
    Root2=Find(S,X1);
    if(Root1!=Root2)
        S[Root2].Parent=Root1;
    return;
}