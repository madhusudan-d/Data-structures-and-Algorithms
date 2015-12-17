
//link for detailed question http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/

#include<stdio.h>
#include "Tree.h"

void printKDistanceDown(struct Node *root,int k){
    if(root==NULL||k<0)
        return;
    if(k==0){
        printf("found Node - %d - \n",root->data);
        return;
    }
    printKDistanceDown(root->left,k-1);
    printKDistanceDown(root->right,k-1);
}

int printKDistanceNodes(struct Node *root,int target,int k){
    if(root==NULL)
        return -1;
    if(root->data==target){
        printKDistanceDown(root,k);
        return 0;
    }
    int left=printKDistanceNodes(root->left,target,k);

    if(left!=-1){
        if(left+1==k)
            printf("found Node u -%d-\n",root->data);
        else
            printKDistanceDown(root->right,k-left-2);

        return  left+1;
    }

    int right=printKDistanceNodes(root->right,target,k);
    if(right!=-1){

        if(right+1==k)
            printf("found Node u -%d-\n",root->data);
        else
            printKDistanceDown(root->left,k-right-2);

        return  right+1;

    }


    return -1;


}

inOrder(struct Node *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    inOrder(root->left);

    inOrder(root->right);

}




main(){
    struct Node *root=getTree();
    inOrder(root);
    printf("\n");
    int target=7;
    int a=printKDistanceNodes(root,target,5);
}
