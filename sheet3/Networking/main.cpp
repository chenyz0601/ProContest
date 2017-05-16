#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

struct Edge{
    int parent;
    int child;
};

bool acompare(struct Edge lhs, struct Edge rhs) {
    if (lhs.parent == rhs.parent)
        return lhs.child < rhs.child;
    else
        return lhs.parent < rhs.parent;
}

int keys(int key[], bool mstSet[], int V) {
    int min = INT8_MAX, min_index;
    for (int v = 0; v < V; v ++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int printMST(int parent[], int V) {
    for (int i = 1; i < V; i ++)
        cout << parent[i]+1 << " " << i+1 << endl;
}

void primMST(int **graph, int V, struct Edge *result) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i ++)
        key[i] = INT8_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V-1; count ++) {
        int u = keys(key, mstSet, V);
        mstSet[u] = true;
        for (int v = 0; v < V; v ++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }
    for (int i = 1; i < V; i ++) {
        if (parent[i] < i) {
            result[i-1].parent = parent[i]+1;
            result[i-1].child = i+1;
        }
        else {
            result[i-1].child = parent[i]+1;
            result[i-1].parent = i+1;
        }
    }
}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int V;
        cin >> V;
        if (V == 1) {
            int c;
            cin >> c;
            cout << "Case #" << t + 1 << ":" << endl;
        }
        else {
            struct Edge result[V - 1];
            int **graph;
            graph = new int *[V];
            for (int i = 0; i < V; i++)
                graph[i] = new int[V];
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    cin >> graph[i][j];
            primMST(graph, V, result);
            sort(result, result+V-1, acompare);
            cout << "Case #" << t + 1 << ":" << endl;
            for (int i = 0; i < V-1; i ++)
                cout << result[i].parent << " " << result[i].child << endl;
        }
    }
    return 0;
}
