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
const int MAX=1e6+1;
ll N,T,A[MAX];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rep(i,1,MAX){for(ll j=i;j<MAX;j+=i){A[j]+=i;}A[i]+=A[i-1];}
	cin>>T;
	while(T--){cin >> N;cout<<A[N]<<"\n";}
}