# Program 5: Graph Traversal (BFS & DFS)

This program implements an **Undirected Graph** using an **Adjacency Matrix** and performs two types of traversals:
1. **Breadth-First Search (BFS)**: Uses a Queue to explore neighbors layer by layer.
2. **Depth-First Search (DFS)**: Uses recursion (internal stack) to explore as deep as possible along each branch.

---

## 1. Data Structure Used

### Adjacency Matrix
A 2D array `adjMatrix[MAX][MAX]` is used to represent the graph.
- `adjMatrix[i][j] = 1` indicates an edge between vertex `i` and vertex `j`.
- `adjMatrix[i][j] = 0` indicates no edge.

### Queue (for BFS)
A simple array-based queue is used to store vertices to be visited during BFS traversal.

---

## 2. Functions Used in the Program

### `initGraph(Graph* g, int vertices)`
- Initializes the adjacency matrix with 0s.
- Sets the number of vertices.

---

### `addEdge(Graph* g, int src, int dest)`
- Adds an edge between `src` and `dest`.
- Since the graph is undirected, it sets both `adjMatrix[src][dest]` and `adjMatrix[dest][src]` to 1.

---

### `BFS(Graph* g, int startVertex)`
- Performs Breadth-First Search starting from `startVertex`.
- Uses a `visited` array to keep track of visited nodes.
- Uses a Queue to manage the traversal order.

---

### `DFS(Graph* g, int startVertex)`
- Performs Depth-First Search starting from `startVertex`.
- Calls the helper function `DFSUtil`.

### `DFSUtil(Graph* g, int vertex, bool visited[])`
- Recursive helper function for DFS.
- Marks the current node as visited and prints it.
- Recursively visits all unvisited adjacent vertices.

---

## 3. Main Function (`main()`)

The `main()` function:
1. Creates a graph with 5 vertices.
2. Adds edges to form the following structure:
   - 0 is connected to 1 and 2.
   - 1 is connected to 3 and 4.
   - 2 is connected to 4.
3. Prints the Adjacency Matrix.
4. Performs and prints BFS traversal starting from vertex 0.
5. Performs and prints DFS traversal starting from vertex 0.

---

## 4. Sample Output

```
Graph (Adjacency Matrix representation):
0 1 1 0 0 
1 0 0 1 1 
1 0 0 0 1 
0 1 0 0 0 
0 1 1 0 0 

BFS Traversal: 0 1 2 3 4 
DFS Traversal: 0 1 3 4 2 
```
