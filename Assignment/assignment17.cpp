#include <iostream>
using namespace std;

#define MAX 100

struct Edge{
    int src;
    int dest;
    int weight;
};

Edge edge[MAX];
int numEdge = 0;
int graph[MAX][MAX];

void sortEdge(){
    Edge temp;
    for(int i = 0; i < numEdge - 1; i++){
        for(int j = 0; j < numEdge - i - 1; j++){
            if(edge[j].weight > edge[j+1].weight){
                temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
            }
        }
    }
}

int findRoot(int u, int parent[]){
    while(parent[u] != -1){
        u = parent[u];
    }
    return u;
}

bool createCycle(int u , int v, int parent[]){
    int rootU = findRoot(u,parent);
    int rootV = findRoot(v, parent);

    return rootU == rootV;
}

void kruskal(int numNodes){
    int parent[MAX];
    for(int i = 0; i < numNodes; i++){
        parent[i] = -1;
    }

    sortEdge();

    cout << "Minimum Spanning Tree" << endl;
    cout << "Edge \t Weight" << endl;

    int edgeMST = 0;
    for(int i = 0; i < numEdge && edgeMST < numNodes - 1; i++){
        int u = edge[i].src;
        int v = edge[i].dest;

        if(!createCycle(u,v,parent)){
            cout << u << " - " << v << " " << edge[i].weight << endl;
            edgeMST++;

            int rootU = findRoot(u, parent);
            int rootV = findRoot(v, parent);
            parent[rootU] = rootV;
        }
    }
}

bool isDuplicate(Edge newEdge) {
    for (int i = 0; i < numEdge; i++) {
        if ((edge[i].src == newEdge.src && edge[i].dest == newEdge.dest) ||
            (edge[i].src == newEdge.dest && edge[i].dest == newEdge.src)) {
            return true; 
        }
    }
    return false; 
}

void dijkstra(int numNodes, int startNode) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < numNodes; i++) {
        dist[i] = INT_MAX; // Initialize distances to infinity
        visited[i] = false; // Mark all nodes as unvisited
    }

    dist[startNode] = 0; // Distance to start node is 0

    for (int count = 0; count < numNodes - 1; count++) {
        int u = -1;
        
        // Find the unvisited node with the smallest distance
        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true; // Mark the selected node as visited

        // Update distances to neighboring nodes
        for (int v = 0; v < numNodes; v++) {
            if (graph[u][v] != 0 && !visited[v]) { // Check for an edge
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v]; // Update distance
                }
            }
        }
    }

    // Print the results
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < numNodes; i++) {
        cout << i << "\t " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl; // Print -1 for unreachable nodes
    }
}


int main(){
    int numNodes;
    int choice;
    while (true){
        cout << "\n Menu : \n" << endl;
        cout << "1. INSERT GRAPH" << endl;
        cout << "2. PERFORM KRUSKAL'S ALGORITHM (MST)" << endl;
        cout << "3. PERFORM DIJKSTRA'S ALGORITHM " << endl;
        cout << "4. EXIT" << endl;
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Number of Node : ";
            cin >> numNodes;

            if(numNodes<=0){
                cout << "No Nodes to process." << endl;
                break;
            }

            cout << "Enter the Number of Edges : ";
            cin >> numEdge;

            if(numEdge == 0 && numNodes == 1){
                cout << "No Edges to process. MST is trivial with only one node." << endl;
                break;
            }

            if(numEdge > MAX){
                cout << "Edges Limits reached" << endl;
                break;
            }

            if(numEdge <= 0){
                cout << "No Edges to proceed." << endl;
                break;
            }

            

            cout << "Enter Edge (Source , Destination , Weight) : " << endl;
            for(int i = 0 ; i < numEdge; i++){
                Edge newEdge;
                cin >> newEdge.src >> newEdge.dest >> newEdge.weight;

                if (!isDuplicate(newEdge)) {
                        edge[numEdge] = newEdge;
                        numEdge++; 
                    } else {
                        cout << "Duplicate edge found: " << newEdge.src << " - " << newEdge.dest << " " << newEdge.weight << endl;
                        cout << "Exiting..." << endl;
                        exit(0);
                    }
            }
            break;
        
        case 2:
        if (numEdge > 0) {
            kruskal(numNodes);
        } else {
            cout << "No edges to process." << endl;
        }
        break;
        case 3:
        cout << "Enter the starting node for Dijkstra's algorithm: ";
        int startNode;
        cin >> startNode;

        if (startNode >= 0 && startNode < numNodes) {
            dijkstra(numNodes, startNode);
        } else {
            cout << "Invalid starting node." << endl;
        }
        break;
        case 4:
        cout << "Exiting...." << endl;
        break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
    
    return 0;
}