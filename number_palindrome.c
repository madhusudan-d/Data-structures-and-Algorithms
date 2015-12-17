#include<stdio.h>
main(){
    int a=1221;
    int n=0;
    int temp=a;
    while(temp){
        n=n*10+temp%10;
        temp=temp/10;
    }
    printf("n:%d a:%d\n",n,a);
    if(a==n)
        printf("number is palindrome\n");
    else
        printf("number is not palindrome\n");

}
