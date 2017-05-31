#include <iostream>
#include <algorithm>

#define c_max 1000000
using namespace std;

struct Edge {
    int node_id;
    int distance;
};

bool edeg_compare(struct Edge a, struct Edge b) {
    return a.distance < b.distance;
}

void dijkstra(int **graph, int start, int *dist, int V);

int minDist(int dist[], bool in_spt[], int V) {
    int min = c_max, min_index = 0;
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
        int N, M, S;
        cin >> N >> M >> S;
        if (N == 1) {
            cin >> S;
            cout << "Case #" << t+1 << ": " << 0 << " " << S << endl;
        }
        else {
            int **graph;
            int dist[N];
            struct Edge result[S];
            graph = new int *[N];
            for (int i = 0; i < N; i ++)
                graph[i] = new int[N];
            for (int i = 0; i < N; i ++)
                for (int j = 0; j < N; j ++)
                    graph[i][j] = 0;
            int temp_row, temp_col, temp_val;
            for (int m = 0; m < M; m ++) {
                cin >> temp_row >> temp_col >> temp_val;
                if (graph[temp_row-1][temp_col-1] != 0) {
                    graph[temp_row-1][temp_col-1] = min(graph[temp_row-1][temp_col-1], temp_val);
                    graph[temp_col-1][temp_row-1] = graph[temp_row-1][temp_col-1];
                }
                else {
                    graph[temp_row-1][temp_col-1] = temp_val;
                    graph[temp_col-1][temp_row-1] = temp_val;
                }
            }
            dijkstra(graph, 0, dist, N);
            int index;
            for (int s = 0; s < S; s ++) {
                cin >> index;
                result[s].distance = dist[index-1];
                result[s].node_id = index;
            }
            sort(result, result+S, edeg_compare);
            cout << "Case #" << t+1 << ": " << result[0].distance;
            int count = 0;
            int out[S];
            for (int s = 0; s < S; s ++)
                if (result[s].distance == result[0].distance) {
                    out[count] = result[s].node_id;
                    count ++;
                }
            sort(out, out+count);
            for (int i = 0; i < count; i ++)
                cout << " " << out[i];
            cout << endl;
        }
    }
    return 0;
}

void dijkstra(int **graph, int start, int *dist, int V) {
    bool in_spt[V];
    for (int i = 0; i < V; i ++) {
        dist[i] = c_max;
        in_spt[i] = false;
    }
    dist[start] = 0;
    for (int i = 0; i < V-1; i ++) {
        int u = minDist(dist, in_spt, V);
        in_spt[u] = true;
        for (int v = 0; v < V; v ++) {
            if (!in_spt[v] && graph[u][v] && dist[u] != c_max && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
}