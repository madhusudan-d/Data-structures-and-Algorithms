#include<stdio.h>
#include<string.h>

partialMatchTable(int *tab,char *pat,int pn){
    int i=0,j=0;
    tab[i]=0;
    i++;
    while(i<pn){
        if(pat[i]==pat[j]){
            tab[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j>0){
                j=tab[j-1];
            }
            else{
                tab[i]=0;
                i++;
            }
        }
    }

}


patSearchKMP(char *str,char *pat,int sn,int pn){
    int i,j,*tab;
    tab=(int *)malloc(sizeof(int)*pn);
    partialMatchTable(tab,pat,pn);
    for(i=0;i<pn;i++)
       printf("%d ",tab[i]);
    printf("\n");
    for(i=0;i<sn;){
        for(j=0;j<pn;j++){
            if(str[i+j]!=pat[j])
                break;
        }
        if(j==pn){
            printf("found pattern at%d\n",i);
            i=i+j;
        }else if(j>1&&(j!=pn)){
            printf("j:%d",j);
            int x=i;
            i=i+j-tab[j-1];
            printf("shift from %d : %d\n",x,i);
        }
        else{
            i++;
        }
    }
}



main(){
    char str[]="AABAACAADAABAAABAA";
    char pat[]="AABA";
    int sn=strlen(str);
    int pn=strlen(pat);
    patSearchKMP(str,pat,sn,pn);
}
