#include <iostream>
#include <algorithm>
#include <cmath>

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
        int n, p, q, r, s;
        cin >> n >> p >> q >> r >> s;
        if (n == 1)
            result[t] = 0;
        else if (n == 2) {
            int sum1 = (1 * p + q) % r + s;
            int sum2 = (2 * p + q) % r + s;
            result[t] = min(sum1,sum2);
        } else {
            long long int sum[n+1];
            sum[0] = 0;
            for (int i = 1; i < n+1; i ++)
                sum[i] = sum[i-1]+((i)*p+q)%r+s;
            long long int toTom = sum[n];
            long long int left, temp;
            for (int a = 1; a < n+1; a ++) {
                left = sum[a-1];
                temp = max(left, findRight(sum, a-1, n));
                if (toTom > temp)
                    toTom = temp;
            }
            /*
            int a = 1, b = n;
            while (sum[a-1]*3 < sum[n])
                a ++;
            while (3*(sum[n]-sum[b]) < sum[n])
                b --;
            for (int aa = a-1; aa < a+1; aa ++){
               for (int bb = b; bb < b+2; bb ++) {
                    long long int temp = max(max(sum[max(0,aa-1)], sum[bb]-sum[max(0,aa-1)]), sum[n]-sum[bb]);
                    if (toTom > temp)
                        toTom = temp;
                }
            }
            */
            result[t] = sum[n]-toTom;
        }
            /*
            long long int left = sum[a-1];
            long long int right = sum[n]-sum[b];
            long long int temp;
            toTom = sum[min(n,b+1)]-sum[max(0,a-2)];
            if (left > right) {
                long long int mid = sum[b]-sum[max(0,a-2)];
                if (mid < right)
                    temp = right;
                else if (mid < left)
                    temp = mid;
                else
                    temp = left;
                if (toTom > temp)
                    toTom = temp;
            } else {
                long long int mid = sum[min(b+1,n)]-sum[a-1];
                if (mid < left)
                    temp = left;
                else if (mid < right)
                    temp = mid;
                else
                    temp = right;
                if (toTom > temp)
                    toTom = temp;
            }
             result[t] = sum[n]-toTom;
        }
        long long int sum[n];
        sum[0] = (1*p+q)%r+s;;
        for (int i = 1; i < n; i ++)
            sum[i] = sum[i-1]+((1+i)*p+q)%r+s;
        long long int toTom;
        long long int T_max;

        for (int a = 0; a < n; a ++){
            for (int b = a; b < n; b ++) {
                if (a == 0)
                    T_max = 0;
                else
                    T_max = sum[a-1];
                if (T_max < sum[b]-T_max)
                    T_max = sum[b]-T_max;
                if (T_max < sum[n-1]-sum[b])
                    T_max = sum[n-1] - sum[b];
                if (T_max < toTom)
                    toTom = T_max;
            }
        }
        result[t] = sum[n-1]-toTom;
         */
    }
    for (int t = 0; t < T; t ++)
        cout << "Case #" << t+1 << ": " << result[t] << endl;
    return 0;
}