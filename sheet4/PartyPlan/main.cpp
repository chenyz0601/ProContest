#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    int *value;
    list<int> *adj;
    list<int> *parents;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        value = new int[V];
        parents = new list<int>[V];
    }

    void addEdge(int u, int v) {
        this->adj[u].push_back(v);
        this->parents[v].push_back(u);
    }

    void addVale(int v,int value) {
        this->value[v] = value;
    }

    void topologicalSort();
};

void Graph::topologicalSort() {
    vector<int> in_degree(V, 0);

    // compute in_degree of each node
    for (int u = 0; u < V; u ++) {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i ++)
            in_degree[*i] = in_degree[u]+1;
    }

    queue<int> q;
    for (int i = 0; i < V; i ++)
        if (in_degree[i] == 0)
            q.push(i);

    int cnt = 0;
    vector<int> top_oder;
    queue<int> counter;
    int pre_degree = 0;

    while (!q.empty()) {
        int u = q.front();
        if (pre_degree == in_degree[u])
            cnt ++;
        else {
            pre_degree = in_degree[u];
            counter.push(cnt-1);
            cnt = 1;
        }
        q.pop();
        top_oder.push_back(u);
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i ++) {
            if (in_degree[*i] == in_degree[u]+1) {
                q.push(*i);
            }
        }
    }
    counter.push(cnt-1);
    int cost_time = 0;
    vector<int> last_stream;
    for (int i = 0; i < top_oder.size(); i ++) {
        int max_step = value[top_oder[i]];
        int max_id = top_oder[i];
        int limit = counter.front();
        counter.pop();
        for (int j = 0; j < limit; j ++) {
            i ++;
            if (max_step < value[top_oder[i]]) {
                max_id = top_oder[i];
                max_step = value[top_oder[i]];
            }
        }
        last_stream.push_back(max_id);
        cost_time += max_step;
    }
    for (int i = 0; i < last_stream.size()-1; i ++) {
        bool in_adj = false;
        list<int>::iterator iter;
        for (iter = adj[i].begin(); iter != adj[i].end(); iter ++)
            if (*iter == last_stream[i+1])
                in_adj = true;
        if (!in_adj) {
            int max_temp = 0;
            for (iter = parents[last_stream[i+1]].begin(); iter != parents[last_stream[i+1]].end(); iter ++) {
                if (in_degree[last_stream[i]] == in_degree[*iter] && value[*iter] > max_temp)
                    max_temp = value[*iter];
            }
            cost_time -= value[last_stream[i]]-max_temp;
        }
    }
    cout << cost_time << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t ++) {
        int V;
        cin >> V;
        Graph graph(V);
        for (int v = 0; v < V; v ++) {
            int cur_val;
            cin >> cur_val;
            graph.addVale(v, cur_val);
            int K;
            cin >> K;
            int child;
            for (int k = 0; k < K; k ++) {
                cin >> child;
                graph.addEdge(v, child-1);
            }
        }
        cout << "Case #" << t+1 << ": ";
        graph.topologicalSort();
    }
    return 0;
}