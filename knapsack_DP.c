#include<stdio.h>

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

solveDP(int value[],int weight[],int n,int w){
    int table[n][w+1],i,j;
    for(i=0;i<n;i++)
        for(j=0;j<w+1;j++)
            table[i][j]=0;

    for(i=0;i<n;i++){
        for(j=1;j<w+1;j++){
            if(j>=weight[i]){
                if(i==0){
                    table[i][j]=value[i];
                }
                else{
                    table[i][j]=max(value[i]+table[i-1][j-weight[i]],table[i-1][j]);
                }
            }
            else{
                if(i>0)
                    table[i][j]=table[i-1][j];
            }
        }
    }

    for(i=0;i<n;i++){
        printf("val:%d wt:%d :-",value[i],weight[i]);
        for(j=0;j<w+1;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

    i=n-1;
    j=w;
    printf("selected weights and values are :\n");
    while(i>0){
        if(table[i][j]!=table[i-1][j]){
            printf("--w:%d, v:%d--\n ",weight[i],value[i]);
            j=j-weight[i];
            i=i-1;
        }
        else{
            i--;
        }


    }

}

main(){
    int value[4]={1,5,4,7};
    int weight[4]={1,4,3,5};
    int n=sizeof(value)/sizeof(value[0]);
    solveDP(value,weight,n,7);
}
