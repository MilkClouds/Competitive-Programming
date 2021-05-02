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

int N;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while((cin >> N) && N){
		int T = 1, i = 1;
		while(T % N){
			T = (T * 10 + 1) % N; i++;
		}
		cout << i << "\n";
	}
}