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
const int MAX = 4e6;
int flag, u, d, chk[MAX], cnt;
string S;
deque<int> deq;
vector<int> ans(MAX);
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> S;
    rep(i, 0, S.size()){
        if(S[i] == '-'){
            flag ^= 1;
            continue;
        }
        if(flag) d++;
        else u++;
        if(flag) chk[cnt++] = 1;
        else chk[cnt++] = 0;
        if(flag)deq.push_back(S[i] - '0');
        else deq.push_front(S[i] - '0');
    }
    auto&& a = vector<ll>(all(deq));
    auto&& b = vector<ll>(u + d, 1);
    rep(i, 0, u + d) b[i] = !chk[(u + d) - i - 1];

    for(auto i: a) cout << i<< " "; cout << endl;
    for(auto i: b) cout << i<< " "; cout << endl;
    auto&& ret1 = conv(a, b);

    reverse(all(deq));
    a = vector<ll>(all(deq));
    rep(i, 0, u + d){
        b[i] = chk[i];
    }
    auto&& ret2 = conv(a, b);
    rep(i, u + d - 1, ret1.size()) cout << ret1[i] << " "; cout << endl;
    rep(i, u + d - 1, ret2.size()) cout << ret2[i] << " "; cout << endl;
    rep(i, u + d - 1, ret1.size()) ans[i - (u + d - 1)] += ret1[i];
    rep(i, u + d - 1, ret2.size()) ans[i - (u + d - 1)] += ret2[i];
    rep(i, 0, MAX){
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    int j;
    rep2(i, 0, MAX){
        if(ans[i] == 0) continue;
        j = i;
        break;
    }
    rep2(i, 0, j + 1) cout << ans[i];
}
