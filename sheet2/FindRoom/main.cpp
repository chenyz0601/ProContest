#include <iostream>
#include <algorithm>

using namespace std;

struct Station {
    int begin, end;
};

bool myCompare(Station s1, Station s2) {
    return s1.begin < s2.begin;
}

int findRoom(Station *s, int length, int lineNum, int minNUm, int maxNum) {
    long int low = minNUm, high = maxNum, testLineNum, range, target = lineNum;
    while (low != high) {
        long int mid = ((low + high)>>1);
        testLineNum = 0;
        range = 0;
        for (int i = 0; i < length; i ++) {
            if (s[i].end < mid)
                testLineNum += s[i].end - s[i].begin + 1;
            else if (s[i].begin <= mid){
                testLineNum += mid - s[i].begin;
                range ++;
            }
            else
                break;
        }
        if (testLineNum < target && target <= testLineNum + range)
            return mid;
        else if (lineNum <= testLineNum)
            high = (high == mid) ? (mid - 1):mid;
        else
            low = (low == mid) ? (mid + 1):mid;
    }
    return low;
}

int main() {
    int T;
    cin >> T;
    int numF[T];
    int result[T][1000];
    for (int t = 0; t < T; t ++){
        int S, F;
        cin >> S >> F;
        numF[t] = F;
        int minNum = numeric_limits<int>::max(), maxNum = numeric_limits<int>::min();
        Station st[S];
        int fr[F];
        for (int s = 0; s < S; s ++) {
            int u, v;
            cin >> u >> v;
            minNum = min(minNum, u);
            maxNum = max(maxNum, v);
            st[s].begin = u;
            st[s].end = v;
        }
        for (int f = 0; f < F; f ++)
            cin >> fr[f];
        sort(st, st+S, myCompare);
        for (int f = 0; f < F; f ++)
            result[t][f] = findRoom(st, S, fr[f], minNum, maxNum);
    }
    for (int t = 0; t < T; t ++) {
        cout << "Case #" << t+1 << ": " << endl;
        for (int f = 0; f < numF[t]; f ++)
            cout << result[t][f] << endl;

    }
    return 0;
}