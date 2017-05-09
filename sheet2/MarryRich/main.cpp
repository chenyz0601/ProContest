#include <iostream>

class UF {
    int *id, cnt, *sz;
public:
    UF(int N){
        cnt = N; // cnt is the total number of sets
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i ++){
            id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF(){delete [] id; delete [] sz;}

    int find(int p){
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root){
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    void merge(int x, int y){
        int i = find(x);
        int j = find(y);
        if (i == j)
            return;
        if (sz[i] < sz[j]){
            id[i] = j;
            sz[j] += sz[i];
        }
        else{
            id[j] = i;
            sz[i] += sz[j];
        }
        cnt --;
    }
    bool isConnected(int x, int y){
        return find(x) == find(y);
    }
    int count(){
        return cnt;
    }
};

using namespace std;
int main() {
    int T;
    cin >> T;
    int marrywith[T];
    for (int t = 0; t < T; t ++) {
        int a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        int money[a-1];
        UF myUF(a);
        UF myRelatives(a);
        for (int aa = 0; aa < a-1; aa ++)
            cin >> money[aa];
        int temp1, temp2;
        for (int bb = 0; bb < b; bb ++) {
            cin >> temp1;
            cin >> temp2;
            myRelatives.merge(temp1-1, temp2-1);
        }
        for (int cc = 0; cc < c; cc ++) {
            cin >> temp1;
            cin >> temp2;
            myUF.merge(a-1, temp1-1);
            myUF.merge(a-1, temp2-1);
            myRelatives.merge(temp1-1, temp2-1);
        }
        for (int i = 0; i < a-1; i ++){
            if (myUF.find(i) == myUF.find(a-1) || myRelatives.find(i) == myRelatives.find(a-1))
                money[i] = 0;
        }
        marrywith[t] = money[0];
        for (int i = 1; i < a-1; i ++){
            if (money[i] > marrywith[t])
                marrywith[t] = money[i];
        }
    }

    for (int t = 0; t < T; t ++)
        cout << "Case #" << t+1 << ": " << marrywith[t] <<endl;
    return 0;
}