/*堆中的路径*/
#include<stdio.h>
#define MAXN 1001
#define MINH -10001

int H[MAXN];
int size=0;

void Create();
void Insert(int X);

int main(){
    int n,m,x,i,j;
    sanf("%d %d",&n,&m);
    Create();
    /*插入n个元素*/
    for(i=0;i<n;i++){
        scanf("%d",&x);
        Insert(X);
    }

    /*打印路径*/
    for(i=0;i<m;i++){
        scanf("%d",&j);
        printf("%d",H[j]);
        while(j>1){
            j/=2;
            printf(" %d",H[j]);
        }
        printf("\n");
    }
    return 0;
}

/*初始化*/
void Create(){
    size=0;
    H[0]=MINH;
}

/*向小顶堆中插入一个元素X*/
void Insert(int X){
    int i=0;
    for(i=++size;H[i/2]>X;i/=2)
        H[i]=H[i/2];
    H[i]=X;
    return;
}