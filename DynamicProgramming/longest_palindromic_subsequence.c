#include<stdio.h>


int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

LPS(char *str,int n){
    int table[n+1][n+1],i,j,l;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                table[i][j]=1;
            else
                table[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",table[i][j]);
        printf("\n");
    }

    for(l=2;l<n+1;l++){
        for(i=0;i<n+1;i++){
            j=i+l-1;
            if(i<n &&j <n){
            //if(l==2 && str[i]==str[j])
              //  table[i][j]=2;
             if(str[i]==str[j])
                table[i][j]=table[i+1][j-1]+2;
            else
                table[i][j]=max(table[i+1][j],table[i][j-1]);
            }
        }
    }
    printf("largest palindromic subsequence=%d\n",table[0][n-1]);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",table[i][j]);
        printf("\n");
    }
}

main(){
    //answer should be 4 (abdba)
    char str[]="agbdba";
    int n=strlen(str);
    printf("strlen =%d\n",n);
    LPS(str,n);
}
