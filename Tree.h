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

    /*      1
           / \
         2    3
        / \  /
       4   5 6
      /
     7

    */


    a->data=1;
    a->left=b;
    a->right=c;

    b->data=2;
    b->left=d;
    b->right=e;

    c->data=3;
    c->left=f;
    c->right=NULL;

    d->data=4;
    d->left=g;
    d->right=NULL;

    e->data=5;
    e->left=NULL;
    e->right=NULL;

    f->data=6;
    f->left=NULL;
    f->right=NULL;

    g->data=7;
    g->left=NULL;
    g->right=NULL;

    return a;

}

