#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* create(){
    int choice=1,item;
    struct Node *head,*temp=0,*newNode;
    head=0;

    while(choice){

        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("enter data\n");
        scanf("%d",&item);
        newNode->data=item;

        if(head!=0){
            temp->next=newNode;
            temp=newNode;
        }
        else{
            head=temp=newNode;
        }

        printf("To continue enter any number ,else enter 0 to exit\n");
        scanf("%d",&choice);

    }
    temp->next=NULL;
    return head;

}

display(struct Node *head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("\n");

}

struct Node* insertNode(struct Node *head){
    int position;
    struct Node *newNode,*temp,*temp1;
    int count=countNodes(head);
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter data\n");
    scanf("%d",&newNode->data);
    printf("enter position \n");
    scanf("%d",&position);
    if(position==1){
        newNode->next=head;
        head=newNode;
        return head;
    }
    else if(position > count+1){
        printf("position exceeds max nodes\n");
        return head;
    }
    else{

        temp=head;
        position--;
        while (position){
            temp1=temp;
            temp=temp->next;
            position--;
        }
        newNode->next=temp;
        temp1->next=newNode;
    }
    return head;

}

int countNodes(struct Node *head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}

void main()
{
    int option,count;
    struct Node *HEAD;

 while(1){
    printf("enter option from below\n");
    printf("\n1-create\n2-insert\n3-delete\n4-display\n6-count\n5-exit\n");
    scanf("%d",&option);
    switch(option){

        case 1:
            HEAD=create();
            break;
        case 2:
            HEAD=insertNode(HEAD);
            break;
        case 3:
            deleteNode();
            break;
        case 4:
            display(HEAD);
            break;
        case 5:
            exit(0);
        case 6:
            count=countNodes(HEAD);
            printf("Number of nodes = %d\n",count);
        default:
            printf("Invalid option");
            break;
    }
 }

}


