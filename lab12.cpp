#include <iostream>
using namespace std;

// Class representing a node in the graph
class GraphNode {
public:
    int id;
    GraphNode* neighbors[10]; // Fixed-size array to hold neighbors
    int neighborCount;

    GraphNode(int nodeId) : id(nodeId), neighborCount(0) {}

    void addNeighbor(GraphNode* neighbor) {
        if (neighborCount < 10) {
            neighbors[neighborCount++] = neighbor;
        } else {
            cout << "Max neighbors reached!" << endl;
        }
    }
};

// Class representing the entire graph
class Graph {
private:
    GraphNode* nodes[10]; // Fixed-size array to hold nodes
    int nodeCount;

public:
    Graph() : nodeCount(0) {}

    // Add a node to the graph
    void addNode(int id) {
        if (nodeCount < 10) {
            nodes[nodeCount++] = new GraphNode(id);
        } else {
            cout << "Max nodes reached!" << endl;
        }
    }

    // Add an edge between two nodes
    void addEdge(int from, int to) {
        GraphNode* fromNode = nullptr;
        GraphNode* toNode = nullptr;

        for (int i = 0; i < nodeCount; i++) {
            if (nodes[i]->id == from) fromNode = nodes[i];
            if (nodes[i]->id == to) toNode = nodes[i];
        }

        if (fromNode && toNode) {
            fromNode->addNeighbor(toNode);
        } else {
            cout << "Invalid node IDs!" << endl;
        }
    }

    // Print the adjacency list representation of the graph
    void printGraph() {
        for (int i = 0; i < nodeCount; i++) {
            cout << nodes[i]->id << " -> ";
            for (int j = 0; j < nodes[i]->neighborCount; j++) {
                cout << nodes[i]->neighbors[j]->id << " ";
            }
            cout << endl;
        }
    }

    // Perform BFS on the graph
    void BFS(int startId) {
        bool visited[10] = {false};
        int queue[10], front = 0, rear = 0;

        // Find the start node
        GraphNode* startNode = nullptr;
        for (int i = 0; i < nodeCount; i++) {
            if (nodes[i]->id == startId) {
                startNode = nodes[i];
                break;
            }
        }

        if (!startNode) {
            cout << "Invalid start node ID!" << endl;
            return;
        }

        queue[rear++] = startNode->id;
        visited[startNode->id] = true;

        cout << "BFS: ";
        while (front < rear) {
            int currentId = queue[front++];
            cout << currentId << " ";

            // Find the current node
            GraphNode* currentNode = nullptr;
            for (int i = 0; i < nodeCount; i++) {
                if (nodes[i]->id == currentId) {
                    currentNode = nodes[i];
                    break;
                }
            }

            // Add unvisited neighbors to the queue
            if (currentNode) {
                for (int i = 0; i < currentNode->neighborCount; i++) {
                    int neighborId = currentNode->neighbors[i]->id;
                    if (!visited[neighborId]) {
                        visited[neighborId] = true;
                        queue[rear++] = neighborId;
                    }
                }
            }
        }
        cout << endl;
    }

    // Perform DFS on the graph
    void DFS(int startId) {
        bool visited[10] = {false};
        int stack[10], top = -1;

        // Find the start node
        GraphNode* startNode = nullptr;
        for (int i = 0; i < nodeCount; i++) {
            if (nodes[i]->id == startId) {
                startNode = nodes[i];
                break;
            }
        }

        if (!startNode) {
            cout << "Invalid start node ID!" << endl;
            return;
        }

        stack[++top] = startNode->id;

        cout << "DFS: ";
        while (top >= 0) {
            int currentId = stack[top--];

            if (!visited[currentId]) {
                cout << currentId << " ";
                visited[currentId] = true;

                // Find the current node
                GraphNode* currentNode = nullptr;
                for (int i = 0; i < nodeCount; i++) {
                    if (nodes[i]->id == currentId) {
                        currentNode = nodes[i];
                        break;
                    }
                }

                // Add unvisited neighbors to the stack
                if (currentNode) {
                    for (int i = currentNode->neighborCount - 1; i >= 0; i--) {
                        int neighborId = currentNode->neighbors[i]->id;
                        if (!visited[neighborId]) {
                            stack[++top] = neighborId;
                        }
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    g.addNode(0);
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();
    g.BFS(0);
    g.DFS(0);

    return 0;
}
