#include<stdio.h>
#include<stdlib.h>
struct node
{
int coeff;
int exp;
struct node *link;
}*P_start,*Q_start,*R_start,*newnode,*ptr,*temp,*Pptr,*Qptr,*Rptr,*start;

struct node* insert(struct node *start,int co,int ex)
{
if(start==NULL)
{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->coeff=co;
newnode->exp=ex;
newnode->link=NULL;
start=newnode;
}
else
{
ptr=start;
while(ptr->link!=NULL)
{
ptr=ptr->link;
}
temp=(struct node *)malloc(sizeof(struct node));
temp->coeff=co;
temp->exp=ex;
temp->link=NULL;
ptr->link=temp;
}
return start;
}

struct node* create(struct node* start)
{
int i,n,ex,co;
printf("\nENTER NUMBER OF TERMS:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("ENTER COEFFICIENT OF TERM %d:\n",i);
scanf("%d",&co);
printf("ENTER EXPONENT OF TERM %d:\n",i);
scanf("%d",&ex);
start=insert(start,co,ex);
}
return start;
}

struct node* poly_add(struct node* start1,struct node*start2,struct node* start3)
{
Pptr=start1;
Qptr=start2;
while(Pptr!=NULL&&Qptr!=NULL)
{
if(start3==NULL)
{
start3=(struct node*)malloc(sizeof(struct node));
Rptr=start3;
}
else
{
Rptr->link=(struct node *)malloc(sizeof(struct node));
Rptr=Rptr->link;
}
if(Pptr->exp==Qptr->exp)
{
Rptr->coeff=Pptr->coeff+Qptr->coeff;
Rptr->exp=Pptr->exp;
Pptr=Pptr->link;
Qptr=Qptr->link;
start=insert(start,Rptr->coeff,Rptr->exp);
}
else if(Pptr->exp>Qptr->exp)
{
Rptr->coeff=Pptr->coeff;
Rptr->exp=Pptr->exp;
Pptr=Pptr->link;
start=insert(start,Rptr->coeff,Rptr->exp);
}
else
{
Rptr->coeff=Qptr->coeff;
Rptr->exp=Qptr->exp;
Qptr=Qptr->link;
start=insert(start,Rptr->coeff,Rptr->exp);
}
}
if(Pptr==NULL)
{
while(Qptr!=NULL)
{
Rptr->coeff=Qptr->coeff;
Rptr->exp=Qptr->exp;
Qptr=Qptr->link;
start=insert(start,Rptr->coeff,Rptr->exp);
}
}
else
{
if(Qptr==NULL)
{
while(Pptr!=NULL)
{
Rptr->coeff=Pptr->coeff;
Rptr->exp=Pptr->exp;
Pptr=Pptr->link;
start=insert(start,Rptr->coeff,Rptr->exp);
}
}
}
return start;
}

void display(struct node* start)
{
ptr=start;
while (ptr != NULL)
{
ptr->exp != 0 ? printf(" %dx^(%d)", ptr->coeff, ptr->exp) : printf(" %d", ptr->coeff);
(ptr->link != NULL && ptr->link->coeff > 0) ? 
printf("+") : printf("");
ptr = ptr->link;
}
printf("\b");
}

void main()
{
char c;
int ch;
do
{
P_start=NULL;
Q_start=NULL;
R_start=NULL;
printf("1.POLYNOMIAL ADDITION\t2.EXIT\n");
printf("ENTER YOUR CHOICE\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("POLYNOMIAL 1:\n");
P_start=create(P_start);
printf("POLYNOMIAL 2:\n");
Q_start=create(Q_start);
R_start=poly_add(P_start,Q_start,R_start);
printf("\nPOLYNOMIAL 1: ");
display(P_start);
printf("\nPOLYNOMIAL 2: ");
display(Q_start);
printf("\nADDED POLYNOMIAL: ");
display(R_start);
break;
case 2:
break;
}
printf("\nDO YOU WANT TO CONTINUE(y/n)");
scanf(" %c",&c);
}
while(ch!=2);
}
