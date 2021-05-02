# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
using namespace std;
using ll=long long;
const int MAX=2e5;

int N,Q,a[MAX],op,i,x,pivot;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	rep(i,0,N) cin >> a[i];
	while(Q--){
		cin >> op >> i;
		if(op == 1){
			cin>>x;
			a[(pivot + i - 1 + N)%N] += x;
		}
		else if(op == 2) pivot -= i;
		else pivot += i;
		pivot = (pivot + N) % N;
	}
	rep(i,0,N) cout << a[(i + pivot + N)%N] <<" ";
}