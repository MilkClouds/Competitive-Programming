#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

int T;
string N;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> v;
		for(int i=0;i<N.size();i++)v.pb(N[i]-'0');
		if(!next_permutation(all(v))){cout<<"BIGGEST\n";continue;}
		for(auto i:v)cout<<i;
		cout<<"\n";
	}
}
	