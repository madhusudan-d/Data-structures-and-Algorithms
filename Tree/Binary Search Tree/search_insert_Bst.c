#include<stdio.h>
#include<stdlib.h>
#include "Tree.h"

inOrder(struct Node *root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf(" %d ",root->data);
    inOrder(root->right);
}

struct Node *insert(struct Node *root,int data){
    if(root==NULL){
        struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(root->data>data)
        root->left=insert(root->left,data);
    if(root->data<data)
        root->right=insert(root->right,data);
    return root;
}

main(){
    struct Node *root=getTree();
    printf("In Order:\n");
    inOrder(root);
    root=insert(root,15);
    printf("\nIn Order:\n");
    inOrder(root);
}
