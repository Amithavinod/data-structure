//merging two arrays
#include<stdio.h>
void main()
{
   int arr1[20],arr2[20],arr3[40],n1,n2;
   void readdata(int[],int);
   void sortdata(int[],int);
   void printdata(int[],int);
   void mergedata(int[],int[],int[],int,int);
   printf("Number of elements in the first arrary[1-20]:");
   scanf("%d,",&n1);
   readdata(arr1,n1);
   printf("Number of elements in the second array[1-20]:");
   scanf("%d,",&n2);
   readdata(arr2,n2);
   sortdata(arr1,n1);
   sortdata(arr2,n2);
   mergedata(arr1,arr2,arr3,n1,n2);
   printf("Sorted array1:");
   printdata(arr1,n1);
   printf("Sorted array2:");
   printdata(arr2,n2);
   printf("Merged array:");
   printdata(arr3,n1+n2);
}
void readdata(int a[],int n)
{
   int i;
   printf("Enter the %d numbers",n);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   return;
}
void printdata(int a[],int n)
{
   int i;
   for(i=0;i<n;i++)
      printf("%d,",a[i]);
   return;
}
void sortdata(int a[],int n)
{
   int i,j,t;
   for(i=0;i<n-1;i++)
   for(j=i+1;j<n;j++)
   if(a[i]>a[j])
   { 
      t=a[i];
      a[i]=a[j];
      a[j]=t;
   }
   return;
}
void mergedata(int a[],int b[],int c[],int n1,int n2)
{
   int i,j,k;
   i=j=k=0;
   while(i<n1 && j<n2)
      if(a[i]<b[j])
      {
         c[k]=a[i];
         i++;
         k++;
      }
      else
      {
         c[k]=b[j];
         j++;
         k++;
      }
   while(i<n1)
   {
      c[k]=a[i];
      i++;
      k++;
   }
   while(j<n2)
   {
      c[k]=b[j];
      j++;
      k++;
   }
   return;
}
      
