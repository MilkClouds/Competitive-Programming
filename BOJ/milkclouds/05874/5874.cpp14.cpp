#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
ll lc,ans;
string S;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>S;
	rep(i,0,S.size()-1){
		if(S[i]==S[i+1] && S[i]=='(')lc++;
		if(S[i]==S[i+1] && S[i]==')')ans+=lc;
	}
	cout<<ans;
}
	