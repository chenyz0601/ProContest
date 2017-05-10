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
        if (N == 1)
            result[t] = "yes";
        else {
            UF Friends(N);
            int Haters_list[M][2] = {0};
            for (int m = 0; m < M; m++) {
                cin >> relationship;
                cin >> temp1;
                cin >> temp2;
                temp1 -= 1;
                temp2 -= 1;
                if (relationship == "F") {
                    Friends.merge(temp1, temp2);
                    Haters_list[m][0] = 0;
                    Haters_list[m][1] = 0;
                } else {
                    Haters_list[m][0] = temp1;
                    Haters_list[m][1] = temp2;
                }
            }
            int myHaters[N];
            fill_n(myHaters, N, -1);
            for (int m = 0; m < M; m ++) {
                temp1 = Haters_list[m][0];
                temp2 = Haters_list[m][1];
                if (temp1 != temp2) {
                    int root_temp1 = Friends.find(temp1);
                    int root_temp2 = Friends.find(temp2);
                    if (myHaters[root_temp1] == -1)
                        myHaters[root_temp1] = root_temp2;
                    else {
                        Friends.merge(myHaters[root_temp1], root_temp2);
                        myHaters[root_temp1] = root_temp2;
                    }
                    if (myHaters[root_temp2] == -1)
                        myHaters[root_temp2] = root_temp1;
                    else {
                        Friends.merge(myHaters[root_temp2], root_temp1);
                        myHaters[root_temp2] = root_temp1;
                    }
                    /*
                    /*
                    Haters.merge(root_temp1, root_temp2);
                    if (root_temp1 == myRoot)
                        myHaters[root_temp2] = true;
                    if (root_temp2 == myRoot)
                        myHaters[root_temp1] = true;
                    */
                }
            }
            /*
            for (int i = 0; i < N; i ++){
                int curRoot = Friends.find(i);
                if (Haters.isConnected(curRoot, myRoot ) && !myHaters[curRoot])
                    Friends.merge(myRoot, curRoot);
            }
            */
            if (2*Friends.num_setMembers(0) > N)
                result[t] = "yes";
            else
                result[t] = "no";
        }
    }
    for (int t = 0; t < T; t ++)
        cout << "Case #" << t+1 << ": " << result[t] << endl;
    return 0;
}
