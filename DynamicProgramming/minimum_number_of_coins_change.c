#include<stdio.h>

#define INT_MAX 1000

int min(int a,int b){
    if(a>b)
        return b;
    else
        return a;
}

int countCoins(int arr[],int na,int s){
    if(s==0)
        return 1;
    if(s<0)
        return 0;
    if(na<=0 && s>=1)
        return 0;
    return countCoins(arr,na-1,s)+countCoins(arr,na,s-arr[na-1]);
}

int minCountCoins(int coin[],int n,int s){
    if(s==0)
        return 0;
    int res=INT_MAX,i;
    for(i=0;i<n;i++){
        if(coin[i]<=s){
            int sub_res=minCountCoins(coin,n,s-coin[i]);
            if(sub_res!=INT_MAX && sub_res+1<res)
                res=sub_res+1;
        }
    }
    return res;
}

int minCountCoinsDP(int coin[],int n,int s){
    int table[s+1];
    table[0]=0;
    int i,j;
    for(i=1;i<s+1;i++)
        table[i]=INT_MAX;

    for(i=1;i<s+1;i++){
        for(j=0;j<n;j++){
            if(coin[j]<=i){
                int sub_res=table[i-coin[j]];
                if(sub_res!=INT_MAX && sub_res+1<table[i])
                    table[i]=sub_res+1;

            }
        }
    }
    printf("table for min count DP\n");
    for(i=0;i<s+1;i++)
        printf("%d ",table[i]);
    return table[s];
}


coinChangeMinDP(int coin[],int n,int s){
    int table[n][s+1];
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<s+1;j++)
            table[i][j]=INT_MAX;
    for(i=0;i<n;i++)
        table[i][0]=0;
    for(i=0;i<n;i++){
        for(j=1;j<s+1;j++){
            if(j>=coin[i])
                if(i>=1)
                    table[i][j]=min(table[i-1][j],table[i][j-coin[i]]+1);
                else
                    table[i][j]=table[i][j-coin[i]]+1;
        }
    }
    for(i=0;i<n;i++){
            printf("%d: ",coin[i]);
        for(j=0;j<s+1;j++)
            printf("%d ",table[i][j]);
        printf("\n");
    }

}
coinChangeWaysDP(int coin[],int n,int s){
    int table[n][s+1];
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<s+1;j++)
            table[i][j]=0;
    for(i=0;i<n;i++)
        table[i][0]=1;
    for(i=0;i<n;i++){
        for(j=1;j<s+1;j++){
            if(j>=coin[i]){
                if(i<1)
                    table[i][j]=table[i][j-coin[i]];
                else
                    table[i][j]=table[i-1][j]+table[i][j-coin[i]];
            }
                //table[i][j]=table[i-1][j];
        }
    }
    for(i=0;i<n;i++){
        printf("%d: ",coin[i]);
        for(j=0;j<s+1;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
}

main(){
    int coin[]={6,3,5};
    int n=sizeof(coin)/sizeof(coin[0]);
    int s=11;
    printf("\nnumber of ways (recursion)=%d\n",countCoins(coin,n,s));
    printf("\nminimum number of coins (recursion)=%d\n");
    minCountCoins(coin,n,s);
    printf("\nminimum number of coins (DP)\n");
    minCountCoinsDP(coin,n,s);
    printf("\n\ncoin change problem build table for minimum coins using DP\n");
    coinChangeMinDP(coin,n,s);
    printf("\ncoin change problem build table for number of ways using DP\n");
    coinChangeWaysDP(coin,n,s);
}

