#include<stdio.h>

#include "Tree.h"

void inOrder(struct Node *root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void preOrder(struct Node *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct Node *root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

int countNodes(struct Node *root){
    static int n;
    if(root==NULL)
        return n;
    n++;
    countNodes(root->left);
    countNodes(root->right);
}

int maxDepth(struct Node *root){
    if(root==NULL)
        return 0;
    else{
        int lDepth=maxDepth(root->left);
        int rDepth=maxDepth(root->right);
    if(lDepth>=rDepth)
        return(lDepth+1);
    else
        return(rDepth+1);
    }

}

int identical(struct Node *a,struct Node *b){
    if(a==NULL&&b==NULL)
        return 1;
    else{
        return(identical(a->left,b->left)&&identical(a->right,b->right)&&(a->data==b->data));
    }
}

void mirror(struct Node *root){
    if(root==NULL)
        return;
    else{
        struct Node *temp;
        mirror(root->left);
        mirror(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;

    }
}

struct Node* copyTree(struct Node *root){
    if(root==NULL)
        return NULL;
    else{
        struct Node *copy;
        copy=(struct Node*)malloc(sizeof(struct Node));
        copy->left=copyTree(root->left);
        copy->right=copyTree(root->right);
        copy->data=root->data;
        return copy;
    }

}

int numOfFullNodes(struct Node *root){
    if(root==NULL)
        return 1;
    return ((root->left&&root->right)+numOfFullNodes(root->left)+numOfFullNodes(root->right));
}

main(){
    struct Node *root;
    root=getTree();
    printf("\n Inorder traversal \n");
    inOrder(root);
    printf("\n Preorder traversal \n");
    preOrder(root);
    printf("\n Postorder traversal \n");
    postOrder(root);
    int n;
    n=countNodes(root);
    printf("\n Number of nodes in a tree = %d \n",n);
    n=maxDepth(root);
    printf("\n Height of tree = %d \n",n);
    n=identical(root,root);
    printf("\n status of identity = %d \n",n);
    struct Node *mirrorHead;
    mirror(root);
    printf("\n After mirror Inorder Traversal \n");
    inOrder(root);
    struct Node *copied;
    copied=copyTree(root);
    printf("\n After copy Inorder Traversal \n");
    inOrder(copied);
    int nf=0;
    nf=numOfFullNodes(root);
    printf("\n number of full nodes is : %d\n",nf);

    printf("\n ")

}
