#include<stdio.h>
void quicksort(int a[10],int left,int right)
{
  int i,j,pivot,temp;
  if(left<right)
 {
   pivot=left;
   i=left;
   j=right;
 while(i<j)
   {
     while(a[i]<=a[pivot]&&i<right)
     i++;
     while(a[j]>a[pivot])
     j--;
     if(i<j)
   {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
   }
   }
   temp=a[pivot];
   a[pivot]=a[j];
   a[j]=temp;
   quicksort(a,left,j-1);
   quicksort(a,j+1,right);
 }
}
int linearsearch(int a[],int n,int key)
{
int loc;
loc=0;
while(loc<n)
{
if(a[loc]==key)
{
return loc;
}
loc++;
}
return -1;
}
   int main()
  {
       int i,n,a[10],p,key;
       printf("Enter the size of array");
       scanf("%d",&n);
       printf("Enter the elements");
       for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
        quicksort(a,0,i-1);
        printf("Sorted array");
        for(i=0;i<n;i++)
      {
        printf("  %d  ",a[i]);
      }
printf("\n Enter the element to  be searched: ");
scanf("%d",&key);
p=linearsearch(a,n,key);
if (p==-1)
printf("the element not found");
else
printf("The element %d is found at index %d.\n",key,p);
   return 0;
   }
