#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
};
void main()
{
struct node*start=(struct node*)0;
struct node*insert(struct node*,int);
struct node*delete(struct node*,int);
void display(struct node*);
struct node*search(struct node*,int);
int item,opt;
while(1)
{
   printf("\n 1.insert\n 2.delete\n 3.display\n 4.search\n 5.exit\n");
   printf("your option:");
   scanf("%d",&opt);
   switch(opt)
   {
   case 1: printf("item to insert:");
           scanf("%d",&item);
           start=insert(start,item);
           break;
   case 2: printf("item to delete:");
           scanf("%d",&item);
           start=delete(start,item);
           break;
   case 3: display(start);
           break;
   case 4: printf("item to search");
           scanf("%d",&item);
           if(search(start,item)==(struct node*)0)
           printf("\ndata not found");
           else
           printf("\ndata found");
           break;
   case 5: exit(0);
   }
}
}
//function to insert
struct node* insert(struct node*s,int data)
{
 struct node*t;
 t=(struct node*)malloc(sizeof(struct node));
 t->data=data;
 t->left=(struct node*)0;
 t->right=s;
 if(s!=0)
  s->left=t;
 return t;
}
//function to search
struct node*search(struct node*s,int data)
{
 while(s!=(struct node*)0 && data!= s->data)
 s=s->right;
 return s;
}         
//function to delete
struct node*delete(struct node*s,int data)
{
 struct node*t;
 t=search(s,data);
 if(t==0)
  printf("data not found\n");
 else
 {
  if(t->left==0)//first node
  {
   s=s->right;//move pointer to next node
   if(t->right!=0)
    s->left=0;
  }
  else
  {
   t->left->right=t->right;
   if(t->right!=0)
     t->right->left=t->left;
  }
  free(t);
 }
 return s;
}

//function to display list contents
void display(struct node*s)
{
while(s!=(struct node*)0)
{
printf("%d ",s->data);
s=s->right;
}
return;
} 
