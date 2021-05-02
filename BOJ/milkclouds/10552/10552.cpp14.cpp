#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int MAX=1e5+5;

int N,M,P,a[MAX],b[MAX],c[MAX],T,cnt;
unordered_map<int,bool> chk;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M>>P;
	rep(i,1,N+1){
		cin>>a[i]>>b[i];
		if(!c[b[i]])c[b[i]]=i;
	}
	while(c[P]){
		chk[P]=1;
		P=a[c[P]];cnt++;
		if(chk[P]){cout<<-1;return 0;}
	}
	cout<<cnt;
}
	