
#include<stdio.h>

palindrome(char *str){
    int len=strlen(str);
    int maxlen=0;
    int low,high,i,start;

    for(i=1;i<len;i++){
        low=i-1;
        high=i;
        while(low>=0 && high<len && str[low]==str[high]){
            if((high-low+1) >maxlen){
                start=low;
                maxlen=high-low+1;
            }
            --low;
            ++high;
        }
        low=i-1;
        high=i+1;
        while(low>=0 && high<len && str[low]==str[high]){
            if((high-low+1) >maxlen){
                start=low;
                maxlen=high-low+1;
            }
            --low;
            ++high;
        }

    }
    for(i=start;i<start+maxlen;i++)
        printf("%c",str[i]);
    printf("\n");
}

main(){
    char str[]="cabcbabacbaqiuaba";
    palindrome(str);
}
