# Program 7: Dijkstra’s Shortest Path Algorithm

This program implements **Dijkstra’s Algorithm** to find the shortest path from a source vertex to all other vertices in a weighted graph. It uses the **Greedy approach**.

---

## 1. Data Structure Used

### Adjacency Matrix
A 2D array `graph[V][V]` represents the weighted graph.
- `graph[i][j] = w` means there is an edge from `i` to `j` with weight `w`.
- `0` indicates no edge.

### Arrays
- `dist[V]`: Stores the shortest distance from the source to each vertex.
- `sptSet[V]`: A boolean array to keep track of vertices included in the Shortest Path Tree (SPT).

---

## 2. Functions Used in the Program

### `minDistance(int dist[], bool sptSet[])`
- Finds the vertex with the minimum distance value from the set of vertices not yet included in the shortest path tree.
- Returns the index of the vertex.

---

### `printSolution(int dist[])`
- Prints the constructed distance array, showing the shortest distance from the source to each vertex.

---

### `dijkstra(int graph[V][V], int src)`
- Implements Dijkstra’s algorithm.
- **Steps:**
  1. Initialize `dist` values as `INT_MAX` and `sptSet` as `false`. Set `dist[src]` to 0.
  2. Repeat `V-1` times:
     - Pick vertex `u` with minimum distance from the set of unvisited vertices.
     - Mark `u` as visited (`sptSet[u] = true`).
     - Update `dist` values of adjacent vertices of `u` if the current path is shorter (`dist[u] + weight < dist[v]`).

---

## 3. Main Function (`main()`)

The `main()` function:
1. Defines a weighted graph with 9 vertices using an adjacency matrix.
2. Calls `dijkstra(graph, 0)` to calculate shortest paths from vertex 0.
3. Prints the results.

---

## 4. Sample Output

```
Dijkstra's Shortest Path Algorithm:
Vertex 		 Distance from Source
0 		 0
1 		 4
2 		 12
3 		 19
4 		 21
5 		 11
6 		 9
7 		 8
8 		 14
```
