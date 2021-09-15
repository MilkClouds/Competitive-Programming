# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;
using vd = vector<double>;

int TC, P;
string A[101];
double sigmoid(double k){
    return 1 / (1 + exp(-k));
}
double sum(vd a){
    double ret = 0;
    for(auto i: a) ret += i;
    return ret;
}
double mean(vd a){
    return sum(a) / a.size();
}
double stdev(vd a){
    vd b(a.size());
    rep(i, 0, a.size()) b[i] = a[i] * a[i];
    return mean(b) - mean(a) * mean(a);
}
void summary(vd a){
    cout << a.size() << " " << mean(a) << " " << stdev(a) << endl;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC >> P;
    rep(tc, 0, TC){
        rep(i, 0, 100) cin >> A[i];
        vd Q(10000), S(100), p(100), tmp(100);
        rep(j, 0, 10000) {
            rep(i, 0, 100) Q[j] += A[i][j] == '1';
            if(Q[j] == 0) Q[j] = -5;
            else if(Q[j] == 100) Q[j] = 5;
            else Q[j] = -log(100 / Q[j] - 1);
        }
        double mult = pow(3 / stdev(Q), 0.5);
        for(auto& i: Q) i *= mult;
        vector<pair<double, int>> QC;
        rep(j, 0, 10000) QC.pb({Q[j], j});
        sort(all(QC));
        rep(i, 0, 100){
            rep(j, 0, 10000) S[i] += A[i][j] == '1';
            if(S[i] == 0) S[i] = -10;
            else if(S[i] == 10000) S[i] = 10;
            else S[i] = -log(10000 / S[i] - 1);
        }
        mult = pow(3 / stdev(S), 0.5);
        for(auto& i: S) i *= mult;
        rep(i, 0, 100) {
            rep(j, 0, 500){
                int a = QC[j].y, b = QC[10000 - j - 1].y;
                p[i] += (A[i][a] == '1') + (A[i][b] == '1') - (sigmoid(S[i] - Q[a]) + sigmoid(S[i] - Q[b]));
            }
        }
        printf("Case #%d: %d\n", tc + 1, max_element(all(p)) - p.begin() + 1);
    }
}
