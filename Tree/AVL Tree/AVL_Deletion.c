#include<stdio.h>
#include<stdlib.h>
#include "AvlTree.h"

int findSuccessor(struct Tree *root){
    struct Tree *temp=root;
    while(root->left){
        temp=root->left;
        root=root->left;
    }
    return temp->data;
}

int height1(struct Tree *node){
    if(node==NULL)
        return 0;
    return node->height;

}

int max1(int a,int b){
    if(a>b)
        return a;
    return b;
}

struct Tree *leftRotate1(struct Tree *z){
    struct Tree *y=z->right;
    struct Tree *x=y->right;


    z->right=y->left;
    y->left=z;

    z->height=max1(height1(z->left),height1(z->right))+1;
    y->height=max1(height1(y->left),height1(y->right))+1;

    return y;

}

struct Tree *rightRotate1(struct Tree *z){
    struct Tree *y=z->left;
    struct Tree *x=y->left;


    z->left=y->right;
    y->right=z;

    z->height=max1(height1(z->left),height1(z->right))+1;
    y->height=max1(height1(y->left),height1(y->right))+1;

    return y;

}


int balance(struct Tree *node){
    return height(node->left)-height(node->right);
}

struct Tree *deleteNode(struct Tree *root,int key){
    if(root==NULL)
        return root;


    if(key < root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key > root->data){
        root->right=deleteNode(root->right,key);
    }
    else{

        struct Tree *temp;

        if(root->left && root->right==NULL){
            temp=root->left;
            free(root);
            return temp;
        }
        if(root->right && root->left==NULL){
            temp=root->right;
            free(root);
            return temp;
        }
        if(root->left==NULL && root->right==NULL ){

            free(root);

            return NULL;
        }
        if(root->right && root->left){

            int temp=findSuccessor(root->right);

            root->data=temp;

            root->right=deleteNode(root->right,temp);

        }
    }

    root->height=max1(height1(root->left),height1(root->right))+1;

    int bd=balance(root);

    //here z x y are different than what we considered in insertion(where all z,x,y are ancestors of inserted key)
    //here let z be first unbalanced node while traversing upwards, y will be  larger height child of z,x will be larger height child of y
    if( bd > 1 && balance(root->left) >= 0 ){
        return rightRotate1(root);

    }
    if( bd > 1 && balance(root->left) < 0 ){
        root->left=leftRotate1(root->left);
        return rightRotate1(root);
    }
    if( bd < -1 && balance(root->right) <= 0 ){
        return leftRotate1(root);
    }
    if( bd < -1 && balance(root->right) > 0 ){
        root->right=rightRotate1(root->right);
        return leftRotate1(root);
    }

    return root;

}





main(){
    struct Tree *root=getAvlTree();
    printf("\nBefore Deletion, PreOrder Traversal:\n");
    preOrder(root);
    root=deleteNode(root,30);
    root=deleteNode(root,25);
    root=deleteNode(root,20);
    root=deleteNode(root,10);
    printf("\nAfter Deletion, PreOrder Traversal:\n");
    preOrder(root);




}



