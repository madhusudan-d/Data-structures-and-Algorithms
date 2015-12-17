#include<stdio.h>
#include "Tree.h"

struct Stack{
    int size;
    int top;
    struct Node **array;
};


struct Stack *createStack(int size){
    struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->array=(struct Node **)malloc(size*sizeof(struct Node*));
    stack->top=-1;
    stack->size=size;
}

void push(struct Stack *stack,struct Node *node){
    stack->array[++stack->top]=node;
}

int isEmpty(struct Stack *stack){
    if(stack->top==-1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *stack){
    if(stack->top+1==stack->size)
        return 1;
    else
        return 0;
}

struct Node *pop(struct Stack *stack){
    if(!isFull(stack))
        return stack->array[stack->top--];
    else
        return NULL;
}

struct Node *peek(struct Stack *stack){
    if(isEmpty(stack))
        return NULL;
    else
        return stack->array[stack->top];
}
// logic is referred http://www.geeksforgeeks.org/print-ancestors-of-a-given-binary-tree-node-without-recursion/
void iterativePostOrder(struct Node *root){
    struct Stack *stack=createStack(20);
    do{


            while(root){
                if(root->right)
                    push(stack,root->right);
                push(stack,root);
                root=root->left;
            }
            root=pop(stack);
            if(root->right && root->right==peek(stack)){
                pop(stack);
                push(stack,root);
                root=root->right;
            }
            else{
                printf(" -%d- ",root->data);
                root=NULL;
            }

    }while(!isEmpty(stack));




}

void iterativePreOrder(struct Node *root){
    struct Stack *stack=createStack(20);

    push(stack,root);

    while(!isEmpty(stack)){
        root=pop(stack);
        printf(" -%d- ",root->data);
        if(root->right){
            push(stack,root->right);
        }
        if(root->left){
            push(stack,root->left);
        }
    }

}

void iterativeInOrder(struct Node *root){
    struct Stack *stack=createStack(20);

    do{

        while(root){
            push(stack,root);
            root=root->left;
        }
        root=pop(stack);
        printf(" -%d- ",root->data);

        if(root->right){
            root=root->right;
        }
        else{
            root=NULL;
        }

    }while(!isEmpty(stack) || root!=NULL);

}







main(){

    struct Node *root=getTree();
    printf("Iterative post-order\n");
    iterativePostOrder(root);
    printf("\nIterative pre-order\n");
    iterativePreOrder(root);
    printf("\nIterative in-order\n");
    iterativeInOrder(root);

    //printf("\njunk %d\n ",root->right);

}
