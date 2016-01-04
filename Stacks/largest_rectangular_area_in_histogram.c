#include<stdio.h>
#include<stdlib.h>

#include"stack1.h"

//assume width is 1 for each height.
//the logic is, push index of elements whose value(height) greater then value on top of stack
//otherwise pop element and calculate area with respect to popped element , compare this area with this with previous area
//here we always compare area with respect to (top to right(smaller among right)) and (left(smaller among the left) to top)

maxArea(int arr[],int n){
    struct Stack *stack=createStack();
    int max=-1,top,i=0,area,len;
    while(i<n){
        if(isEmptyStack(stack) || arr[peek(stack)]<=arr[i])
            pushStack(stack,i++);
        else{
            top=popStack(stack);

            //if stack is empty len=i
            //else len=i-top-1
            if(isEmptyStack(stack))
                len=i;
            else
                len=i-peek(stack)-1;

            area=arr[top] * len;
            if(area>max)
                max=area;
        }

    }

    while(!isEmptyStack(stack)){
        top=popStack(stack);
        if(isEmptyStack(stack))
            len=i;
        else
            len=i-peek(stack)-1;

        area=arr[top]* len;
        if(area>max)
            max=area;
    }

    printf("max area is %d \n",max);

}

main(){
    int arr[]={6,2,5,4,5,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    maxArea(arr,n);


}
