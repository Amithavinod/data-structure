#include<stdio.h>
#include<stdlib.h>
struct bit{unsigned char x:1;};
int uset[]={1,2,3,4,5,6,7,8,9},size=9;
void main()
{
   void readset (struct bit[],int n);
   void printset(struct bit[]);
   void unionset(struct bit[],struct bit[],struct bit[]);
   void intersect(struct bit[],struct bit[],struct bit[]);
   void difference(struct bit[],struct bit[],struct bit[]);
   struct bit a[10]={0},b[10]={0},c[10]={0};
   int n;
   printf("No of elements in SET A:");
   scanf("%d,",&n);
   readset(a,n);
   printf("No of elements in SET B:");
   scanf("%d,",&n);
   readset(b,n);
   printf("Set A:"),printset(a);
   printf("Set B:"),printset(b);
   unionset(a,b,c);
   printf("AUB is:"),printset(c);
   intersect(a,b,c);
   printf("A intersect B is:"),printset(c);
   difference(a,b,c);
   printf("A-B is:"),printset(c);
}
//to read a set
void readset(struct bit a[],int n)
{
   int i,j,k;
   printf("Enter the %d numbers",n);
   for(i=0;i<n;i++)
   {
   scanf("%d",&j);
   for(k=0;k<size;++k)
   if(uset[k]==j)
   {
   a[k].x=1;
   break;
   }
   }
   return;
}
//to print a set
void printset(struct bit a[])
{
   int k;
   printf("{");
   for(k=0;k<size;++k)
   if( a[k].x==1)
   printf("%d,",uset[k]);
   printf("}\n");
   return;
}
//union operation
void unionset(struct bit a[],struct bit b[],struct bit c[])
{
   int k;
   for(k=0;k<size;++k)
   c[k].x=a[k].x | b[k].x;
   return;
}
//intersection operation
void intersect(struct bit a[],struct bit b[],struct bit c[])
{
	int k;
	for(k=0;k<size;++k)
	c[k].x=a[k].x & b[k].x;
	return;
}
//difference operation
void difference(struct bit a[],struct bit b[],struct bit c[])
{
	int k;
	for(k=0;k<size;++k)
	if(a[k].x==1)
	c[k].x=a[k].x ^ b[k].x;
	return;
}

