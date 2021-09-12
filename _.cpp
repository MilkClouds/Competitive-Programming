#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;


typedef complex<double> cpx;

void fft(vector<cpx>& a) {
    // https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/FastFourierTransform.h
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<cpx> R(2, 1);
    static vector<cpx> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0, acos(-1.0) / k);
        for (int i = k; i < 2 * k; i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];
                cpx z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            } 
        }
    }
}

vector<ll> conv(const vector<ll>& a, const vector<ll>& b) {
    if (a.empty() || b.empty()) return {};
    vector<ll> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<cpx> in(n), out(n);
    copy(a.begin(), a.end(), begin(in));
    for (size_t i = 0; i < b.size(); i++) in[i].imag(b[i]);
    fft(in);
    for (cpx& x : in) x *= x;
    for (int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    // for (size_t i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
    for (size_t i = 0; i < res.size(); i++) res[i] = round(imag(out[i]) / (4 * n));
    // for (size_t i = 0; i < res.size(); i++) res[i] = (ll) round(imag(out[i]) / (4 * n)) % MOD; // for MOD
    return res;
}

const int MAX = 1e5;
int N, x;
vector<ll> A1, A2, B1, B2;
priority_queue<pl> pq;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    A1.resize(MAX);
    A2.resize(MAX);
    B1.resize(MAX);
    B2.resize(MAX);
    rep(i, 0, N){
        cin >> x;
        A1[x]++;
        A2[x] = 1;
    }
    rep(i, 0, N){
        cin >> x;
        B1[x]++;
        B2[x] = 1;
    }
    auto&& ret11 = conv(A1, B1);
    auto&& ret12 = conv(A1, B2);
    auto&& ret21 = conv(A2, B1); 
    auto&& ret22 = conv(A2, B2);
    rep(i, 0, 10) cout << ret11[i] << " "; cout << endl;
    rep(i, 0, 10) cout << ret12[i] << " "; cout << endl;
    rep(i, 0, 10) cout << ret21[i] << " "; cout << endl;
    rep(i, 0, 10) cout << ret22[i] << " "; cout << endl;
    rep(i, 0, ret11.size()){
        ret11[i] -= ret12[i] + ret21[i];
        pq.em(ret11[i], i);
    }
    cout << pq.top().x << " " << pq.top().y << endl;
}
