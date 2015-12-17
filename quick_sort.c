#include<stdio.h>

int partition(int arr[],int l,int r){
    int pivot=(l+r)/2;
    int i=l,j=r,temp;
    while(i<j){

            while(arr[i]<=arr[pivot] && i<j)
                i++;

            while(arr[j]>arr[pivot])
                j--;

            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
    }

    temp=arr[pivot];
    arr[pivot]=arr[j];
    arr[j]=temp;
    return j;
}


quickSort(int arr[],int l,int r){
    if(l<r){
        int m=partition(arr,l,r);
        quickSort(arr,l,m-1);
        quickSort(arr,m+1,r);
    }
}

main(){
    int arr[]={9,8,7,6,5,4,3,2,1,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
