#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
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


typedef double f_t;
typedef complex<f_t> C;

void fft(vector<C>& a) {
    // https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/FastFourierTransform.h
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<C> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar((f_t) 1.0, acos((f_t) -1.0) / k);
        for (int i = k; i < 2 * k; i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                auto x = (f_t *)&rt[j+k], y = (f_t *)&a[i+j+k];
                C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            } 
        }
    }
}

vector<f_t> conv(const vector<f_t>& a, const vector<f_t>& b) {
    if (a.empty() || b.empty()) return {};
    vector<f_t> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<C> in(n), out(n);
    copy(a.begin(), a.end(), begin(in));
    for (size_t i = 0; i < b.size(); i++) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    for (int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    for (size_t i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
    return res;
}

vector<ll> multiply(vector<ll>& a, vector<ll>& b){
    auto&& A = vector<f_t>(all(a));
    auto&& B = vector<f_t>(all(b));
    auto&& tmp = conv(A, B);
    auto&& ret = vector<ll>(tmp.size());
    for(int i = 0; i < tmp.size(); i++) ret[i] = round(tmp[i]);
    return ret;
}
const int MAX = 5e5;
int N, quad[MAX];
ll ans, sep;
vector<ll> A;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N) quad[(i * i) % N]++;
    A.assign(N, 0);
    rep(i, 1, N){
        A[(i * i) % N]++;
        sep += quad[(i * i * 2) % N];
    }
    auto&& ret = multiply(A, A);
    rep(i, N, 2 * N - 1) ret[i - N] += ret[i];
    rep(i, 1, N) ans += ret[(i * i) % N];
    cout << (ans - sep) / 2 + sep << endl;
}
