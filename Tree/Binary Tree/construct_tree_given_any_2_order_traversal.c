
#include<stdio.h>

struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *createNode(int data){
    struct Tree *node=(struct Tree*)malloc(sizeof(struct Tree));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
int searchIN(int data,int IN[],int beg,int end){
    int i;
    for(i=beg ;i<=end+1;i++){
        if(data==IN[i])
            return i;
    }
    printf("error :search IN\n");
    exit(0);
}

struct Tree *constructTreeWithInPr(int IN[],int PR[],int inBeg,int inEnd,int prEnd){

    static int prBeg=0;
    if(inBeg>inEnd)
        return NULL;
    struct Tree *root=createNode(PR[prBeg]);

    prBeg++;
     printf(" root :%d \n",root->data);
    if(inBeg==inEnd)
        return root;

    int inLoc=searchIN(root->data,IN,inBeg,inEnd);
    root->left=constructTreeWithInPr(IN,PR,inBeg,inLoc-1,prEnd);
    root->right=constructTreeWithInPr(IN,PR,inLoc+1,inEnd,prEnd);

    return root;
}

printIn(struct Tree *root){
    if(root==NULL)
        return;

    printIn(root->left);
    printf("-%d-",root->data);
    printIn(root->right);
}

rootToLeaf(struct Tree *root,int arr[],int n){
    if(root==NULL)
        return;
    arr[n]=root->data;
        n++;

    if(root->left==NULL && root->right==NULL){
            int i;
        for(i=0;i<n;i++)
            printf("%d-",arr[i]);
        printf("\n");
    }


        rootToLeaf(root->left,arr,n);
        rootToLeaf(root->right,arr,n);



}

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int diameter(struct Tree *root,int *height){
    int lh=0,rh=0;
    int ld=0,rd=0;
    if(root==NULL){
        *height=0;
        return 0;
    }
    ld=diameter(root->left,&lh);
    rd=diameter(root->right,&rh);
    *height=max(lh,rh)+1;
    return max(lh+rh+1,max(ld,rd));
}


main(){
    int IN[]={8,6,4,2,5,7,1,3};
    int PR[]={1,2,4,6,8,5,7,3};
    int in=sizeof(IN)/sizeof(IN[0]);
    int pn=sizeof(PR)/sizeof(PR[0]);

    struct Tree *root=constructTreeWithInPr(IN,PR,0,in-1,pn-1);

    printIn(root);
    printf("\n");
    int arr[5];
    rootToLeaf(root,arr,0);
    int a=0;
    int d=diameter(root,&a);
    printf("diameter is : %d \n",d);
}
