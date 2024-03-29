# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1 };
ll POW(ll a, ll b, ll MMM) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a / GCD(a, b) * b; }
ll INV(ll a, ll m) {
	ll m0 = m, y = 0, x = 1;
	if (m == 1)	return 0;
	while (a > 1) {
		ll q = a / m;
		ll t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) x += m0;
	return x;
}
pll EXGCD(ll a, ll b) {
	if (b == 0) return { 1,0 };
	auto t = EXGCD(b, a%b);
	return { t.second,t.first - t.second*(a / b) };
}
bool OOB(ll x, ll y, ll N, ll M) { return 0 > x || x >= N || 0 > y || y >= M; }
#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define sf1(a) cin >> a
#define sf2(a,b) cin >> a >> b
#define sf3(a,b,c) cin >> a >> b >> c
#define sf4(a,b,c,d) cin >> a >> b >> c >> d
#define sf5(a,b,c,d,e) cin >> a >> b >> c >> d >> e
#define sf6(a,b,c,d,e,f) cin >> a >> b >> c >> d >> e >> f
#define pf1(a) cout << (a) << ' '
#define pf2(a,b) cout << (a) << ' ' << (b) << ' '
#define pf3(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << ' '
#define pf4(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '
#define pf5(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' '
#define pf6(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << ' '
#define pf0l() cout << '\n';
#define pf1l(a) cout << (a) << '\n'
#define pf2l(a,b) cout << (a) << ' ' << (b) << '\n'
#define pf3l(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << '\n'
#define pf4l(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << '\n'
#define pf5l(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << '\n'
#define pf6l(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << '\n'
#define pfvec(V) for(auto const &t : V) pf1(t)
#define pfvecl(V) for(auto const &t : V) pf1(t); pf0l()

ull mul(ull x, ull y, ull m){
  return (ull)((__int128)x * y % m);
}
ull lpow(ull x, ull y, ull m){
  ull r = 1;
  x %= m;
  while(y){
    if(y&1) r = mul(r,x,m);
    x = mul(x,x,m);
    y >>= 1;
  }
  return r;
}
bool MR(ull n, ull a){
  if(n%a==0) return 0;
  int cnt = -1;
  ull d = n-1;
  while(!(d&1)){
    d >>= 1;
    cnt++;
  }
  ull p = lpow(a,d,n);
  if(p==1 or p==n-1) return 1;
  while(cnt--){
    p=mul(p,p,n);
    if(p==n-1) return 1;
  }
  return 0;
}
bool isPrime_MR(ll n){
  for(auto p : {2,3,5,7,11,13,17,19,23,29,31,37}){
    if(n == p) return 1;
    if(n > 40 && !MR(n,p)) return 0;
  }
  if(n <= 40) return 0;
  return 1;
}


ll PollardRho(ll n){
  ll x = rand()%(n-2)+2;
  ll y = x;
  ll c = rand()%(n-1)+1;
  while(true){
    x = (mul(x,x,n)+c)%n;
    y = (mul(y,y,n)+c)%n;
    y = (mul(y,y,n)+c)%n;
    ll d = __gcd(abs(x-y),n);
    if(d==1) continue;
    if(!isPrime_MR(d)) return PollardRho(d);
    else return d;
  }
}


void getFactor(ll n, vector<ll>& f){
  while(!(n&1)){
    n >>= 1;
    f.push_back(2);
  }
  if(n==1) return;
  while(!isPrime_MR(n)){
    ll d = PollardRho(n);
    while(n%d == 0){
      f.push_back(d);
      n /= d;
    }
    if(n==1) break;
  }
  if(n != 1) f.push_back(n);
}

int main(void) {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
  ll N;
  sf1(N);
  if(N==1) return 0;
  vl f;
  getFactor(N,f);
  sort(all(f));
    
  for(auto e : f) pf1l(e);
}
