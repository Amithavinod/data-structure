// BFS WITH GRAPH PRINT
#include<stdio.h>
#include<stdlib.h>

#define size 10

struct node {
    int data;
    int status;
    struct node *next, *point;
};

struct node *g = NULL;
struct node *q[size];
int front = 0, rear = 0;

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

// queue operations
void enqueue(struct node *s) {
    int r1 = (rear + 1) % size;
    if (r1 == front) {
        printf("Queue full");
        exit(1);
    }
    rear = r1;
    q[rear] = s;
}

int emptyqueue() {
    return front == rear;
}

struct node* dequeue() {
    if (emptyqueue()) {
        printf("Queue Empty");
        exit(1);
    }
    front = (front + 1) % size;
    return q[front];
}

// BFS
void bfs(struct node *start) {
    struct node *u, *t, *t1, *v;

    // set all vertices not visited
    v = g;
    while (v != NULL) {
        v->status = 0;
        v = v->next;
    }

    start->status = 1;
    printf("%d ", start->data);

    enqueue(start);

    while (!emptyqueue()) {
        u = dequeue();
        t = u->point;

        while (t != NULL) {
            t1 = t->point;
            if (t1->status == 0) {
                printf("%d ", t1->data);
                t1->status = 1;
                enqueue(t1);
            }
            t = t->next;
        }
    }
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

    printf("\nBFS Traversal: ");
    bfs(find(1));
}

