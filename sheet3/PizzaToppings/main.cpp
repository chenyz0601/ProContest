#include <iostream>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
    bool DFSUtil(int v, int pare_mark);

public:
    int *mark;
    bool notPossible = false;
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    mark = new int[V];
    for (int i = 0; i < V; i ++)
        mark[i] = -1;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::DFSUtil(int v, int pare_mark) {
    mark[v] = 1 - pare_mark;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i ++) {
        if (mark[*i] != -1) {
            if (mark[*i] == mark[v]) {
                notPossible = true;
                return true;
            }
        } else if (DFSUtil(*i, mark[v]))
            return true;
    }
    return false;
}

void Graph::DFS(int v) {
    DFSUtil(v, 0);
}

int main() {
    int T;
    cin >> T;
    string result[T];
    for (int t = 0; t < T; t ++) {
        int N, M;
        cin >> N >> M;
        Graph g(N);
        int a, b;
        for (int m = 0; m < M; m ++) {
            cin >> a >> b;
            g.addEdge(a-1, b-1);
        }
        for (int i = 0; i < N; i ++) {
            if (g.mark[i] == -1) {
                g.DFS(i);
                if (g.notPossible) {
                    result[t] = "no";
                    break;
                }
            }
        }
        if (!g.notPossible)
            result[t] = "yes";
    }
    for (int t = 0; t < T; t ++)
        cout << "Case #" << t+1 << ": " << result[t] << endl;
    return 0;
}