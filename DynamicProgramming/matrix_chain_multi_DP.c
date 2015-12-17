#include<stdio.h>

#define INT_MAX 1000000


int mcc_DP(int arr[],int n){
    int table[n][n],p,i,j,l,k;
    int a,b,c,d;
    for(i=1;i<n;i++)
        table[i][i]=0;


    for(l=2;l<n;l++){
        for(i=1;i<n-l+1;i++){
            j=i+l-1;
            table[i][j]=INT_MAX;
            for(k=i;k<=j;k++){
                p=table[i][k]+table[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(p<table[i][j]){
                    table[i][j]=p;
                    a=i;b=k;c=k+1;d=j;
                }

            }
            printf("for i: %d j: %d \n (%d,%d) (%d,%d)\n",i,j,a,b,c,d);
        }
    }
    for(i=1;i<n;i++){
        printf("%d :",i);
        for(j=1;j<n;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    return table[1][n-1];

}

main(){
    int arr[]={2,3,6,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int p=mcc_DP(arr,n);
    printf("minimum multiplications required :%d\n",p);
}
