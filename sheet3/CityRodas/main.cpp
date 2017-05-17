#include <iostream>
#include <list>
#include <stack>
#define NIL -1

int gloabl_count = 0;

using namespace std;
// A class that represents an directed graph
class Graph {
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists

    // A Recursive DFS based function used by SCC()
    void SCCUtil(int u, int disc[], int low[],
                 stack<int> *st, bool stackMember[], int ref[][2], int L, bool &control, bool print);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void SCC(int ref[][2], int L, bool &control, bool print);    // prints strongly connected components
    void delete_edge(int src, int dest);
    void cout_edges() {
        for (int i = 0; i < V; i ++) {
            if (!adj[i].empty()) {
                list<int>::iterator itr;
                for (itr = adj[i].begin(); itr != adj[i].end(); itr ++)
                    cout << "edge " << i << " -> " << *itr << endl;
            }
        }
    }
    bool is_find(int ref[][2], int s, int d, int L) {
    for (int i = 0; i < L; i ++) {
        if (ref[i][0] == s && ref[i][1] == d)
            return true;
    }
    return false;
}

};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::delete_edge(int src, int dest) {
    adj[src].remove(dest);
}

// A recursive function that finds and prints strongly connected
// components using DFS traversal
// u --> The vertex to be visited next
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
//             discovery time) that can be reached from subtree
//             rooted with current vertex
// *st -- >> To store all the connected ancestors (could be part
//           of SCC)
// stackMember[] --> bit/index array for faster check whether
//                  a node is in stack
void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st,
                    bool stackMember[], int ref[][2], int L, bool &control, bool print){//, list<int> *out) {
    // A static variable is used for simplicity, we can avoid use
    // of static variable by passing a pointer.
    static int time = 0;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;

    // Go through all vertices adjacent to this
    if (!adj[u].empty()) {

        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = *i;  // v is current adjacent of 'u'

            // If v is not visited yet, then recur for it
            if (disc[v] == -1) {
                SCCUtil(v, disc, low, st, stackMember, ref, L, control, print);//, out);

                // Check if the subtree rooted with 'v' has a
                // connection to one of the ancestors of 'u'
                // Case 1 (per above discussion on Disc and Low value)
                low[u]  = min(low[u], low[v]);
            }

                // Update low value of 'u' only of 'v' is still in stack
                // (i.e. it's a back edge, not cross edge).
                // Case 2 (per above discussion on Disc and Low value)
            else if (stackMember[v])
                low[u]  = min(low[u], disc[v]);
        }

        // head node found, pop the stack and print an SCC
        int w = 0;  // To store stack extracted vertices
        if (low[u] == disc[u]) {
            //cout << "the stack size is: " << st->size() << endl;
            if (st->size() > 2) {
                list<int> out;
                while (st->top() != u) {
                    w = (int) st->top();
                    out.push_back(w);
                    //cout << w << " ";
                    stackMember[w] = false;
                    st->pop();
                }
                w = (int) st->top();
                out.push_back(w);
                //cout << w << "\n";
                stackMember[w] = false;
                st->pop();
                // here to find deleted edge
                int length = (int)out.size();
                int temp1, temp2;
                if (length > 1) {
                    list<int>::iterator itr;
                    itr = out.begin();
                    temp1 = *itr;
                    int first = temp1;
                    itr ++;
                    if (length == 2) {
                        if (is_find(ref, *itr, temp1, 2*L)) {
                            gloabl_count ++;
                            if (print) {
                                delete_edge(*itr, temp1);
                                cout <<  *itr+1 << " " << temp1+1 << endl;
                            }
                        }
                    } else {
                        while (itr != out.end()) {
                            temp2 = *itr;
                            if (is_find(ref, temp1, temp2, 2*L)) {
                                gloabl_count ++;
                                if (print) {
                                    delete_edge(temp2, temp1);
                                    cout << temp2+1 << " " << temp1+1 << endl;
                                }
                            }
                            temp1 = temp2;
                            itr ++;
                        }
                        int last = temp1;
                        if (is_find(ref, first, last, 2*L)) {
                            gloabl_count ++;
                            if (print) {
                                delete_edge(first, last);
                                cout << first+1 << " " << last+1 << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

// The function to do DFS traversal. It uses SCCUtil()
void Graph::SCC(int ref[][2], int L, bool &control, bool print) {
    int *disc = new int[V];
    int *low = new int[V];
    bool *stackMember = new bool[V];
    stack<int> *st = new stack<int>();

    // Initialize disc and low, and stackMember arrays
    for (int i = 0; i < V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        stackMember[i] = false;
    }

    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    for (int i = 0; i < V; i++)
        if (disc[i] == NIL)
            SCCUtil(i, disc, low, st, stackMember, ref, L, control, print);
}


int main() {
    int T, N, M, L, temp1, temp2;
    cin >> T;
    for (int t = 0; t < T; t ++) {
        cin >> N >> M >> L;
        Graph graph(N);
        int ref[2*L][2];
        for (int m = 0; m < M; m ++) {
            cin >> temp1 >> temp2;
            graph.addEdge(temp1-1, temp2-1);
        }
        for (int l = 0; l < L; l ++) {
            cin >> temp1 >> temp2;
            graph.addEdge(temp1-1, temp2-1);
            graph.addEdge(temp2-1, temp1-1);
            ref[l*2][0] = temp1-1;
            ref[l*2][1] = temp2-1;
            ref[l*2+1][0] = temp2-1;
            ref[l*2+1][1] = temp1-1;
        }
        bool not_stop = true;
        bool print = {false};
        while (true) {
            graph.SCC(ref, L, not_stop, print);
            if (gloabl_count == 0 && !print) {
                cout << "Case #" << t+1 << ": no" << endl;
                break;
            }
            else if (!print){
                gloabl_count = 0;
                cout << "Case #" << t+1 << ": yes" << endl;
            }
            print = true;
            if (gloabl_count == L)
                break;
        }
        gloabl_count = 0;
    }
    return 0;
}