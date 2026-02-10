#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int adjMatrix[MAX][MAX];
    int numVertices;
} Graph;

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    // Undirected graph
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

// Queue for BFS
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void BFS(Graph* g, int startVertex) {
    bool visited[MAX] = {false};
    Queue q;
    initQueue(&q);

    visited[startVertex] = true;
    enqueue(&q, startVertex);

    printf("BFS Traversal: ");

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void DFSUtil(Graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(Graph* g, int startVertex) {
    bool visited[MAX] = {false};
    printf("DFS Traversal: ");
    DFSUtil(g, startVertex, visited);
    printf("\n");
}

int main() {
    Graph g;
    int vertices = 5; // 0, 1, 2, 3, 4
    initGraph(&g, vertices);

    // Add edges
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);

    printf("Graph (Adjacency Matrix representation):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", g.adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    BFS(&g, 0);
    DFS(&g, 0);

    return 0;
}
