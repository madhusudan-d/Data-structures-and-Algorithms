#include<stdio.h>
#include<stdlib.h>

#define INT_MIN 0
#define INT_MAX 1000

struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *createNode(int data){
    struct Tree *tree=(struct Tree *)malloc(sizeof(struct Tree));
    tree->data=data;
    tree->left=tree->right=NULL;
    return tree;
}

struct Tree *constructBst(int pre[],int *preIndex,int key,int min,int max,int n){

    if(*preIndex>=n)
        return NULL;
        struct Tree *root=NULL;
    if( key > min && key < max ){
        root=createNode(key);
        *preIndex=*preIndex+1;

        if(*preIndex < n){

            root->left=constructBst(pre,preIndex,pre[*preIndex],min,key,n);

            root->right=constructBst(pre,preIndex,pre[*preIndex],key,max,n);
        }
    }
    return root;

}

inOrder(struct Tree *root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf(" %d ",root->data);
    inOrder(root->right);
}

main(){
    int pre[]={10,5,1,7,40,50};
    int n=sizeof(pre)/sizeof(pre[0]);
    int key=pre[0];
    int preIndex=0;
    int min=INT_MIN;
    int max=INT_MAX;
    struct Tree *root=constructBst(pre,&preIndex,key,min,max,n);

    printf("In order traversal is :\n");
    inOrder(root);
}
