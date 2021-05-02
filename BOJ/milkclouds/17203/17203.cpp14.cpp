# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const int MAX=1e4+5;
int N,Q,a[MAX],b[MAX],c[MAX];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> Q;
	rep(i, 0, N) cin >> a[i];
	rep(i, 0, N-1) b[i] = abs(a[i+1]-a[i]);
	rep(i, 0, N-1) c[i+1] = c[i]+b[i];
	rep(i, 0, Q){
		int a,b;
		cin >> a >> b;
		cout << c[b-1] - c[a-1] << "\n";
	}
}