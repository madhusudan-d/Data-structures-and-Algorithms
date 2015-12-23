#include<stdio.h>
#include<stdlib.h>

spiral(int arr[4][4],int m,int n){
    int i,j;
    int p=0,q=0;

    //p->starting row index
    //q->starting col index
    //m->ending row index
    //n->ending col index

   while(p< m && q<n){

        for(i=p;i<n;i++){
            printf(" %d ",arr[p][i]);
        }
        p++;

        for(i=p;i<m;i++){
            printf(" %d ",arr[i][n-1]);
        }
        n--;

        if(p<m){
            for(i=n-1;i>=q;i--){
                printf(" %d ",arr[m-1][i]);
            }
            m--;
        }


        if(q<n){

            for(i=m-1;i>=p;i--){
                printf(" %d ",arr[i][q]);
            }
            q++;
        }

    }

}

main(){
    int arr[4][4];
    int i,j,a=1;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            arr[i][j]=a;
            a++;
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    spiral(arr,4,4);
}
