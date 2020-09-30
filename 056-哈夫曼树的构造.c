/*哈夫曼的构造*/

typedef struct TreeNode* HuffmanTree;
struct TreeNode{
    int Weight;
    HuffmanTree Left,Right;
};

HuffmanTree Huffman(MinHeap H){
    /*假设H->Size个权值已经存入H*/
    int i=0;
    HuffmanTree T;
    /*将H->Element[]按权值调为最小堆*/
    BuildMinHeap(H);
    for(i=1;i<H->Size;i++){
        T=malloc(sizeof(struct TreeNode));
        /*这里的DeleteMin返回的是MinHeap的结点*/
        T->Left=DeleteMin(H);
        T->Right=DeleteMin(H);
        T->Weight=T->Left->Weight+T->Right->Weight;
        Insert(H,T);
    }
    T=DeleteMin(H);
    return T;
}