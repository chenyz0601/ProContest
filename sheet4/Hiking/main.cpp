#include <iostream>

using namespace std;

int dijkstra(int **graph, int start, int end, int V);

int minDist(int dist[], bool in_spt[], int V) {
    int min = 1000, min_index;
    for (int v = 0; v < V; v ++) {
        if (dist[v] <= min && !in_spt[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t ++) {
        int N, M;
        cin >> N >> M;
        if (N == 1) {
            int c;
            cin >> c;
            cout << "Case #" << t+1 << ": " << 0 << endl;
        }
        else {
            int **graph;
            graph = new int *[N];
            for (int i = 0; i < N; i ++)
                graph[i] = new int[N];
            for (int i = 0; i < N; i ++)
                for (int j = 0; j < N; j ++)
                    graph[i][j] = 0;
            int temp_row, temp_col, temp_val;
            for (int m = 0; m < M; m ++) {
                cin >> temp_row >> temp_col >> temp_val;
                graph[temp_row-1][temp_col-1] = temp_val;
                graph[temp_col-1][temp_row-1] = temp_val;
            }
            int result = dijkstra(graph, 0, N-1, N);
            cout << "Case #" << t+1 << ": " << result << endl;
        }
    }
    return 0;
}

int dijkstra(int **graph, int start, int end, int V) {
    int dist[V];
    bool in_spt[V];
    for (int i = 0; i < V; i ++) {
        dist[i] = 1000;
        in_spt[i] = false;
    }
    dist[start] = 0;
    for (int i = 0; i < V-1; i ++) {
        int u = minDist(dist, in_spt, V);
        in_spt[u] = true;
        for (int v = 0; v < V; v ++) {
            if (!in_spt[v] && graph[u][v] && dist[u] != 1000 && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    return dist[end];
}
