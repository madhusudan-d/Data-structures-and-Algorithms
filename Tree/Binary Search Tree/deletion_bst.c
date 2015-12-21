
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

struct Node* findmin(struct Node *root){
    struct Node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;

}

struct Node *deleteNode(struct Node *root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
            struct Node *temp=NULL;
        if(!root->left && !root->right){
            free(root);
            return NULL;
        }
        if(!root->left && root->right){
            temp=root->right;
            free(root);
            return temp;
        }
        if(!root->right && root->left){
            temp=root->left;
            free(root);
            return temp;
        }
        if(root->left && root->right){
            temp=findmin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
            return root;
        }

    }
    if(root->data>data)
        root->left=deleteNode(root->left,data);
    if(root->data<data)
        root->right=deleteNode(root->right,data);
    return root;
}

main(){
    struct Node *root=getTree();
    printf("In Order:\n");
    inOrder(root);
    root=deleteNode(root,9);
    printf("\nIn Order:\n");
    inOrder(root);
}
