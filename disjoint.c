#include<stdio.h>
#include<stdlib.h>
//disjoint set representation
//structure to represention object of a set in linked representation
struct node
{
	int value;
	struct rep*repptr;//pointer to header node of the list
	struct rep*next;
};
//structure to represent header node of linked representation of set
struct rep
{
	struct node*head;
	struct node*tail;
};
//structure to store key and object node pointer
struct nodaddr
{	
	int key;
	struct node*obj_node_ptr;
	struct nodaddr*next;
};
struct nodaddr*ndr=0;//list to store keys and objects
void makeset(int a)
{
//create a object node pointer
struct nodaddr*t=(struct nodaddr*)malloc(sizeof(struct nodaddr));
//create a newset
struct rep*newset=(struct rep*)malloc(sizeof(struct rep));
struct node*n=(struct node*)malloc(sizeof(struct node));
//fill values
n->value=a;
n->repptr=newset;
n->next=0;
//initalize head and tail
newset->head=newset->tail=n;
//to store object node pointer and key
t->obj_node_ptr=n;
t->key=a;
t->next=ndr;
ndr=t;
}
//function to return pointer of the representation (header node)of the set containing x
struct rep*find(int x)
{
	struct nodaddr*t=ndr;
	while(t!=0 && t->key!=x)
		t=t->next;
	return t->obj_node_ptr->repptr;
}
//to find union of two sets corresponding to objects given
void unionset(int key1,int key2)
{
	struct rep*set1,*set2;
	struct node*t1;
	set1=find(key1);
	set2=find(key2);
	if(set1==set2)
		printf("\n%d and %dbelongs to same set\n",key1,key2);
	else//changing header pointer of objects of objects of set2 to that of set 1
	{
	t1=set2->head;
	while(t1!=0)
	{
	t1->repptr=set1;
	t1=t1->next;
	}
	set1->tail->next=set2->head;
	set1->tail=set2->tail;//set the tail of the set 1 to tail of set 2
	free(set2);
	}
}
//function to display a set
void display_set(int a)
{
	struct rep*r;
	struct node*t;
	r=find(a);
	t=r->head;
	printf("set members containing %d:",a);
	while(t!=0)
	{
		printf("%d,",t->value);
		t=t->next;
	}
}
void main()
{
 makeset(10);
 makeset(20);
 makeset(30);
 makeset(40);
 makeset(50);
 printf("\nfind(10)=%X",find(10));
 printf("\nfind(20)=%X",find(20));
 printf("\nfind(30)=%X",find(30));
 printf("\nfind(40)=%X",find(40));
 unionset(10,20);
 printf("\nafter union of 10 and 20 find(20)=%X",find(20));
 unionset(30,40);
 printf("\nafter union of 30 and 40 find(40)=%X",find(40));
 unionset(20,40);
 printf("\n after union of set containing 20 and the set contaning 40 find(40)=%X\n",find(40));
 display_set(40);
}
 
 
 
 
 	

