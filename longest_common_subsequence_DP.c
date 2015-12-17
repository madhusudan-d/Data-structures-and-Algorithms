#include<stdio.h>

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int LCS(char *a,char *b,int m,int n){
    int table[m+1][n+1],i,j;

    for(i=0;i<m+1;i++){
        for(j=0;j<n+1;j++){
            if(i==0||j==0)
                table[i][j]=0;
            else if(a[i-1]==b[j-1])
                table[i][j]=table[i-1][j-1]+1;
            else
                table[i][j]=max(table[i-1][j],table[i][j-1]);
        }
    }
    return table[m][n];


}

main(){
    char a[]="AGGTAB";
    char b[]="GXTXAYB";
    int m=strlen(a);
    int n=strlen(b);
    printf("LCS length is : %d \n",LCS(a,b,m,n));
}
