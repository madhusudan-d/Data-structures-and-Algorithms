#include<stdio.h>

int binarySearch(int arr[],int l,int r,int x){
    int mid=l+(r-l)/2;
    if(l<=r){
        if(arr[mid]==x)
            return mid;
        if(arr[mid]<x)
            return binarySearch(arr,mid+1,r,x);
        if(arr[mid]>x)
            return binarySearch(arr,l,mid-1,x);

    }
    return -1;
}

main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int x=5;
    int found=binarySearch(arr,0,size-1,x);
    printf("found at :%d",found);
}
