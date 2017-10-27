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

struct Node* deleteNode(struct Node *head){
    struct Node *temp,*temp1;
    int position;
    int count=countNodes(head);
    printf("enter position\n");
    scanf("%d",&position);
    temp=head;
    if(position==1){
        head=head->next;
    }
    else if(position > count){
            printf("position exceeds max nodes\n");
            return head;
    }
    else{
            position--;
        while(position){
            temp1=temp;
            temp=temp->next;
            position--;
        }
        temp1->next=temp->next;
    }
    free(temp);
    return head;
}

struct Node *reverseRecursion(struct Node *head){
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    struct Node *secondNode=head->next;
    head->next=NULL;
    struct Node *rest=reverseRecursion(secondNode);
    secondNode->next=head;
    return rest;
}

int palUsingRe(struct Node *head,struct Node **first){
    if(head==NULL)
        return 1;
    if(head==*first)
        return 1;
    int res=palUsingRe(head->next,first);
    if(!res)
        return 0;
    int res1;
    if(head->data==(*first)->data){
        res1=1;
    }
    else
        res1=0;
    *first=(*first)->next;
    return res1;

}
//for checking if the loop exist in the linked list//
 int detect loop(struct node** head)
{
struct node* temp1=head;
struct node* temp2=head;
while(temp1&&temp2&&temp2->next)
{
temp1->temp1->next;
temp2=temp2->next->next;
if(temp1==temp2)
return 1;
}
return 0;
}



void main()
{
    int option,count;
    struct Node *HEAD;

 while(1){
    printf("enter option from below\n");
    printf("\n1-create\n2-insert\n3-delete\n4-display\n6-count\n5-reverse using Recursion\n7-check for palindrome\n8-check for loop\n0-exit\n");
    scanf("%d",&option);
    switch(option){

        case 1:
            HEAD=create();
            break;
        case 2:
            HEAD=insertNode(HEAD);
            break;
        case 3:
            HEAD=deleteNode(HEAD);
            break;
        case 4:
            display(HEAD);
            break;
        case 5:
            HEAD=reverseRecursion(HEAD);
            break;
        case 7:
            printf("\npalindrome status : %d\n",palUsingRe(HEAD,&HEAD));
            break;
        case 8:
            printf("\nloop status: %d\n",detectloop(&HEAD));
            break;
        case 0:
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


