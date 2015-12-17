
#include<stdio.h>

struct List{
    int data;
    struct List *next;
};
struct List* sortAndMerge(struct List *first,struct List *second){
    struct List *result=NULL;
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;
    if(first->data<=second->data){
        result=first;
        result->next=sortAndMerge(result->next,second);
    }
    else{
        result=second;
        result->next=sortAndMerge(first,result->next);
    }
    return result;
}


mergeSort(struct List **headr){
    struct List *a,*b;
    struct List *h=*headr;
    if(h==NULL||h->next==NULL)
        return ;
    splitList(h,&a,&b);
    mergeSort(&a);
    mergeSort(&b);
    *headr=sortAndMerge(a,b);
}

splitList(struct List *head,struct List **first,struct List **second){
    struct List *slow;
    struct List *fast;
    if(head==NULL||head->next==NULL){
        first=head;
        second=NULL;
        return;
    }


    slow=head;
    fast=head->next;
    while(fast){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    *first=head;
    *second=slow->next;
    slow->next=NULL;
}

main(){
    struct List *a,*b,*c,*d,*e;
    a=(struct List*)malloc(sizeof(struct List));
    a->data=5;
    b=(struct List*)malloc(sizeof(struct List));
    b->data=4;
    c=(struct List*)malloc(sizeof(struct List));
    c->data=3;
    d=(struct List*)malloc(sizeof(struct List));
    d->data=2;
    e=(struct List*)malloc(sizeof(struct List));
    e->data=1;
    a->next=b;b->next=c;c->next=d;d->next=e;e->next=NULL;
    struct List *head=a;
    while(head){
        printf("%d ->",head->data);
        head=head->next;
    }

    mergeSort(&a);
    printf("\nafter sorting\n");
    head=a;
    while(head){
        printf("%d ->",head->data);
        head=head->next;
    }

}
