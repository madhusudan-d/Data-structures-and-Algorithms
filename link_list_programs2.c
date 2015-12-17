#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createList(){
    struct Node *a,*b,*c,*d,*e,*f,*g,*h;
    a=(struct Node *)malloc(sizeof(struct Node));
    b=(struct Node *)malloc(sizeof(struct Node));
    c=(struct Node *)malloc(sizeof(struct Node));
    d=(struct Node *)malloc(sizeof(struct Node));
    e=(struct Node *)malloc(sizeof(struct Node));
    f=(struct Node *)malloc(sizeof(struct Node));
    g=(struct Node *)malloc(sizeof(struct Node));
    h=(struct Node *)malloc(sizeof(struct Node));
    a->data=1;a->next=b;
    b->data=2;b->next=c;
    c->data=3;c->next=d;
    d->data=4;d->next=e;
    e->data=5;e->next=f;
    f->data=6;f->next=g;
    g->data=7;g->next=h;
    h->data=8;h->next=NULL;
    return a;
}

printList(struct Node *head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n\n");

}

struct Node *reverseInGroups(struct Node *cur,int k){
    int count=0;
    struct Node *nextNode=NULL,*prevNode=NULL,*head=cur;


        while(head!=NULL && count<k ){
            nextNode=head->next;
            head->next=prevNode;
            prevNode=head;
            head=nextNode;
            count++;
        }
        if(nextNode!=NULL)
            cur->next=reverseInGroups(nextNode,k);


    return prevNode;

}

int hasKnodes(struct Node *head,int k){
    int count=0;
    while(head && count<k){
        head=head->next;
        count++;
    }
    if(count==k)
        return 1;

    return 0;
}

struct Node *GetKPlusOnethNode(int k,struct Node *cur){
    int count =0;
    struct Node *head=cur;
    if(!head)
        return head;

    while(count<k && head){
        head=head->next;
        ++count;
    }
    if(k==count && head!=NULL)
        return head;
    return cur->next;

}

struct Node *reverseInGroups2(struct Node *cur,int k){

    struct Node *nextNode=NULL,*newHead=NULL,*head=cur,*prev=NULL;
    int count=0;
    if(hasKnodes(head,k-1))
        newHead=GetKPlusOnethNode(k-1,head);
    else
        return newHead=head;

    while( hasKnodes(head,k) && head){
         count=0;
        prev=GetKPlusOnethNode(k,head);
        //printf("nn = %d\n",prev->data);
        while(count<k){
            nextNode=head->next;
            head->next=prev;
            prev=head;
            head=nextNode;
            count++;
        }

    }
    return newHead;
}


main(){
    struct Node *head=createList();
    printList(head);
    struct Node *rg=reverseInGroups2(head,3);
    printList(rg);



}
