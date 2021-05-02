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
const int MAX = 2e5+1;

string S,S2;
int N;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin >> S >> N){
		int i = 0;
		S2=S;
		do{i++;}while(next_permutation(S.begin(),S.end())&&i<N-1);
		cout << S2 << " " << N << " = " << ((i < N-1) ? "No permutation" : S) << "\n";
	}
}