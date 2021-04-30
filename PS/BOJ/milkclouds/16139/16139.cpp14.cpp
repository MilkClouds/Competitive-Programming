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
const int MAX=2e5+1;
string S;
int q, A[27][MAX];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>S;
	rep(i,0,S.size()){
		rep(j,0,26){
			A[j][i+1] = A[j][i] + (S[i]=='a'+j);
		}
	}
	cin>>q;
	while(q--){
		char c; int i,j;
		cin>>c>>i>>j;
		c-='a';
		cout<<A[c][j+1]-A[c][i]<<"\n";
	}
}