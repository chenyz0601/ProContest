#include <iostream>
#include <list>
#include <stack>

using namespace std;

void findPath(int **graph, int V) {
    list<int> nodes;
    nodes.push_back(0);
    list<int>::iterator itr;
    int parent[V];
    bool visited[V];
    for (int i = 0; i < V; i ++)
        visited[i] = false;
    parent[0] = -1;
    visited[0] = true;
    int index;
    int uncle = 0;
    while (uncle != V-1) {
        int min = 150000;
        for (itr = nodes.begin(); itr != nodes.end(); itr ++) {
            for (int i = 0; i < V; i ++) {
                if (!visited[i] && 0<graph[*itr][i] && graph[*itr][i]<min) {
                    min = graph[*itr][i];
                    index = *itr;
                    uncle = i;
                }
            }
        }
        parent[uncle] = index;
        visited[uncle] = true;
        nodes.push_back(uncle);
    }
    stack<int> finalPath;
    int p = V-1;
    finalPath.push(p);
    while (parent[p] != -1) {
        p = parent[p];
        finalPath.push(p);
    }
    while (!finalPath.empty()) {
        cout << 1+finalPath.top() << " ";
        finalPath.pop();
    }
}

int main() {
    int T, V;
    int **graph;
    cin >> T;
    for (int t = 0; t < T; t ++) {
        cin >> V;
        graph = new int *[V];
        for (int i = 0; i < V; i++)
            graph[i] = new int[V];
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                cin >> graph[i][j];
        if (V == 1)
            cout << "Case #" << t+1 << ": " << 1 << endl;
        else {
            cout << "Case #" << t+1 << ": ";
            findPath(graph, V);
            cout << endl;
        }
    }
    return 0;
}

