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

ll K, N, A[11][21], rev[11][21], no[21][21], ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> K >> N;
	rep(i, 0, K){
		rep(j, 0, N){
			cin >> A[i][j];
			rev[i][A[i][j] - 1] = j;
		}
		rep(a, 0, N){
			rep(b, a + 1, N){
				if(no[a][b])continue;
				if((rev[i][a] < rev[i][b]) ^ (rev[0][a] < rev[0][b])) no[a][b] = 1;
			}
		}
	}
	rep(a, 0, N){
		rep(b, a + 1, N){
			ans += !no[a][b];
		}
	}
	cout << ans << endl;
}