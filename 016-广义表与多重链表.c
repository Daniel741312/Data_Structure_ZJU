/*广义表:通过union手段将数据域和子链指针域合并*/
#define ElementType int

typedef struct GNode* GList;
struct GNode{
    int Tag;
    union{
        ElementType Data;
        GList SubList;
    }URegion;
    GList Next;
};