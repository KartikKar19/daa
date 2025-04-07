#include <iostream> 
#include <vector> 
#include <limits> 
using namespace std; 
struct Edge { 
int source, destination, weight; 
}; 
void bellmanFord(int vertices, int edges, vector<Edge>& edgeList, int  
source) { 
vector<int> distance(vertices, numeric_limits<int>::max()); 
distance[source] = 0; 
for (int i = 1; i < vertices; i++) { 
for (const auto& edge : edgeList) { 
if (distance[edge.source] != numeric_limits<int>::max() && 
distance[edge.source] + edge.weight < distance[edge.destination]) { 
distance[edge.destination] = distance[edge.source] + edge.weight; 
} 
} 
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
cout << "Vertex " << i << ": " << (distance[i] ==  
numeric_limits<int>::max() ? "Infinity" : to_string(distance[i])) <<  
endl; 
} 
} 
int main() { 
int vertices, edges; 
cout << "Enter number of vertices: "; 
cin >> vertices; 
cout << "Enter number of edges: "; 
cin >> edges; 
vector<Edge> edgeL // Output the shortest distances 
ist(edges); 
cout << "Enter edges (source destination weight):" << endl; 
for (int i = 0; i < edges; i++) { 
cin >> edgeList[i].source >> edgeList[i].destination >>  
edgeList[i].weight; 
} 
int source; 
cout << "Enter source vertex: "; 
cin >> source; 
bellmanFord(vertices, edges, edgeList, source); 
return 0; 
} 