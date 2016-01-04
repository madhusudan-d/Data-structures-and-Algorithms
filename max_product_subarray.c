#include<stdio.h>

int min(int a,int b){
    if(a<b)
        return a;
    return b;
}

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

maxProduct(int arr[],int n){
    int i=0;
    int max_ending_here=0;
    int min_ending_here=0;
    int max_so_far=0;

    for(i=0;i<n;i++){
        if(arr[i]>0){
            max_ending_here=max(max_ending_here*arr[i],arr[i]);
            min_ending_here=min(min_ending_here*arr[i],min_ending_here);
        }
        if(arr[i]==0){
            max_ending_here=0;
            min_ending_here=0;
        }
        if(arr[i]<0){
            int temp=max_ending_here;
            max_ending_here=max(min_ending_here*arr[i],arr[i]);
            min_ending_here=temp*arr[i];
        }
        if(max_ending_here > max_so_far)
            max_so_far=max_ending_here;
    }

    printf("max product subarray is %d \n ",max_so_far);
}


main(){
    int arr[]= {1, -2, -3, 0, 7, -8, -2};
    int n=sizeof(arr)/sizeof(arr[0]);
    maxProduct(arr,n);
}
