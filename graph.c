#include <stdio.h>
#include <malloc.h>
#include "graph.h"

STACK* createStck(int vertex){
    STACK *stack;
    stack = (STACK *) malloc(sizeof(STACK));
    stack->vertex = vertex;
    stack->next = NULL;
    return stack;
}

NODE* createNode(int vertex){
    //create a vertex of graph
    NODE* newNode = malloc(sizeof(NODE));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

GRAPH* createGraph(int numVert){
    //create graph with creation of lists
    GRAPH* newGraph = malloc(sizeof(GRAPH));
    newGraph->numVertices = numVert;

    newGraph->list = malloc(numVert * sizeof(NODE*));
    for (int i = 0; i < numVert; ++i)
        newGraph->list[i] = NULL;
    return newGraph;
}

void addEdge(GRAPH *graph, int start, int end){
    //add edge between two vertex (
    //an directed graph)
    NODE *node = createNode(end - 1);
    node->next = graph->list[start - 1];
    graph->list[start - 1] = node;
}

void printGraph(GRAPH *graph){
    for (int i = 0; i < graph->numVertices; ++i) {
        NODE *temp = graph->list[i];
        printf("%d: ", i + 1);
        while (temp != NULL){
            printf("%d ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void printStck(STACK *stack){
    STACK *tmp = stack->next;
    while(tmp){
        printf("%d ", tmp->vertex + 1);
        tmp = tmp->next;
    }
}

void push(STACK *stack, STACK *elem){
    STACK *first = stack->next;
    elem->next = first;
    stack->next = elem;
}

int count(STACK *stack){
    int cnt = 0;
    STACK *tmp = stack->next;
    while (tmp != NULL){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
