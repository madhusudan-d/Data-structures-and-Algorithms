#include<stdio.h>
#include<stdlib.h>
#include "Tree.h"

#define INT_MAX 1000
#define INT_MIN 0

int largestBst(struct Node *root,int *min,int *max,int *maxSize,int *isBst){

    if(root==NULL){
        *isBst=1;
        return 0;
    }
    int leftBst=0;
    int rightBst=0;
    int ls,rs;
    *max=INT_MIN;

    ls=largestBst(root->left,min,max,maxSize,isBst);
    if(*isBst==1 && root->data>*max)
        leftBst=1;

    int minLeft=*min;
    *min=INT_MAX;
    rs=largestBst(root->right,min,max,maxSize,isBst);
    if(*isBst==1 && root->data<*min)
        rightBst=1;

    if(minLeft<*min)
        *min=minLeft;
    if(root->data<*min)
        *min=root->data;
    if(root->data>*max)
        *max=root->data;

    if(rightBst && leftBst){
        *isBst=1;
        if(ls+rs+1>*maxSize)
            *maxSize=ls+rs+1;
       // printf("\n %d  root:%d min :%d max :%d\n",*maxSize,root->data,*min,*max);
        return ls+rs+1;
    }
   // printf("\nout  %d  root:%d min :%d max :%d\n",*maxSize,root->data,*min,*max);
        *isBst=0;
        return 0;

}

postOrder(struct Node *root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ",root->data);
}

main(){
    struct Node *root=getTree();
    int min=INT_MAX;
    int max=INT_MIN;
    int isBst=0;
    int maxSize=0;
    printf("post order traversal \n");
    postOrder(root);
    largestBst(root,&min,&max,&maxSize,&isBst);

    printf("\nlargest BST is of length %d \n",maxSize);
}
