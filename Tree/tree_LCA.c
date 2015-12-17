#include<stdio.h>
#include "Tree.h"

struct Node *LCA(struct Node *root,int n1,int n2,int *v1,int *v2){
    if(root==NULL)
        return NULL;
    if(root->data==n1){
        *v1=1;
        return root;
    }
    if(root->data==n2){
        *v2=1;
        return root;
    }

    struct Node *left=LCA(root->left,n1,n2,v1,v2);
    struct Node *right=LCA(root->right,n1,n2,v1,v2);
    if(left && right)
        return root;
    return left?left:right;
}

main(){

    struct Node *root=getTree();
    int v1=0,v2=0;
    struct Node *lca=LCA(root,7,6,&v1,&v2);
    printf("LCA is %d\n",lca->data);
}
