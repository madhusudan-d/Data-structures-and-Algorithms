//Given to strings str1 and str2, find minimum number of operations(edits) required to convert str1 to str2.
// you can perform one of the three operations at a time 1) insert 2)delete 3)replace
//Input:   str1 = "cat", str2 = "cut"
//Output:  1
//We can convert str1 into str2 by replacing 'a' with 'u'.


#include<stdio.h>
#include<string.h>

int min(int a,int b,int c){
   return min1(min1(a,b),c);
}
int min1(int a,int b){
    if(a<b)
        return a;
    return b;
}

minEditDistanceDP(char str1[],char str2[]){
    int n=strlen(str1);
    int m=strlen(str2);

    int tab[m+1][n+1];
    int i,j;


    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0||j==0){
                tab[i][j]=i?i:j;
            }
            else{
                if(str1[j-1]==str2[i-1]){
                    tab[i][j]=tab[i-1][j-1];
                }
                else{
                    tab[i][j]=min(tab[i-1][j],tab[i][j-1],tab[i-1][j-1])+1;
                }

            }
        }
    }
    //for(i=0;i<m+1;i++){
    //    for(j=0;j<n+1;j++){
    //        printf(" %d ",tab[i][j]);
    //    }
    //    printf("\n");
    //}
    printf(" min edit Distance %d\n",tab[m][n]);

}


main(){
    char str1[]="saturday";
    char str2[]="sunday";

    minEditDistanceDP(str1,str2);


}
