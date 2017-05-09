#include <iostream>

using namespace std;

class UF {
    int *id, cnt, *sz;
public:
    UF(int N) {
        cnt = N;
        id = new int[N]; // id of sets contain this element;
        sz = new int[N]; // size of each set;
        for (int i = 0; i < N; i ++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF() {
        delete[] id;
        delete[] sz;
    }
    int find(int p) {
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    void merge(int x, int y) {
        int i = find(x);
        int j = find(y);
        if (i == j)
            return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        }
        else {
            id[j] = i;
            sz[i] += sz[j];
        }
        cnt --;
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    int num_sets() {
        return cnt;
    }
    int num_setMembers(int p) {
        return this->sz[this->find(p)];
    }
};

int main() {
    int T;
    cin >> T;
    string result[T];
    for (int t = 0; t < T; t ++) {
        int N, M, temp1, temp2;
        string relationship;
        cin >> N;
        cin >> M;
        UF myUF(N);
        int idHaters[N][N] = {0};
        int Haters_list[M][2] = {0};
        int numHaters[N] = {0};
        for (int m = 0; m < M; m ++) {
            cin >> relationship;
            cin >> temp1;
            cin >> temp2;
            temp1 -= 1;
            temp2 -= 1;
            if (relationship == "F")
                myUF.merge(temp1, temp2);
            else {
                Haters_list[m][0] = temp1;
                Haters_list[m][1] = temp2;
            }
        }
        for (int m = 0; m < M; m ++) {
            temp1 = Haters_list[m][0];
            temp2 = Haters_list[m][1];
            int root_temp1 = myUF.find(temp1);
            int root_temp2 = myUF.find(temp2);
            idHaters[root_temp1][numHaters[root_temp1]] = temp2;
            idHaters[root_temp2][numHaters[root_temp2]] = temp1;
            numHaters[root_temp1] += 1;
            numHaters[root_temp2] += 1;
        }
        for (int i = 0; i < N; i ++){
            if (numHaters[i] > 1) {
                for (int j = 0; j < numHaters[i]-1; j ++)
                    myUF.merge(idHaters[i][j],idHaters[i][j+1]);
            }
        }
        if (2*myUF.num_setMembers(0) > N)
            result[t] = "yes";
        else
            result[t] = "no";
    }
    for (int t = 0; t < T; t ++)
        cout << "Case #" << t+1 << ": " << result[t] << endl;
    return 0;
}
