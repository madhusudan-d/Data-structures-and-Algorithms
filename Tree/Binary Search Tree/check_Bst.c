#include<stdio.h>
#include<stdlib.h>
#include "Tree.h"

#define INT_MIN 0
#define INT_MAX 1000

isBst(struct Node *root,int min,int max){
    if(root==NULL)
        return 1;
    if(root->data<min || root->data>max)
        return 0;

    return (isBst(root->left,min,root->data) && isBst(root->right,root->data,max));


}

isBstInOrder(struct Node *root,int *prev){
    if(root==NULL )
        return 1;
    if(!isBstInOrder(root->left,prev))
        return 0;
    if(root->data<*prev)
        return 0;
    *prev=root->data;
    return(isBstInOrder(root->right,prev));

}

inOrder(struct Node *root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf(" %d ",root->data);
    inOrder(root->right);
}

main(){
    struct Node *root=getTree();
    printf("In order traversal:\n");
    inOrder(root);
    printf("\n");
    if(isBst(root,INT_MIN,INT_MAX))
        printf("is a binary search tree\n");
    else
        printf("not a binary search tree\n");
    int prev=INT_MIN;
    if(isBstInOrder(root,&prev))
        printf("is a binary search tree(using in order)\n");
    else
        printf("not a binary search tree(using in order)\n");

}
