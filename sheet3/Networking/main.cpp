#include <iostream>
#include <algorithm>
#include <list>

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

void primMST(int **graph, int V, struct Edge *result) {
    list<int> tree;
    bool inTree[V];
    for (int i = 0; i < V; i ++)
        inTree[i] = false;
    tree.push_back(0);
    inTree[0] = true;
    list<int>::iterator itr;
    int parent;
    int child = 0;
    int count = 0;
    while (count < V-1) {
        int min = 10000;
        for (itr = tree.begin(); itr != tree.end(); itr ++) {
            for (int i = 0; i < V; i ++) {
                if (graph[*itr][i]<min && !inTree[i]) {
                    min = graph[*itr][i];
                    parent = *itr;
                    child = i;
                }
            }
        }
        tree.push_back(child);
        inTree[child] = true;
        if (parent < child) {
            result[count].parent = parent+1;
            result[count].child = child+1;
        }
        else {
            result[count].child = parent+1;
            result[count].parent = child+1;
        }
        count ++;
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
/*
struct resultEdge{
    int parent;
    int child;
};

bool acompare(struct resultEdge lhs, struct resultEdge rhs) {
    if (lhs.parent == rhs.parent)
        return lhs.child < rhs.child;
    else
        return lhs.parent < rhs.parent;
}

struct Edge {
    int src, dest, weight;
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

void KruskalMST(struct Graph* graph, struct resultEdge *result) {
    int V = graph->V;
    int E = graph->E;

    qsort(graph->edge, E, sizeof(graph->edge[0]), myComp);

    struct subset *subsets =
            (struct subset*) malloc( V * sizeof(struct subset) );
    for (int v = 0; v < E; ++v) {
        subsets[v].parent = v;
        subsets[v].num = 1;
    }
    for (int e = 0; e < V-1; e ++) {
        struct Edge next_edge = graph->edge[e];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e].child = max(next_edge.src+1,next_edge.dest+1);
            result[e].parent = min(next_edge.src+1,next_edge.dest+1);
            Union(subsets, x, y);
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
            struct resultEdge result[V - 1];
            struct Graph* graph;
            graph = createGraph(V, V*(V-1)/2);
            int m = 0;
            int empty = 0;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (i < j) {
                        graph->edge[m].src = i;
                        graph->edge[m].dest = j;
                        cin >> graph->edge[m].weight;
                        m++;
                    }
                    else
                        cin >> empty;
                }
            }
            KruskalMST(graph, result);
            sort(result, result+V-1, acompare);
            cout << "Case #" << t + 1 << ":" << endl;
            for (int i = 0; i < V-1; i ++)
                cout << result[i].parent << " " << result[i].child << endl;
        }
    }
    return 0;
}
*/