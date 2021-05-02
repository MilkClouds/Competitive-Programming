#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
int N,K,i=1,T;
string S;
deque<char> ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>K>>S;T=K;ans.push_back(S[0]);
	while(i<N){
		if(K==0){
			rep(j,i,N)ans.push_back(S[j]);
			break;
		}
		while(!ans.empty()&&ans.back()<S[i]&&K){
			K--;
			ans.pop_back();
		}
		ans.push_back(S[i]);
		i++;
	}
	rep(i,0,N-T)cout<<ans[i];
}
	