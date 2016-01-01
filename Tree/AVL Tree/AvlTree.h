
#include<stdio.h>


struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
    int height;
};

struct Tree *newNode(int data){
    struct Tree *tree=(struct Tree *)malloc(sizeof(struct Tree));
    tree->data=data;
    tree->left=tree->right=NULL;
    tree->height=1;
    return tree;
}

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

struct Tree *leftRotate(struct Tree *z){

    struct Tree *y=z->right;
    struct Tree *x=y->right;

    z->right=y->left;
    z->height=max(height(z->left),height(z->right))+1;
    y->left=z;
    y->height=max(height(y->left),height(y->right))+1;
    return y;

}

struct Tree *rightRotate(struct Tree *z){
    struct Tree *y=z->left;
    struct Tree *x=y->left;

    z->left=y->right;
    z->height=max(height(z->left),height(z->right))+1;
    y->right=z;
    y->height=max(height(y->left),height(y->right))+1;

    return y;

}

int height(struct Tree *node){
    if(node==NULL)
        return 0;
    return node->height;
}

struct Tree *insertAVL(struct Tree *root,int key){
    if(root==NULL)
        return (newNode(key));
    if(key<root->data)
        root->left=insertAVL(root->left,key);
    else
        root->right=insertAVL(root->right,key);

    root->height=max(height(root->left),height(root->right))+1;
    //printf("check1");

    int bd=height(root->left)-height(root->right);
    if(bd > 1 && key < root->left->data)
        return rightRotate(root);
    if(bd < -1 && key > root->right->data)
        return leftRotate(root);

    if(bd > 1 && key > root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(bd < -1 && key <root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;


}




preOrder(struct Tree *root){
    if(root==NULL)
        return;
    printf("(data:%d,height:%d)\n",root->data,root->height);
    preOrder(root->left);
    preOrder(root->right);
}

struct Tree *getAvlTree(){
    struct Tree *root=NULL;


    root = insertAVL(root, 10);

    root = insertAVL(root, 20);

    root = insertAVL(root, 30);

    root = insertAVL(root, 40);
    root = insertAVL(root, 50);
    root = insertAVL(root, 25);
    root = insertAVL(root, 35);
    return root;
}
