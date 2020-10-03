/*在线处理*/
int MaxSubseqSum4(int A[],int N){
    int ThisSum=0;
    int MaxSum=0;
    int i=0;
    for(i=0;i<N;i++){
        ThisSum+=A[i];
        if(ThisSum>MaxSum)
            MaxSum=ThisSum;
        /*一旦当前子列和为负,则不可能使后面部分变大,直接丢弃*/
        else if(ThisSum<0)
            ThisSum=0;
    }
    return MaxSum;
}