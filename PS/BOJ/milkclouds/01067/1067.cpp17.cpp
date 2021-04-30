#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define sz(v) ((ll)(v).size())
#define all(v) (v).begin(), (v).end()
 
using namespace std;
typedef long long ll;
typedef complex<double> base;

ll N, ans;
vector<ll> X, Y, res;

void fft(vector<base> &a, bool invert) {
    ll n = sz(a);
    for (ll i=1,j=0;i<n;i++){
        ll bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (ll len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (ll i=0;i<n;i+=len){
            base w(1);
            for (ll j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (ll i=0;i<n;i++) a[i] /= n;
    }
}
 
void multiply(const vector<ll> &a,const vector<ll> &b,vector<ll> &res) {
    vector <base> fa(all(a)), fb(all(b));
    ll n = 1;
    while (n < max(sz(a),sz(b))) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (ll i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (ll i=0;i<n;i++) res[i] = ll(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> N;
	X.resize(N * 2); Y.resize(N);
	rep(i, 0, N) {cin >> X[i]; X[i + N] = X[i];}
	rep(i, 0, N) cin >> Y[N - i - 1];
	multiply(X, Y, res);
	rep(i, N, N * 2) ans = max(ans, res[i]);
	cout << ans;
}
