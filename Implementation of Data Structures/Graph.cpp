#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int MAX_VERTICES = 100;

struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void initGraph(Graph& graph, int vertices) {
    graph.numVertices = vertices;
    for (int i = 0; i < graph.numVertices; i++) {
        for (int j = 0; j < graph.numVertices; j++) {
            graph.adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph& graph, int src, int dest) {
    if (src >= 0 && src < graph.numVertices && dest >= 0 && dest < graph.numVertices) {
        graph.adjMatrix[src][dest] = 1;
        graph.adjMatrix[dest][src] = 1; // Comment this line for directed graph
    } else {
        cout << "Invalid vertices." << endl;
    }
}

void removeEdge(Graph& graph, int src, int dest) {
    if (src >= 0 && src < graph.numVertices && dest >= 0 && dest < graph.numVertices) {
        graph.adjMatrix[src][dest] = 0;
        graph.adjMatrix[dest][src] = 0; //Comment this line for directed graph
    } else {
        cout << "Invalid vertices." << endl;
    }
}

void displayGraph(const Graph& graph) {
    for (int i = 0; i < graph.numVertices; i++) {
        for (int j = 0; j < graph.numVertices; j++) {
            cout << graph.adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(const Graph& graph, int startVertex) {
    if (startVertex < 0 || startVertex >= graph.numVertices) {
        cout << "Invalid start vertex." << endl;
        return;
    }

    queue<int> q;
    vector<bool> visited(graph.numVertices, false);

    cout << "Breadth-First Search starting from vertex " << startVertex << ": ";
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (int i = 0; i < graph.numVertices; i++) {
            if (graph.adjMatrix[vertex][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

void DFS(const Graph& graph, int startVertex) {
    if (startVertex < 0 || startVertex >= graph.numVertices) {
        cout << "Invalid start vertex." << endl;
        return;
    }

    stack<int> s;
    vector<bool> visited(graph.numVertices, false);

    cout << "Depth-First Search starting from vertex " << startVertex << ": ";
    s.push(startVertex);
    visited[startVertex] = true;

    while (!s.empty()) {
        int vertex = s.top();
        s.pop();
        cout << vertex << " ";

        for (int i = 0; i < graph.numVertices; i++) {
            if (graph.adjMatrix[vertex][i] == 1 && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph graph;
    initGraph(graph, vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int src, dest;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> src >> dest;
        addEdge(graph, src, dest);
    }

    cout << "Adjacency Matrix:" << endl;
    displayGraph(graph);

    int startVertex;
    cout << "Enter the starting vertex for BFS and DFS: ";
    cin >> startVertex;

    BFS(graph, startVertex);
    DFS(graph, startVertex);

    return 0;
}

