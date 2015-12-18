#include<stdio.h>
#include "queue.h"
#include "stack.h"

struct adjListNode{
    int dest;
    struct adjListNode *next;
};

struct adjList{
    struct  adjListNode *head;
};


struct Graph{
    int v;
    struct adjList *array;
};

struct adjListNode *createNode(int dest){
    struct adjListNode *newNode=(struct adjListNode*)malloc(sizeof(struct adjListNode));
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}

addEdge(struct Graph *graph,int src,int dest){
    struct adjListNode *newNode=createNode(dest);
    newNode->next=graph->array[src].head;
    graph->array[src].head=newNode;

    //for un-directed graph
    //comment below three lines for directed graph
    newNode=createNode(src);
    newNode->next=graph->array[dest].head;
    graph->array[dest].head=newNode;

}


struct Graph *createGraph(int v){

    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->v=v;
    graph->array=(struct adjList*)malloc(v*sizeof(struct adjList));
    int i=0;
    for(i=0;i<v;i++){
        graph->array[i].head=NULL;
    }
    return graph;
}

printGraph(struct Graph *graph){
    int i;
    for(i=0;i<graph->v;i++){
        struct adjListNode *node=graph->array[i].head;
        printf("adj[%d]:",i);
        while(node){
            printf("->%d",node->dest);
            node=node->next;
        }
        printf("\n");
    }
}

BFS(struct Graph *graph,int v){
    int visited[graph->v];
    int i;
    for(i=0;i<graph->v;i++)
        visited[i]=0;
    struct Queue *Q=createQueue();

    enQueue(Q,v);
    while(!isEmptyQueue(Q)){
            int vertice=deQueue(Q);
            if(!visited[vertice]){
                printf("visited :%d\n",vertice);
                visited[vertice]=1;
                struct adjListNode *node=graph->array[vertice].head;
                while(node){
                    enQueue(Q,node->dest);
                    node=node->next;
                }
            }
    }

}

DFS(struct Graph *graph,int v){
    int visited[graph->v];
    int i;
    for(i=0;i<graph->v;i++){
        visited[i]=0;
    }
    struct Stack *S=createStack();

    pushStack(S,v);

    while(!isEmptyStack(S)){
        int vertice=popStack(S);
        if(!visited[vertice]){
            printf("visited :%d\n",vertice);
            visited[vertice]=1;
            struct adjListNode *node=graph->array[vertice].head;
            while(node){
                pushStack(S,node->dest);
                node=node->next;
            }
        }
    }
}

//this function is for detecting cycle in directed graph.
int hasCycleDirected(struct Graph *graph,int v,int *onstack,int *visited){
    onstack[v]=1;
    visited[v]=1;
    int i;
    for(i=0;i<graph->v;i++){
        printf("-%d-",onstack[i]);
    }
    printf("\n");

    struct adjListNode *node=graph->array[v].head;
    while(node){
        if(!visited[node->dest]){
            return hasCycleDirected(graph,node->dest,onstack,visited);
        }
        else if(onstack[node->dest]){
            return 1;
        }
        node=node->next;
    }
    return 0;

}

//this function is for detecting cycle in undirected graph.
int hasCycleUndirected(struct Graph *graph,int *visited,int v,int parent){
    visited[v]=1;

    struct adjListNode *node=graph->array[v].head;

    while(node){
        if(!visited[node->dest]){
            if(hasCycleUndirected(graph,visited,node->dest,v))
                return 1;
        }
        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if(node->dest!=parent){
            return 1;
        }
        node=node->next;
    }
    return 0;

}


main(){
    int v=5;
    struct Graph *graph=createGraph(v);
    addEdge(graph,0,1);
    addEdge(graph,1,3);
    addEdge(graph,2,1);
    addEdge(graph,2,3);
//    addEdge(graph,3,4);
//    addEdge(graph,4,1);
    printf("\nAdjacency List representation of Graph is\n");
    printGraph(graph);

    printf("\nBFS Traversal\n");
    BFS(graph,0);
    printf("\nDFS Traversal\n");
    DFS(graph,0);
    printf("\n\n");
    int onstack[graph->v];
    int visited[graph->v];
    int i;
    for(i=0;i<graph->v;i++){
        onstack[i]=0;
        visited[i]=0;
    }
    //for directed graph: call hasCycleDirected
    //for undirected graph: call hasCycleUndirected
    if(hasCycleUndirected(graph,visited,0,0))
        printf("\nGraph has cycle \n");
    else
        printf("\nGraph does not have cycle\n");


}

