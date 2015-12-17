#include<stdio.h>
#include<string.h>

swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

permute(char *str,int l,int r){
    if(l==r)
        printf("%s\n",str);
    else{
        int i;
        for(i=l;i<=r;i++){
            swap((str+l),(str+i));
            permute(str,l+1,r);
            swap((str+l),(str+i));
        }
    }
}

main(){
    char str[10];
    printf("enter string:\n");
    scanf("%s",&str);
    int size=strlen(str);
    printf("entered string is :%s size :%d\n",str,size);
    permute(str,0,size-1);
}
