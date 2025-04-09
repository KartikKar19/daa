#include <iostream>
#include <limits.h>
#include <string.h>
#include <vector>

using namespace std;
bool bfs(vector<vector<int>>& residualGraph, int V, int source, int sink, vector<int>& parent) {
    vector<bool> visited(V, false);
    vector<int> queue(V);
    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = true;
    parent[source] = -1;
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
                if (v == sink) return true;
            }
        }
    }
    return false;
}
int fordFulkerson(vector<vector<int>>& graph, int V, int source, int sink) {
    int u, v;
    vector<vector<int>> residualGraph = graph;
    vector<int> parent(V);
    int maxFlow = 0;
    while (bfs(residualGraph, V, source, sink, parent)) {
        int pathFlow = INT_MAX;
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}
int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix:" << endl;
    cout << "Enter the capacity for each edge (0 if no edge exists):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    int source, sink;
    cout << "Enter source vertex (0 to " << V-1 << "): ";
    cin >> source;
    cout << "Enter sink vertex (0 to " << V-1 << "): ";
    cin >> sink;
    cout << "The maximum possible flow is " << fordFulkerson(graph, V, source, sink) << endl;
    return 0;
}
