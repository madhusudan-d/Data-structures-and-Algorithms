#include<stdio.h>

rotate(int arr[3][4],int *dest,int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            int x=(j*m)+(m-i)-1;
            *(dest+x)=arr[i][j];
            printf(" %d ",*(dest+x));
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf(" %d ",*(dest+i*m+j));
        }
        printf("\n");
    }

}

main(){
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int m=3,n=4;
    int *dest;
    dest=(int *)malloc(sizeof(int)*m*n);
    rotate(arr,dest,m,n);
}
