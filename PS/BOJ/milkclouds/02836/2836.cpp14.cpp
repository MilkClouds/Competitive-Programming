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
const ll MAX = 3e5;

ll N, M, u, v, dist, l, r;
pi A[MAX];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// from 11:43
	cin >> N >> M;
	rep(i, 0, N) {
		cin >> u >> v;
		A[i] = {u, v};
	}

	sort(A, A + N, [](pi& a, pi& b){return a.y < b.y;});
	rep(i, 0, N){
		if(A[i].x < A[i].y){
			continue;
		}
		if(A[i].x > A[i].y){
			if(A[i].y > r){
				dist += 2 * (r - l);
				l = A[i].y;
				r = A[i].x;
			}
			else{
				if(l==0) l = A[i].y;
				r = max(r, A[i].x);
			}
		}
	}
	dist += 2 * (r - l);
	cout << dist + M;
}
	
