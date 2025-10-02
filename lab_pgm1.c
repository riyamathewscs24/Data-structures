#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push()
{
    int x;
    printf("Enter data to be inserted:\n");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top]=x;
        printf("%d is inserted into the stack\n",x);
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        item=stack[top];
        top--;
        printf("%d is deleted from the stack\n",item);
    }
}
void peek()
{
   if(top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%d is the top most element of the stack\n",stack[top]);
    } 
}
void display()
{
    printf("Elements of the stack:\n");
    for(int i=0;i<top+1;i++)
    {
        printf("%d \n",stack[i]);
    }
}
void main()
{
    int choice;
    while(1)
    {
        printf("Enter option 1,2,3 or 4 to perform push,pop,peek or exit operation:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
              push();
              display();
              break;
            case 2:
              pop();
              display();
              break;
            case 3:
              peek();
              break;
        }
        if(choice==4)
        {
            printf("Done");
            break;
        }
    }
    
}