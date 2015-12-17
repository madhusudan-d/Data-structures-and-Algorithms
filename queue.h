#include<stdio.h>

struct List{
    int data;
    struct List *next;
};

struct Queue{
    struct List *head;
    struct List *tail;
};


struct Queue *createQueue(){
    struct Queue *queue1=(struct Queue*)malloc(sizeof(struct Queue));
    queue1->head=queue1->tail=NULL;
    return queue1;
}

struct Queue *createNodeQueue(int data){
    struct List *newNode=(struct List*)malloc(sizeof(struct List));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
enQueue(struct Queue *queue1,int data){
    if(queue1->head==NULL){
        queue1->head=queue1->tail=createNodeQueue(data);
    }
    else{
        struct List *temp=queue1->tail;
        temp->next=createNodeQueue(data);
        queue1->tail=temp->next;
    }
}

printQueue(struct Queue *queue1){
    if(queue1->head==NULL){
        printf("Queue is empty");
    }
    else{
        struct List *temp=queue1->head;
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int  isEmptyQueue(struct Queue *queue1){
    if(queue1->head==NULL)
        return 1;
    else
        return 0;
}

int deQueue(struct Queue *queue1){
    if(queue1->head==NULL){
        printf("no elements in queue");
        return NULL;
    }
    int data=queue1->head->data;
    struct List *temp=queue1->head;
    queue1->head=temp->next;
    free(temp);
    return  data;

}
