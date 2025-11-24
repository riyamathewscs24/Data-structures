#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head1=NULL,*head2=NULL;
struct Node  *createList(int n)
{
    struct Node *head=NULL,*newNode,*temp;
    int data,i;
    for(i=1;i<=n;i++)
    {
        newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL)
        {
            printf("Mmeory allocation failed");
            exit(0);
        }
        printf("Enter data for node%d:",i);
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            temp->next=newNode;
        }
        temp=newNode;
    }
    printf("Linked list created sucessfully\n");
    return head;
}
void displayList(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void sortList(struct Node *head)
{
    struct Node *i,*j;
    int temp;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data>j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
    printf("Linked list sorted sucessfully\n");
}
struct Node *reverseList(struct Node *head)
{
    struct Node *prev=NULL,*curr=head,*next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    printf("Linked list reversed successfully\n");
    return prev;
}
struct Node *concatenate(struct Node *head1,struct Node *head2)
{
    struct Node *temp;
    if(head1==NULL)
     return head2;
    if(head2==NULL)
     return head1;
    temp=head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    printf("Linked list concatenated successfully\n");
    return head1;
}
int main()
{
    int choice,n,m;
    while(1)
    {
        printf("\n-------Singly Linked List Operations------------\n");
        printf("1.Create first and second Linked Lists\n");
        printf("2.Display first and second Linked lists\n");
        printf("3.Sort first list\n");
        printf("4.Reverse first list\n");
        printf("5.Concatenate two lists\n");
        printf("6.Display concatenated list\n");
        printf("7.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
              printf("Enter no of nodes for first list:");
              scanf("%d",&n);
              head1=createList(n);
              printf("Enter no of nodes for second list:");
              scanf("%d",&m);
              head2=createList(m);
              break;
            case 2:
               printf("First linked list:\n");
               displayList(head1);
               printf("Second Linked list:\n");
               displayList(head2);
               break;
            case 3:
              sortList(head1);
              printf("Sorted List:");
              displayList(head1);
              break;
            case 4:
               head1=reverseList(head1);
               printf("Reversed list:");
               displayList(head1);
               break;
            case 5:
               head1=concatenate(head1,head2);
               head2=NULL;
               break;
            case 6:
                printf("Concatenated Linked list:");
                displayList(head1);
                break;
            case 7:
               printf("Exiting program\n");
               exit(0);
            default:
               printf("Invalid choice\n");
        }
    }
    return 0;
}