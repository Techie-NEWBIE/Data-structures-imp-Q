#include<stdio.h>
 struct poly
 {
int coeff;
int expo;
 } x1[10],x2[10],x3[10];
 int readPoly(struct poly []);
 int subPoly(struct poly [],struct poly [],int ,int ,struct poly []);
 void displayPoly( struct poly [],int terms);
 int main()
 {
int m,n,t;
m=readPoly(x1);
printf(" \n First polynomial : ");
displayPoly(x1,m);
n=readPoly(x2);
printf(" \n Second polynomial : ");
displayPoly(x2,n);
t=subPoly(x1,x2,m,n,x3);
printf(" \n Resultant polynomial after subtraction : ");
displayPoly(x3,t);
printf("\n");
return 0;
 }
 int readPoly(struct poly x[10])
 {
int m,i;
printf("\n\n Enter the total number of terms in the polynomial:");
scanf("%d",&m);
printf("\n Enter the coffecient and exponent in descending order\n");
for(i=0;i<m;i++)
{
printf("   Enter the Coefficient(%d): ",i+1);
scanf("%d",&x[i].coeff);
printf("      Enter the exponent(%d): ",i+1);
scanf("%d",&x[i].expo);    
}
return(m);
}
 int subPoly(struct poly x1[10],struct poly x2[10],int m,int n,struct poly x3[10])
 {
int i,j,k;
i=0;
j=0;
k=0;
while(i<m && j<n)
{
if(x1[i].expo==x2[j].expo)
{
x3[k].coeff=x1[i].coeff - x2[j].coeff;
x3[k].expo=x1[i].expo;
i++;
j++;
k++;
}
else if(x1[i].expo>x2[j].expo)
{
x3[k].coeff=x1[i].coeff;
x3[k].expo=x1[i].expo;
i++;
k++;
}
else
{
x3[k].coeff=x2[j].coeff;
x3[k].expo=x2[j].expo;
j++;
k++;
}
}
while(i<m)
{
x3[k].coeff=x1[i].coeff;
x3[k].expo=x1[i].expo;
i++;
k++;
}
while(j<n)
{
x3[k].coeff=x2[j].coeff;
x3[k].expo=x2[j].expo;
j++;
k++;
}
return(k);
 }
 void displayPoly(struct poly x[10],int term)
 {
int k;
for(k=0;k<term-1;k++)
printf("%d(x^%d)+",x[k].coeff,x[k].expo);
printf("%d(x^%d)",x[term-1].coeff,x[term-1].expo);
}