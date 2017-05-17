#include <iostream>

using namespace std;

struct Edge {
    int src, dest, weight = 0;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
    return graph;
}

struct subset {
    int parent;
    int num;
};

// uses union set to do path compression
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].num < subsets[yroot].num) {
        subsets[xroot].parent = yroot;
        subsets[yroot].num += subsets[xroot].num;
    }
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].num += subsets[yroot].num;
    }
}

int myComp(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

int KruskalMST(struct Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    int e_max = 0;
    int out = 0;

    qsort(graph->edge, E, sizeof(graph->edge[0]), myComp);

    struct subset *subsets =
            (struct subset*) malloc( V * sizeof(struct subset) );
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].num = 1;
    }

    for (int e = 0; e < E; e ++) {
        struct Edge next_edge = graph->edge[e];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            e_max ++;
            out -= next_edge.weight;
            Union(subsets, x, y);
        }
        if (e_max == V-1)
            break;
    }
    if (e_max < V-1)
        return -1;
    else
        return out;
}

int main() {
    int T, V, M, node1, node2, temp1, temp2, sum;
    cin >> T;
    for (int t = 0; t < T; t ++) {
        cin >> V >> M;
        if (V == 1) {
            cout << "Case #" << t+1 << ": impossible" << endl;
        }
        else {
            sum = 0;
            struct Graph* graph = createGraph(V, M);
            for (int m = 0; m < M; m ++) {
                cin >> node1 >> node2 >> temp1 >> temp2;
                sum += temp1*temp2;
                graph->edge[m].src = node1-1;
                graph->edge[m].dest = node2-1;
                graph->edge[m].weight = -temp1*temp2;
            }
            int out = KruskalMST(graph);
            if (out == -1)
                cout << "Case #" << t+1 << ": impossible" << endl;
            else
                cout << "Case #" << t+1 << ": " << sum-out << endl;
        }
    }
    return 0;
}