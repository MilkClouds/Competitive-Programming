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
const ll INF = 3e9, MOD = 1e9 + 7, MAX = 15e4;

int N, M, S[51], ban[MAX], chk[MAX];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M;
	rep(i, 0, M) { cin >> S[i]; ban[S[i]] = 1;}
	rep(i, 1, MAX){
		if(ban[i]) continue;
		rep(j, 1, MAX){
			if(i * j >= MAX) break;
			if(ban[j]) continue;
			rep(k, 1, MAX){
				if(i * j * k >= MAX)break;
				if(ban[k]) continue;
				chk[i * j * k] = 3;
			}
		}
	}
	rep(s, 0, MAX - N){
		if((N > s && chk[N - s] == 3) || chk[N + s] == 3){
			cout << s << endl;
			return 0;
		}
	}
}
	
