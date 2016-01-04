#include<stdio.h>
#include<stdlib.h>

//comment below 4 lines if using with queue.h (already there in queue.h)
struct List{
    int data;
    struct List *next;
};

struct Stack {
    struct List *top;
};

struct Stack *createStack(){
    struct Stack *stack1=(struct Stack *)malloc(sizeof(struct Stack));
    stack1->top=NULL;
    return stack1;
}
int peek(struct Stack *stack1){
    if(!isEmptyStack(stack1))
        return stack1->top->data;
    return 0;
}

struct Stack *createStackNode(int data){
    struct List *newNode=(struct List *)malloc(sizeof(struct Stack));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

int isEmptyStack(struct Stack *stack1){
    if(stack1->top==NULL)
        return 1;
    else
        return 0;
}




pushStack(struct Stack *stack1,int data){
    if(stack1->top==NULL){
        stack1->top=createStackNode(data);
    }
    else{
        struct List *temp=stack1->top;
        stack1->top=createStackNode(data);
        stack1->top->next=temp;
    }
}

int popStack(struct Stack *stack1){
    if(stack1->top==NULL)
        printf("stack empty\n");
    else{
        struct List *temp=stack1->top;
        stack1->top=stack1->top->next;
        int data=temp->data;
        free(temp);
        return data;
    }
}

