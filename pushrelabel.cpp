#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 

struct Edge { 
    int to, capacity, flow; 
    Edge* reverse; 
}; 

class PushRelabel { 
private: 
    int V; 
    vector<vector<Edge*>> adj; 
    vector<int> height, excess; 

    void push(Edge* e) { 
        int flow = min(excess[e->reverse->to], e->capacity - e->flow); 
        e->flow += flow; 
        e->reverse->flow -= flow; 
        excess[e->to] += flow; 
        excess[e->reverse->to] -= flow; 
    } 

    void relabel(int u) { 
        int minHeight = INT_MAX; 
        for (Edge* e : adj[u]) { 
            if (e->capacity > e->flow) { 
                minHeight = min(minHeight, height[e->to]); 
            } 
        } 
        if (minHeight != INT_MAX) height[u] = minHeight + 1; 
    } 

    void discharge(int u) { 
        while (excess[u] > 0) { 
            bool pushed = false; 
            for (Edge* e : adj[u]) { 
                if (e->capacity > e->flow && height[u] == height[e->to] + 1) { 
                    push(e); 
                    pushed = true; 
                    if (excess[u] == 0) break; 
                } 
            } 
            if (!pushed) relabel(u); 
        } 
    } 

public: 
    PushRelabel(int V) : V(V), adj(V), height(V, 0), excess(V, 0) {} 

    void addEdge(int u, int v, int capacity) { 
        Edge* e1 = new Edge{v, capacity, 0}; 
        Edge* e2 = new Edge{u, 0, 0}; 
        e1->reverse = e2; 
        e2->reverse = e1; 
        adj[u].push_back(e1); 
        adj[v].push_back(e2); 
    } 

    int maxFlow(int source, int sink) { 
        height[source] = V; 
        for (Edge* e : adj[source]) { 
            e->flow = e->capacity; 
            e->reverse->flow = -e->capacity; 
            excess[e->to] += e->capacity; 
        } 

        vector<int> active; 
        for (int i = 0; i < V; i++) { 
            if (i != source && i != sink) active.push_back(i); 
        } 

        bool changed; 
        do { 
            changed = false; 
            for (int u : active) { 
                int oldHeight = height[u]; 
                discharge(u); 
                if (height[u] > oldHeight) changed = true; 
            } 
        } while (changed); 

        return excess[sink]; 
    } 
}; 

int main() { 
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    PushRelabel graph(V);

    cout << "\nEnter edges (source destination capacity), -1 -1 -1 to end:" << endl;
    while (true) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        if (u == -1 && v == -1 && capacity == -1) break;
        graph.addEdge(u, v, capacity);
    }

    int source, sink;
    cout << "\nEnter source vertex (0 to " << V-1 << "): ";
    cin >> source;
    cout << "Enter sink vertex (0 to " << V-1 << "): ";
    cin >> sink;

    cout << "\nThe maximum possible flow is " << graph.maxFlow(source, sink) << endl;
    return 0; 
}