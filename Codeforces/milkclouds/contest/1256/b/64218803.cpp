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

ll Q, n, a[105], chk[105];

void process(int k){
	int pos = 0;
	rep(i, 1, n + 1) if(a[i] == k) pos = i - 1;
	while(pos>0 && !chk[pos] && a[pos] > a[pos + 1]){
		swap(a[pos], a[pos + 1]);
		chk[pos] = 1; pos--;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> Q;
	while(Q--){
		cin >> n;
		fill(chk, chk + n + 1,0);
		rep(i, 0, n) cin >> a[i + 1];
		rep(i, 0, n) process(i + 1);
		rep(i, 0, n) cout << a[i + 1] << " ";
		cout << "\n";
	}
}