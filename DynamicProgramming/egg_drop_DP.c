//Problem is to find minimum number of attempts required to find a (lowest)floor at which egg breaks

#include<stdio.h>


int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

minAttempts(int egg,int floor){

    int table[egg+1][floor+1];
    int i,j,k;
    int temp=0;



    for(i=0;i<=floor;i++)
        table[1][i]=i;
    for(i=0;i<=egg;i++)
        table[i][0]=0;


    for(i=2;i<=egg;i++){
        for(j=1;j<=floor;j++){
            table[i][j]=100;
            for(k=1;k<=j;k++){
                temp=1+max(table[i-1][k-1],table[i][j-k]);
                if(temp<table[i][j]){
                    table[i][j]=temp;
                }

            }

        }
    }

   // for(i=1;i<=egg;i++){
   //     for(j=1;j<=floor;j++){
   //         printf("%d ",table[i][j]);
   //     }
   //     printf("\n");
    //}

    printf(" Minimum attempts at worst case is %d \n",table[egg][floor]);



}

main(){
    int floor=10;
    int egg=2;

    minAttempts(egg,floor);
}
