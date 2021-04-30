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
int N,M;
tuple<ll,ll,char> A[1005];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M;
	rep(i, 0, M){
		ll a,b; char c;
		cin >> a >> b>> c;
		A[i] = {b,a,c};
	}
	sort(A,A+M);
	rep(i, 0, M){
		cout << get<2>(A[i]);
	}
}