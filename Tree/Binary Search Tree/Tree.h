#include<stdio.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *getTree(){
    struct Node *a,*b,*c,*d,*e,*f,*g;
    a=(struct Node*)malloc(sizeof(struct Node));
    b=(struct Node*)malloc(sizeof(struct Node));
    c=(struct Node*)malloc(sizeof(struct Node));
    d=(struct Node*)malloc(sizeof(struct Node));
    e=(struct Node*)malloc(sizeof(struct Node));
    f=(struct Node*)malloc(sizeof(struct Node));
    g=(struct Node*)malloc(sizeof(struct Node));

    /*      10
           / \
         7    12
        / \  /
       5   9 11
      /
     4

    */


    a->data=10;
    a->left=b;
    a->right=c;

    b->data=7;
    b->left=d;
    b->right=e;

    c->data=12;
    c->left=f;
    c->right=NULL;

    d->data=5;
    d->left=g;
    d->right=NULL;

    e->data=9;
    e->left=NULL;
    e->right=NULL;

    f->data=11;
    f->left=NULL;
    f->right=NULL;

    g->data=4;
    g->left=NULL;
    g->right=NULL;

    return a;

}


