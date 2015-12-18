
#include<stdio.h>

int findCeilBst(int arr[],int T[],int len,int data){
    int low=0,mid,high=len;
    while(low <= high){
        mid=(low+high)/2;
        if(mid < len && data<=arr[T[mid+1]] && data>arr[T[mid]])
            return mid+1;
        else if(data>arr[T[mid]]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return -1;
}

LISnlogn(int arr[],int n){
    int T[n],R[n],i,len=0;
    T[0]=0;
    for(i=0;i<n;i++)
        R[i]=-1;

    for(i=1;i<n;i++){
        if(arr[i]<arr[T[0]]){
            T[0]=i;
            //printf(" t0 :%d \n",T[0]);
        }
        else if(arr[i]<arr[T[len]]){
            int index=findCeilBst(arr,T,len,arr[i]);
            T[index]=i;
            R[T[index]]=T[index-1];
            //printf("index : %d \n",index);
        }
        else{
            len++;
            T[len]=i;
            R[T[len]]=T[len-1];
            //printf(" len %d \n",len);

        }

    }
    printf(" %d \n",len+1);

    int index=T[len];
    while(index!=-1){
        printf("  %d  ",arr[index]);
        index=R[index];
    }


}

main(){
    int arr[]={3,4,-1,5,8,2,3,12,7,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    LISnlogn(arr,n);
}
