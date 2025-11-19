// DFS WITH GRAPH PRINT
#include<stdio.h>
#include<stdlib.h>

#define size 10

struct node {
    int data;
    int status;
    struct node *next, *point;
};

struct node *g = NULL;

// add vertex
void addvertex(int n) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = n;
    t->point = NULL;
    t->next = g;
    g = t;
}

// find vertex
struct node* find(int n) {
    struct node *t = g;
    while (t != NULL && t->data != n)
        t = t->next;
    return t;
}

// add edge u->v
void addedge(int u, int v) {
    struct node *v1, *v2, *t;
    v1 = find(u);
    v2 = find(v);

    t = (struct node*)malloc(sizeof(struct node));
    t->next = v1->point;
    t->point = v2;
    v1->point = t;
}

// print graph
void printgraph() {
    struct node *t1, *t2, *t3;

    printf("\nVertex\tEdges\n");
    t1 = g;
    while (t1 != NULL) {
        printf("%d -> ", t1->data);
        t2 = t1->point;
        while (t2 != NULL) {
            t3 = t2->point;
            printf("%d ", t3->data);
            t2 = t2->next;
        }
        printf("\n");
        t1 = t1->next;
    }
}

// DFS Visit
void dfs_visit(struct node *u) {
    struct node *t, *t1;
    u->status = 1;
    printf("%d ", u->data);

    t = u->point;
    while (t != NULL) {
        t1 = t->point;
        if (t1->status == 0)
            dfs_visit(t1);
        t = t->next;
    }
}

// DFS
void dfs(struct node *start) {
    struct node *t = g;
    while (t != NULL) {
        t->status = 0;
        t = t->next;
    }
    dfs_visit(start);
}

void main() {
   	addvertex(1);
	addvertex(2);
	addvertex(3);
	addvertex(4);
	addvertex(5);
	addedge(1,2);
	addedge(1,4);
	addedge(2,3);
	addedge(2,4);
	addedge(4,3);
	addedge(4,5);
    printf("Graph Representation:\n");
    printgraph();

    printf("\nDFS Traversal: ");
    dfs(find(1));
}

