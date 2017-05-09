#include <iostream>
#include <algorithm>

using namespace std;
long long int findRight(long long int *sum, int a, int n) {
    int low = a, high = n;
    if (low == high)
        return sum[n]-sum[-1];
    else {
        int mid;
        while (1) {
            if (low == high-1)
                break;
            mid = (int) floor((low + high) / 2);
            long long int left = sum[mid]-sum[a];
            long long int right = sum[n]-sum[mid];
            if (left-right > 0)
                high = mid;
            else
                low = mid;
        }
        return min(max(sum[low]-sum[a], sum[n]-sum[low]), max(sum[high]-sum[a], sum[n]-sum[high]));
    }
}
int main() {
    int T;
    cin >> T;
    long long int result[T];
    for (int t = 0; t < T; t ++) {
        int n;
        long long int p, q, r, s;
        cin >> n >> p >> q >> r >> s;
        if (n == 1)
            result[t] = 0;
        else if (n == 2) {
            int sum1 = (int) ((1 * p + q) % r + s);
            int sum2 = (int) ((2 * p + q) % r + s);
            result[t] = min(sum1,sum2);
        } else {
            long long int sum[n+1];
            sum[0] = 0;
            for (long long int i = 1; i < n+1; i ++)
                sum[i] = sum[i-1]+(i*p+q)%r+s;
            long long int toTom = sum[n];
            long long int left, temp;
            int a = 0;
            while (2*sum[a] < sum[n]) {
                a ++;
                left = sum[a-1];
                temp = max(left, findRight(sum, a-1, n));
                if (toTom > temp)
                    toTom = temp;
            }
            result[t] = sum[n]-toTom;
        }
    }
    for (int t = 0; t < T; t ++)
        cout << "Case #" << t+1 << ": " << result[t] << endl;
    return 0;
}