#include<stdio.h>
#include<stdbool.h>

subsetSumDP(int arr[],int n,int s){
    int table[n][s+1],i,j;
    for(i=0;i<n;i++)
        for(j=0;j<s+1;j++)
            table[i][j]=0;
    for(i=0;i<n;i++)
        table[i][0]=1;

    for(i=0;i<n;i++){
        for(j=1;j<s+1;j++){
            if(j>=arr[i]){
                if(i==0 && j==arr[i])
                    table[i][j]=table[i][j-arr[i]];
                else if(i>0){
                    table[i][j]=table[i-1][j]||table[i-1][j-arr[i]];
                }
            }
        }
    }

    for(i=0;i<n;i++){
            printf("%d :",arr[i]);
        for(j=0;j<s+1;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

    //for finding subset whose sum equals to given value
    i=n-1;
    j=s;
    while(j){
        if(i==0 && table[i][j-arr[i]]){
            printf("--%d--\n",arr[i]);
            j=j-arr[i];
        }

        if(table[i][j])
        {
            if(table[i-1][j]==0 && table[i-1][j-arr[i]]){
                printf("--%d--\n",arr[i]);
                j=j-arr[i];
                i=i-1;
            }
            else
                i--;

        }
    }

}

main(){
    int arr[]={3,4,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    subsetSumDP(arr,n,9);
}
