#include <stdio.h>
#include "graph.c"

#define MAX_VERT 2000
#define MAX_EDGE (n * (n + 1)) / 2

int check(int n, int m) {
    if (n < 0 || n > MAX_VERT) {
        printf("bad number of vertices");
        return -1;
    }

    if (m < 0 || m > MAX_EDGE) {
        printf("bad number of edges");
        return -1;
    }
    return 0;
}

int check2(int num, int start, int end, int n) {
    if (start == end) {
        printf("bad number of edges");
        return -1;
    }

    if (num != 2) {
        printf("bad number of lines");
        return -1;
    }

    if (start < 1 || start > n || end < 1 || end > n) {
        printf("bad vertex");
        return -1;
    }
    return 0;
}

void dfs(GRAPH *graph, int vrt, char *visited, STACK *res, int cycle) {
    *(visited + vrt) = 'g';
    NODE *tmp = graph->list[vrt];

    while (tmp != NULL) {
        int nextVrt = tmp->vertex;
        if (visited[nextVrt] == 'w' && cycle == 0)
            dfs(graph, nextVrt, visited, res, cycle);
        if (visited[nextVrt] == 'g' && cycle == 0) {
            cycle = 1;
            return;
        }
        tmp = tmp->next;
    }
    *(visited + vrt) = 'b';
    STACK *elemRes = createStck(vrt);
    push(res, elemRes);
}

int main() {
    int n, m, start, end, cycle = 0;
    GRAPH *graph;
    char *visited;
    STACK *res;

    scanf("%d", &n);
    scanf("%d", &m);

    if (check(n, m) == -1)
        return 0;

    res = createStck(-1);
    graph = createGraph(n);
    visited = (char *) malloc(n * sizeof(char));

    for (int i = 0; i < n; ++i) {
        *(visited + i) = 'w';
    }

    for (int i = 0; i < m; ++i) {
        int num;
        num = scanf("%d %d", &start, &end);
        addEdge(graph, start, end);

        if (check2(num, start, end, n) == -1)
            return 0;
    }

    for (int i = 0; i < graph->numVertices; ++i) {
        if (*(visited + i) == 'w')
            dfs(graph, i, visited, res, cycle);
    }

    if (count(res) != graph->numVertices)
        printf("impossible to sort");
    else
        printStck(res);
    return 0;
}
