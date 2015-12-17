#include<stdio.h>
#include<string.h>

patSearch(char *str,char *pat,int sn,int pn){
    int i,j;
    for(i=0;i<=sn-pn;i++){
        for(j=0;j<pn;j++){
            if(str[i+j]!=pat[j])
                break;
        }
        if(j==pn){
            printf("pattern found at %d\n",i);
            i=i+j-1;
        }
    }
}

main(){
    char str[]="abcdefghababcabaab";
    char pat[]="abc";
    int sn=strlen(str);
    int pn=strlen(pat);
    patSearch(str,pat,sn,pn);
}
