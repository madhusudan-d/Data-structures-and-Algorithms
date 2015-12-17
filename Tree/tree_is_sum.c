#include<stdio.h>
#include "Tree.h"

int checkSum(struct Node *root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int left=checkSum(root->left);
    int right=checkSum(root->right);
    if(root->data==left+right)
        return (root->data+left+right);
    else
        return 0;
}

inOrder(struct Node *root){
    if(root==NULL)
        return;

    inOrder(root->left);
    printf("%d ",root->data);

    inOrder(root->right);

}



main(){
    struct Node *root=getTree();
    printf("Inorder \n");
    inOrder(root);
    int a=checkSum(root);
    if(a)
        printf("\ntree sum property satisfied\n");
    else
        printf("\ntree sum property NOT satisfied\n");

}
