#include <iostream> 
#include <vector> 
#include <limits> 
using namespace std; 
#define INF numeric_limits<int>::max() 
void floydWarshall(vector<vector<int>>& graph, int n) { 
    vector<vector<int>> dist = graph; 
    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) { 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                } 
            } 
        } 
    } 
    cout << "Shortest path matrix:" << endl;
    cout << "    "; 
    for (int i = 0; i < n; i++) {
        cout << i << "   ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) { 
        cout << i << "   ";
        for (int j = 0; j < n; j++) { 
            if (dist[i][j] == INF) 
                cout << "∞   "; 
            else 
                cout << dist[i][j] << "   "; 
        } 
        cout << endl; 
    } 
} 
int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "\nEnter the adjacency matrix:" << endl;
    cout << "Use -1 for infinity (no direct edge)" << endl;
    cout << "Enter 0 for self-loops" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter weights for vertex " << i << ":" << endl;
        for (int j = 0; j < n; j++) {
            int weight;
            cin >> weight;
            graph[i][j] = (weight == -1) ? INF : weight;
        }
    }
    floydWarshall(graph, n);
    return 0; 
} 