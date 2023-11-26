#include <iostream>
#include <list>
#include <stack>

using namespace std; 

// Got help from friends + youtube + stackoverflow/G4G
// This shit was hard bruh
class Graph{
    int v2; 
    list<int> *adj;
    // half[] represents the nodes of the graph that have been visited but not completed. 
    void fillInNode(int v, bool half[], stack<int> &stack);
    void DFS(int v, bool half[], int node, int arr[]);

    public:
        Graph(int v2);
        void add_SCC(int v, int w); 
        void printGraph(int node, int arr[]);
        Graph transpose(); 
};

// this :: operator lets you define the functions that you defined in the class. 
Graph::Graph(int v2){
    this->v2 = v2;
    adj = new list<int>[v2];
}

void Graph::DFS(int v, bool half[], int node, int arr[]){
    half[v] = true;
    arr[v] = node;
    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++){
        if (half[*i] == false){
            DFS(*i, half, node, arr);
        }
    }
}

Graph Graph::transpose(){
    Graph graph(v2);
    for (int v = 0; v < v2; v++){
        for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++){
            graph.adj[*i].push_back(v);
        }
    }
    return graph;
}

void Graph::add_SCC(int v, int w){
    adj[v].push_back(w);
}

void Graph::fillInNode(int v, bool half[], stack<int> &stack){
    half[v] = true;
    for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++){
        if(half[*i] == false){
            fillInNode(*i, half, stack);
        }
    }
    stack.push(v);
}

void Graph::printGraph(int node,int arr[]){
    stack<int> nodes;
    bool *half = new bool[v2];

    for(int i = 0; i < v2; i++){
        half[i] = false;
    }

    for(int i = 0; i < v2; i++){
        if(half[i] == false){
            fillInNode(i, half, nodes);
        }
    }
    Graph graph2 = transpose();

    for(int i = 0; i < v2; i++){
        half[i] = false;
    }

    while (nodes.empty() == false){
        int v = nodes.top();
        nodes.pop();
        if (half[v] == false){
            graph2.DFS(v, half, v, arr);
            int minimum = v;
            for(int i = 0; i < node; i++){
                if(arr[i] == v){
                    if(minimum > i){
                        minimum = i;
                    }
                }
            }
            for(int i = 0; i < node; i++){
                if(arr[i] == v){
                    arr[i] = minimum;
                }
            }
        }
    }
}

int main(){
    int nodeCount;
    int edgeCount;
    cin >> nodeCount;
    cin >> edgeCount;
    Graph G(nodeCount);

    for(int i = 0; i < edgeCount; i++){
        int u, w;
        cin >> u;
        cin >> w; 
        G.add_SCC(u,w);
    }

    int arr[nodeCount];
    for(int i = 0; i < nodeCount; i++){
        arr[i] = nodeCount + 2;
    }
    G.printGraph(nodeCount, arr);

    for(int i = 0; i < nodeCount; i++){
        cout << arr[i] << endl;
    }
    return 0;
}