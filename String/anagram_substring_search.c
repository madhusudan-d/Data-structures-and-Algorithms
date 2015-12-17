#include<stdio.h>
#include<stdlib.h>

int MAX=256;
compare(int arr1[],int arr2[]){
    int i;
    for(i=0;i<MAX;i++){
        if(arr1[i]!=arr2[i])
            return 0;
    }
    return 1;
}

searchAnagram(char *str,char *pat,int sn,int pn){
    int countP[MAX],countW[MAX];
    int i;
    for(i=0;i<MAX;i++){
        countP[i]=0;
        countW[i]=0;
    }
    for(i=0;i<pn;i++){
        countP[pat[i]]++;
        countW[str[i]]++;
    }

    for(i=pn;i<=sn;i++){
        if(compare(countP,countW))
            printf("found at %d\n",i-pn);
        countW[str[i]]++;
        countW[str[i-pn]]--;
    }
}
main(){
    char str[]="babcdbabc";
    char pat[]="abb";
    int sn=strlen(str);
    int pn=strlen(pat);
    searchAnagram(str,pat,sn,pn);

}
