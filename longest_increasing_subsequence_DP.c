#include<stdio.h>

int lisDP(int arr[],int n){
    int table[n],i,j;
    for(i=0;i<n;i++)
        table[i]=1;
    for(i=1;i<n;i++){
        j=0;
        for(j=0;j<i;j++){
            if(arr[j]<arr[i]){
            //table[i] store longest increasing subsequence till i from j
                if(table[j]+1>table[i])
                    table[i]=table[j]+1;
            }
        }
    }
    printf("LIS table\n");
    int max=table[0];
    for(i=0;i<n;i++){
        if(max<table[i])
            max=table[i];
        printf("%d ",table[i]);
    }
    printf("\n");

    return max;
}

main(){
    int arr[]={3,4,-1,0,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=lisDP(arr,n);
    printf("Longest increasing subsequence is %d \n",ans);
}
