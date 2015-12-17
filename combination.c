#include<stdio.h>

int count=0;


printComb(int arr[],int data[],int start,int end,int index,int r){
    if(index==r){
        int i;
        for(i=0;i<index;i++){
            printf("%d ",data[i]);
        }
        printf("\n");
        count++;
        return;
    }
    int j;
    for(j=start;j<=end;j++){
        data[index]=arr[j];
        printComb(arr,data,j+1,end,index+1,r);
        //printf("\n");
    }
}
main(){
    int arr[]={1,2,3,4,5};//,6,7,8,9,10,11,12,13,14,15,16};
    int r=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    int data[r];
    printComb(arr,data,0,n-1,0,r);
    printf("\n %d \n",count);
}
