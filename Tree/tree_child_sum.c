
#include<stdio.h>
#include "Tree.h"


inOrder(struct Node *root){
    if(root==NULL)
        return;

    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);

}

int addChildSum(struct Node *root){

    if(root==NULL )
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;

    int left=addChildSum(root->left);
    int right=addChildSum(root->right);
    int diff=0;
    if(root->data<left+right){
        diff=(left+right)-(root->data);
        root->data+=diff;
    }
    if(root->data>left+right){
        diff=(root->data)-(left+right);
        if(root->left){
            root->left->data+=diff;
            addChildSum(root->left);
        }
        else{
            root->right->data+=diff;
            addChildSum(root->right);
        }


    }


}
int checkChildSum(struct Node *root){

    if(root==NULL || root->left==NULL && root->right==NULL)
        return 1;
    int left=0,right=0;
    if(root->left!=NULL)
        left=root->left->data;
    if(root->right!=NULL)
        right=root->right->data;

    //if (root->data!=left+right)
    //exit(1);

    return (root->data==left+right && checkChildSum(root->left) && checkChildSum(root->right));

}


main(){
    struct Node *root=getTree();
    printf("Before implementing child sum property\n");
    inOrder(root);
    addChildSum(root);
    printf("\nAfter implementing child sum property\n");
    inOrder(root);
    int a=checkChildSum(root);
    if(a)
        printf("\nchild sum property satisfied\n");
    else
        printf("\nchild sum property NOT satisfied\n");


}
