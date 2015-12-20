#include<stdio.h>
#include "Tree.h"

morrisInorder(struct Node *cur){
    while(cur!=NULL){
        if(cur->left==NULL){
            printf(" -%d- ",cur->data);
            cur=cur->right;
        }
        else{

            struct Node *prev=cur->left;
            while(prev->right!=NULL && prev->right!=cur)
                prev=prev->right;

            if(prev->right==NULL){
                //uncomment for preorder
                //printf(" -2 %d- ",cur->data);
                prev->right=cur;
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                //comment for preorder
                printf(" -%d- ",cur->data);
                cur=cur->right;
            }
        }
    }
}
inOrder(struct Node *root){
    if(!root)
        return;

    inOrder(root->left);
    printf(" -%d- ",root->data);
    inOrder(root->right);
}

main(){
    struct Node *root=getTree();
    inOrder(root);
    printf("\n");
    morrisInorder(root);

}
