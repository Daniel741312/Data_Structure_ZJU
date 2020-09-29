/*堆的插入*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ElementType int
#define MaxData 10000				//设置“哨兵”，插入时判定到0号元素终止判定

typedef struct HeapStruct* MaxHeap;
struct HeapStruct{
	ElementType* Elements;			//Element是一个ElementType(int)类型的数组
	int Size;				//当前堆的元素个数
	int Capacity;				//堆的最大元素个数
};

/*函数声明先*/
MaxHeap Create(int MaxSize);
void Insert(MaxHeap H,ElementType item);
bool IsFull(MaxHeap H);
}

/*建立一个空堆*/
MaxHeap Create(int MaxSize){
	MaxHeap H=malloc(sizeof(struct HeapStruct));
	H->Elements=malloc((MaxSize+1)*sizeof(ElementType));
	H->Size=0;
	H->Capacity=MaxSize;
	H->Elements[0]=MaxData;
	return H;
}

/*插入元素*/
void Insert(MaxHeap H,ElementType item){
	int i=0;				//虽然没有显示的绑定，但i一直指向被插入的元素的位置，找到了合适的i再插入		
	if(IsFull(H)){
		printf("Full\n");
		return;
	}

	i=++H->Size;				//在堆末尾“开一块空间”

	/*核心部分：
	 * 循环的判定条件是此位置的父节点<传入的item，
	 * 条件若成立说明父节点不配在这个位置，循环体将其换出来：将他的值拷贝到当前位置
	 * i/2跃升为父节点，进入下一轮，由于哨兵的存在，循环最终一定是可以结束的
	 * */
	for(;H->Elements[i/2]<item;i/=2)
		H->Elements[i]=H->Elements[i/2];

	H->Elements[i]=item;			//找到了合适的位置，item可以插入了
	return;
}

bool IsFull(MaxHeap H){
	return H->Size==(H->Capacity-1);
}
