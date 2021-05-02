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
const int MAX = 2e5 + 5;
ll N, K, A[MAX], ans, p[MAX];
map<ll, ll> m;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> K;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) p[i + 1] = p[i] + A[i];
	m[0]++;
	rep(i, 0, N){
		ans += m[p[i+1] - K];
		m[p[i+1]]++;
	}
	cout << ans;
}