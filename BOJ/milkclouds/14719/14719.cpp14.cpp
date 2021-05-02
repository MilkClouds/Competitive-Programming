# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<int,int>;

int H, W, A[501], ans, L[502], R[502];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> H >> W;
	rep(i, 0, W) cin >> A[i];
	rep(i, 0, W) L[i + 1] = max(L[i], A[i]);
	rep2(i, W, 0) R[i] = max(R[i + 1], A[i - 1]);
	rep(i, 0, W) ans += max(0, min(L[i], R[i + 2]) - A[i]);
	cout << ans << endl;
}