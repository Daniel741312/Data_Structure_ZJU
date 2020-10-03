/*最大子列和问题*/

/*憨憨解法*/
int MaxSubseqSum1(int A[],int N){
    int ThisSum=0;
    int MaxSum=0;
    int i,j,k;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            ThisSum=0;
            for(k=i;j<j;k++)
                ThisSum+=A[k];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }
    }
    return MaxSum;
}

/*常规解法*/
int MaxSubseqSum2(int A[],int N){
    int ThisSum=0;
    int MaxSum=0;
    int i,j;
    for(i=0;i<N;i++){
        ThisSum=0;
        for(j=i;j<N;j++){
            ThisSum+=A[i];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }
    }
    return MaxSum;
}
