# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
const int MAX = 2e5;

int N, C, x[MAX];

bool f(int dist){
	int last = x[0], cnt = 1;
	rep(i, 1, N){
		if(x[i] - last >= dist) {
			last = x[i];
			cnt++;
		}
	}
	return cnt >= C;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> C;
	rep(i, 0, N) cin >> x[i];
	sort(x, x + N);
	int lo = 1, hi = 1e9;
	while(lo + 1 < hi){
		int m = lo + hi >> 1;
		if(f(m)) lo = m;
		else hi = m;
	}
	cout << lo;
}