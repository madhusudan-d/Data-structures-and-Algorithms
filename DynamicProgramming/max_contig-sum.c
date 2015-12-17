#include<stdio.h>

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int max_contig_sum(int *arry,int n){
    int max_so_far=arry[0],i;
    int cur_max=arry[0];
    for(i=0;i<n;i++){
         cur_max=max(arry[i],cur_max+arry[i]);
         max_so_far=max(cur_max,max_so_far);
    }
    return max_so_far;
}

main(){
    int arr[10]={-2,-5,-1,-3,-10,-17,1,-29,-2,-4};
    int size=10;
    //printf("size=%d",size);
    int max_sum=max_contig_sum(arr,size);
    printf("max contiguous sum is %d",max_sum);
}
