/*计算一元多项式*/
#include<stdio.h>
#include<math.h>
#include<time.h>
#define MAXN 10                 //多项式的阶数
#define MAXK 1e7                //最大循环次数

clock_t start,stop;

double f1(int n,double a[],double x);
double f2(int n,double a[],double x);

int main(){
    int i=0;
    int k=0;
    double x=1.1;
    double a[MAXN];
    /*简单的把a[i]赋值成为i*/
    for(i=0;i<MAXN;i++)
        a[i]=(double)i;
    
    start=clock();
    for(k=0;k<MAXK;k++)
        f1(10,a,x);
    stop=clock();
    printf("ticks1 cycles for 1e7 times=%d\n",(int)(stop-start));

    start=clock();
    for(k=0;k<MAXK;k++)
        f2(10,a,x);
    stop=clock();
    printf("\nticks2 cycles for 1e7 times=%d\n",(int)(stop-start));

    return 0;
}

/*直接算法*/
double f1(int n,double a[],double x){
    int i=0;
    double p=a[0];
    for(i=1;i<=n;i++)
        p=p+(a[i]*pow(x,i));
    return p;
}

/*秦九韶算法*/
double f2(int n,double a[],double x){
    int i=0;
    double p=a[n];
    for(i=n;i>0;i--)
        p=a[i-1]+x*p;
    return p;
}

/*秦九韶算法用递归怎么实现呢?*/