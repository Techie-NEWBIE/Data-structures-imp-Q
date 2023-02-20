#include<stdio.h>
int CQ[100],n,i,item,rear,front,choice,next;
void enqueue();
void dequeue();
void main()
{
    printf("\n Enter the size of the array :");
    scanf("%d",&n);
    printf(" \n 1. ENQUEUE \n 2. DEQUEUE \n 3.EXIT ");
    do
    {
       printf("\n Enter your Choice :");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1 :
        {
            enqueue();
            break;
        }
        case 2 :
         {
             dequeue();
             break;
         }
        case 3 :
         {
            break;
         }
        default :
        {
            printf("\n Invalid choice :");
        }
        }
        printf("\n Elements in queue :");
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",CQ[i]);
        }
    } while (choice!=3);
}
void enqueue()
{
    printf("\n Enter a value to be inserted :");
    scanf("%d",&item);
    if(front==0)
    {
        front=1;
        rear=1;
        CQ[front]=item;
    }
    else
    {
        next=(rear % 10)+1;
        if(next!=front)
          {
            rear=next;
            CQ[rear]=item;
          }
        else
         {
            printf("\nCircular queue is full");
         }
    }
}
void dequeue()
{
    if (front==0)
     {
        printf("\n Circular queue is full");
     }
     else
     {
        item=CQ[front];
        if(front==rear)
        {
            front=0;
            rear=0;
        }
        else
        {
            front=(front%10)+1;
        }
     }
}