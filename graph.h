#define GRAPH struct graph
#define NODE struct node
#define STACK struct stack

STACK{
    //structure of stack
    int vertex;
    STACK *next;
};

NODE{
    //structure of node to describe vertex
    int vertex;
    NODE *next;
};

GRAPH{
    //the list of node's lists
    int numVertices;
    NODE** list;
};

STACK *createStck(int vertex);
NODE *createNode(int vertex);
GRAPH* createGraph(int numVert);

void printStck(STACK *stack);
void push(STACK *stack, STACK *elem);
void addEdge(GRAPH *graph, int start, int end);
void printGraph(GRAPH *graph);
int count(STACK *stack);

