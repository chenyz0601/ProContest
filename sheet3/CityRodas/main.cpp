#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::topologicalSort() {
    vector<int> in_degree(V, 0);
    for (int u = 0; u < V; u ++) {
        list<int>::iterator iter;
        for (iter = adj[u].begin(); iter != adj[u].end(); iter ++)
            in_degree[*iter] ++;
    }
    queue<int> q;
    for (int i = 0; i < V; i ++)
        if (in_degree[i] == 0)
            q.push(i);
    int cnt = 0;
    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        list<int>::iterator iter;
        for (iter = adj[u].begin(); iter != adj[u].end(); iter ++)
            if (--in_degree[*iter] == 0)
                q.push(*iter);
        cnt ++;
    }
    if (cnt != V) {
        cout << "there is a cycle" << endl;
        return;
    }
    for (int i = 0; i < top_order.size(); i ++)
        cout << top_order[i] << " ";
    cout << endl;
}

int main() {
    int T, N, M, L, temp1, temp2;
    cin >> T;
    for (int t = 0; t < T; t ++) {
        cin >> N >> M >> L;
        Graph graph(N);
        for (int m = 0; m < M; m ++) {
            cin >> temp1 >> temp2;
            graph.addEdge(temp1-1, temp2-1);
        }
        for (int l = 0; l < L; l ++) {
            cin >> temp1 >> temp2;
            graph.addEdge(temp1-1, temp2-1);
            graph.addEdge(temp2-1, temp1-1);
        }
        graph.topologicalSort();
    }
    return 0;
}