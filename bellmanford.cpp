#include <iostream>
#include <vector>
#include <limits>
using namespace std;
struct Edge {
    int source, destination, weight;
};
void bellmanFord(int vertices, int edges, vector<Edge>& edgeList, int source) {
    vector<int> distance(vertices, numeric_limits<int>::max());
    distance[source] = 0;
    for (int i = 1; i < vertices; i++) {
        bool updated = false;
        for (const auto& edge : edgeList) {
            if (distance[edge.source] != numeric_limits<int>::max() &&
                distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
                updated = true;
            }
        }
        if (!updated) break;
    }
    for (const auto& edge : edgeList) {
        if (distance[edge.source] != numeric_limits<int>::max() &&
            distance[edge.source] + edge.weight < distance[edge.destination]) {
            cout << "Graph contains a negative-weight cycle." << endl;
            return;
        }
    }
    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == numeric_limits<int>::max()) {
            cout << "Infinity";
        } else {
            cout << distance[i];
        }
        cout << endl;
    }
}
int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<Edge> edgeList(edges);
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> edgeList[i].source >> edgeList[i].destination >> edgeList[i].weight;
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    bellmanFord(vertices, edges, edgeList, source);
    return 0;
}