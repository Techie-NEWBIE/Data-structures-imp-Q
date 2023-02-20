#include<stdio.h>
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
int linearsearch(int[],int,int);
int n; 
int main()
{
  int a[30],i,key,p;
  printf("Enter the NO of elements in array : ");
  scanf("%d",&n);
  printf("Enter the elements : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  mergesort(a,0,n-1);
  printf("\n sorted array is : ");
  for(i=0;i<n;i++)
  printf("%d ",a[i]);
  printf("\n");
  printf("\n Enter the element to be searched :");
  scanf("%d",&key);
  p=linearsearch(a,n,key);
  if(p==-1)
  {
    printf("The element does not exits in the array ");
  }
  else
  {
    printf("The element %d exist in array at index %d ",key,p);
  }
  return 0;
}


void mergesort(int a[],int i,int j)
{
int mid;
if(i<j) 
{
mid=(i+j)/2;
mergesort(a,i,mid);
mergesort(a,mid+1,j);
merge(a,i,mid,mid+1,j);
}
}
void merge(int a[],int i1,int i2,int j1,int j2)
{
int temp[50];
int i=i1,j=j1,k=0;
while(i<=i2 && j<=j2)
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=i2)
temp[k++]=a[i++];
while(j<=j2)
temp[k++]=a[j++];
for(i=i1,j=0;i<=j2;i++,j++)
a[i]=temp[j];
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
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