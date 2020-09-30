/*网络联通问题:一个典型的并查集问题*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MaxSize 1001

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];

void Input_connection(SetType S);
void Check_connection(SetType S);
void Check_network(SetType S,int n);
void Initialization(SetType S,int n);
SetName Find(SetType S,ElementType X);
void Union(SetType S,SetName Root1,SetName Root2);

int main(){
    SetType S;
    int n;
    char in;
    scanf("%d\n",&n);
    Initialization(S,n);
    do{
        scanf("%c",&in);
        switch(in){
            case 'I':
                Input_connection(S);
                break;
            case 'C':
                Check_connection(S);
                break;
            case 'S':
                Check_network(S,n);
                break;
        }
    }while(in!='S');

    return 0;
}

/*添加新连接*/
void Input_connection(SetType S){
    ElementType u,v;
    SetName Root1,Root2;
    scanf("%d %d",&u,&v);
    /*找到它们的根节点,也就是属于哪一个集合*/
    Root1=Find(S,u-1);
    Root2=Find(S,v-1);
    /*如果他们属于不同集合,就并起来*/
    if(Root1!=Root2)
        Union(S,Root1,Root2);
}

/*检查两台计算机是否连接*/
void Check_connection(SetType S){
    ElementType u,v;
    SetName Root1,Root2;
    scanf("%d %d",&u,&v);
    Root1=Find(S,u-1);
    Root2=Find(S,v-1);
    /*如果他们的根节点相同(属于同一个集合)则已连通*/
    if(Root1==Root2)
        printf("yes\n");
    else
        printf("no\n");
    return;
}

/*检查网络的连通情况*/
void Check_network(SetType S,int n){
    int i=0;
    int cnt=0;
    for(i=0;i<n;i++){
        if(S[i]<0)
            cnt++;
    }
    if(cnt==1)
        printf("The network is connected\n");
    else
        printf("There are %d componets\n",cnt);
    return;
}