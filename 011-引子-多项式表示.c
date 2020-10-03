/*采用链表的形式存储多项式,一个系数,一个指数,一个指向下一个结点的指针*/
typedef struct PolyNode* Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial Next;
};