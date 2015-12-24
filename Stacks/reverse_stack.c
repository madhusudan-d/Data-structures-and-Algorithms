#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

insertBottom(struct Stack *stack,int item){
    if(isEmptyStack(stack)){
        pushStack(stack,item);
    }
    else{
        int temp=popStack(stack);
        insertBottom(stack,item);
        pushStack(stack,temp);
    }
}


reverseStack(struct Stack *stack){
    if(!isEmptyStack(stack)){
        int temp=popStack(stack);
        reverseStack(stack);
        insertBottom(stack,temp);
    }
}

printStack(struct Stack *stack){
    if(isEmptyStack(stack))
        return;
    int item=popStack(stack);
    printf(" %d ",item);
    printStack(stack);
    pushStack(stack,item);
}

main(){
    struct Stack *stack=createStack();
    pushStack(stack,1);
    pushStack(stack,2);
    pushStack(stack,3);
    pushStack(stack,4);
    pushStack(stack,5);

    printf("stack before reversing\n");
    printStack(stack);

    reverseStack(stack);
    printf("\nstack after reversing\n");
    printStack(stack);




}
