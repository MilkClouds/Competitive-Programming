#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(int a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 3001;
int N, X[MAX], Y[MAX], cnt;
set<int> vx, vy;
vector<int> order_by_Y[MAX];
unordered_map<int, int> mx, my;
ll W[MAX], ans;

class Seg{
public:
  int n;
  vector<ll> a, lmax, rmax, mmax, pos;
  Seg(int n):n(n),a(4*n),lmax(4*n),rmax(4*n),mmax(4*n){}
  void update(int node, int l, int r, int i, ll val){
    if(r <= i || i < l) return;
    if(l + 1 == r){
      a[node] += val;
      lmax[node] = rmax[node] = mmax[node] = max(0LL, a[node]);
      return;
    }
    int m = l + r >> 1, left = node * 2, right = node * 2 + 1;
    update(left, l, m, i, val);
    update(right, m, r, i, val);
    a[node] = a[left] + a[right];
    lmax[node] = max(a[left] + lmax[right], lmax[left]);
    rmax[node] = max(a[right] + rmax[left], rmax[right]);
    mmax[node] = max({mmax[left], mmax[right], rmax[left] + lmax[right]});
  }
};

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) {
		cin >> X[i] >> Y[i] >> W[i];
		vx.insert(X[i]);
		vy.insert(Y[i]);
	}
	for(auto j: vx) {
		mx[j] = cnt++;
	}
	cnt = 0;
	for(auto j: vy) {
		my[j] = cnt++;
	}
	rep(i, 0, N) {
		X[i] = mx[X[i]];
		Y[i] = my[Y[i]];
		order_by_Y[Y[i]].pb(i);
	}
	Seg tree = Seg(vx.size());
	rep(y_start, 0, vy.size()){
		fill(all(tree.a), 0);
		fill(all(tree.lmax), 0);
		fill(all(tree.rmax), 0);
		fill(all(tree.mmax), 0);
		rep(y_end, y_start, vy.size()){
			for(auto i: order_by_Y[y_end]){
				tree.update(1, 0, vx.size(), X[i], W[i]);
			}
			ans = max(ans, tree.mmax[1]);
		}
	}
	cout << ans << endl;
}
