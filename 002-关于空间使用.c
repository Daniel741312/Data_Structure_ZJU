#include <stdio.h>

void PrintN1(int N);
void PrintN2(int N);

int main(){
    int n;
    int select=0;
    printf("Select the function:\n1-cycle\n2-recursion\n");
    scanf("%d",&select);

    printf("\nInput the num:\n");
    scanf("%d",&n);

    if(select==1)
        PrintN1(n);
    else
        PrintN2(n);
    return 0;
}

/*循环版本:平淡无奇*/
void PrintN1(int N){
    int i = 0;
    for (i = 1; i <= N; i++)
        printf("%d\n", i);
    return;
}

/*递龟版本:N到100000时堆栈爆掉*/
void PrintN2(int N){
    if (N){
        PrintN2(N - 1);
        printf("%d\n", N);
    }
    return;
}
