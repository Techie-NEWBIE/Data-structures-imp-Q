#include<stdio.h>
#include<stdlib.h>

struct Node
{
int Data;
struct Node *next;
} *header, *ptr, *node, *prev;
struct Node *getNode()
{
node=(struct Node *)malloc(sizeof(struct Node));
return node;
}


void InsertFront(int X)
{
node=getNode();
if (node==NULL) 
printf("\nMemory not available,insertion not possible!\n");
else
{
node->next=header->next;
node->Data=X;
header->next=node;
}
}


void InsertEnd(int X)
{
node=getNode();
if (node==NULL) 
printf("\nMemory not available,insertion not possible!\n");
else
{
ptr=header;
while (ptr->next!=NULL)
{
ptr=ptr->next;
}
node->Data=X;
node->next=NULL;
ptr->next=node;
}
}


void InsertAny(int X,int key)
{
node=getNode();
if (node==NULL) 
printf("\nMemory not available!\n");
else
{
ptr=header;
printf("\nEnter the key: ");
scanf("%d",&key);
while (ptr->next!=NULL && ptr->Data!=key)
{
ptr=ptr->next;
}
if (ptr->next==NULL) 
printf("\nKey not found!\n");
else
{
printf("\nEnter the number to be inserted: ");
scanf("%d",&X);
node->Data=X;
node->next=ptr->next;
ptr->next=node;
}
}
}


void DeleteFront()
{
ptr=header->next;
if (ptr==NULL) 
printf("\nLinked List is empty!\n");
else
{
header->next=ptr->next;
//return(ptr);
}
}


void DeleteEnd()
{
ptr=header;
if (ptr->next==NULL) 
printf("\nLinked List is empty!\n");
else
{
while(ptr->next!=NULL)
{
prev=ptr;
ptr=ptr->next;
}
prev->next=NULL;
//return(ptr);
}
}


void DeleteAny(int key)
{
prev=header;
ptr=header;
if (ptr->next==NULL) 
printf("\nLinked List is empty!\n");
else
{
printf("\nEnter the key: ");
scanf("%d",&key);
while (ptr->Data!=key && ptr->next!=NULL)
{
prev=ptr;
ptr=ptr->next;
}
if (ptr->next==NULL) 
printf("\nKey not found!\n"); 
else 
{
prev->next=ptr->next; 
}
}
}


void display()
{
ptr=header->next;
if (ptr==NULL) 
printf("\nLinked List is Empty!\n");
while(ptr!=NULL)
{
printf("%d->",ptr->Data);
ptr=ptr->next;
}
printf("\n");
}


void main()
{
int c,X,ch=1,key;
header=getNode();
header->Data=0;
header->next=NULL;
while (ch==1)
{ 
printf("Linked List:\n");
display();
printf("\n\t\t***MENU***\n1. Insert Front\n2. Insert End\n3. Insert Anywhere\n4. Delete Front\n5. Delete End\n6. Delete Anywhere \n7. Transversal \nEnter your choice: ");
scanf("%d",&c);
switch(c)
{
case 1: 
printf("\nInsert Front!");
printf("\nEnter the number to be inserted: ");
scanf("%d",&X);
InsertFront(X);
break;
case 2: 
printf("\nInsert End!");
printf("\nEnter the number to be inserted: ");
scanf("%d",&X);
InsertEnd(X);
break;
case 3: 
printf("\nInsert Anywhere!");
InsertAny(X,key);
break;
case 4: 
printf("\nDelete Front!");
DeleteFront();
break;
case 5: 
printf("\nDelete End!");
DeleteEnd();
break;
case 6: 
printf("\nDelete Any!");
DeleteAny(key);
break;
case 7:
printf("\n traversal");
//traversal();
display();
break;

default:printf("\nNot a Invalid Choice!\n");
}
printf("\nDo you want to continue?(1/0): ");
scanf("%d",&ch);
printf("\n");
}
}