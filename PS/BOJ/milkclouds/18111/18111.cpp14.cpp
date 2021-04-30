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
using pi=pair<ll,ll>;
const int MAX = 1e3;

int M, N, B, A[MAX][MAX], MM, mm = 1e9, ans;

int query(int h){
	int BB = B, ans = 0;
	rep(i, 0, N) rep(j, 0, M){
		if(A[i][j] < h) {
			ans += h - A[i][j];
			BB -= h - A[i][j];
		}
		else if (A[i][j] > h){
			ans += (A[i][j] - h) * 2;
			BB += A[i][j] - h;
		}
	}
	return BB < 0 ? 1e9 : ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M >> B;
	rep(i, 0, N) rep(j, 0, M) { cin >> A[i][j]; MM = max(MM, A[i][j]);}
	rep(h, 0, MM + 1) {
		int cost = query(h);
		if(cost <= mm) {
			mm = cost; ans = h;
		}
	}
	cout << mm << " " << ans << endl;
}