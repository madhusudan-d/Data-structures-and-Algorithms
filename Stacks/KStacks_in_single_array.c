#include<stdio.h>
#include<stdlib.h>

#define N 20
#define K 5

int arr[N];
int next[N];
int top[K];
int freee=0;

push(int data,int sn){
    //printf("freee : %d \n",freee);

    if(!isFull()){
        int i=freee;
        freee=next[i];
        next[i]=top[sn];
        top[sn]=i;
        arr[i]=data;

    }

}

int pop(int sn){

    if(!isEmpty(sn)){
        int i=top[sn];
        top[sn]=next[i];
        next[i]=freee;
        freee=i;
        return arr[i];
    }

}

int isFull(){
    if(freee==-1){
        printf("stack overflow\n");
        return -1;
    }

    return 0;
}

int isEmpty(int sn){
    if(top[sn]==-1){
        printf("stack empty\n");
        return -1;
    }

    return 0;
}



main(){

    int i;
    //Initialization
    for(i=0;i<K;i++)
        top[i]=-1;

    for(i=0;i<N-1;i++)
        next[i]=i+1;



    next[N-1]=-1;
    
    //for(i=0;i<N;i++)
    //    printf(" -%d- ",next[i]);

    

    push(10,0);
    push(11,0);
    push(20,1);
    push(21,1);


    printf("pop of 1 : %d \n",pop(1));
    printf("pop of 0 : %d \n",pop(0));
    printf("pop of 1 : %d \n",pop(1));
    printf("pop of 0 : %d \n",pop(0));
    
    //for(i=0;i<K;i++)
    //    printf(" %d ",top[i]);

    //for(i=0;i<N-1;i++)
    //    printf(" -%d- ",arr[i]);





}
