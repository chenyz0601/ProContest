#include <iostream>

#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int T;
    double error = 0.0000000001;
    cin >> T;
    double x[T];
    for (int t = 0; t < T; t ++) {
        double d, u, v;
        int p;
        cin >> d >> p >> u >> v;
        double left = u;
        double right = d-v;
        double cayon = v-u;
        double l = 0.0;
        auto h = d;
        while (h-l > error) {
            double m = (l+h)/2;
            int lp = (int) (left / m);
            int rp = (int) (right / m);
            double lRemain = left - lp*m;
            double rRemain = right - rp*m;
            double gap = lRemain + rRemain + cayon;
            int freep = lp + rp + 2;
            if (freep > p)
                l = m;
            else if (freep < p)
                h = m;
            else if (gap < m)
                h = m;
            else
                l = m;
        }
        x[t] = (l+h)/2;
    }
    for (int t = 0; t < T; t ++)
        //cout << "Case #" << t +1 << ": " << setprecision(10) << x[t] << endl;
        printf("Case #%d: %.10f\n",t+1,x[t]);
    return 0;
}