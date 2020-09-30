/*
    *采用按秩归并的思想对原来的Union函数进行改进
    *根节点不再存入-1,存入有意义的数字(树的高度或者元素的个数)
*/

/*对树高进行按秩归并:S[Root]=-hight*/
void Union(SetType S,SetName Root1,SetName Root2){
    /*
        *存入的是负的树高,S[Root2]<S[Root1],说明Root1较矮
        *应该把Root1挂到Root2上去
    */
    if(S[Root2]<S[Root1])
        S[Root1]=Root2;
    else{
        if(Root1==Root2)
            S[Root1]--;
        S[Root2=Root1];
    }
    return;
}

/*对集合中元素个数进行按秩归并:S[Root]=-cnt*/
void Union(SetType S,SetName Root1,SetName Root2){
    if(S[Root2]<S[Root1]){
        S[Root2]+=S[Root1];
        S[Root1]=Root2;
    }
    else{
        S[Root1]+=S[Root2];
        S[Root2]=Root1;
    }
    return;
}

/*采用了按秩归并后,最坏情况下的树高是logN,时间复杂度是N*logN*/