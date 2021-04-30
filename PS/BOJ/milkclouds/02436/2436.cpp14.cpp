#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,r,mv,bitmask,c,d;
pair<ll,ll> ans;
map<ll,ll> dic;
int main(){
	cin>>a>>b;
	r=b/a;
	mv=1e10;
	for(int i=2,END=sqrt(r);i<=END;i++){
		while(r%i==0){dic[i]=(dic[i]?dic[i]:1)*i;r/=i;}
	}
	if(r>1)dic[r]=(dic[r]?dic[r]:1)*r;
	r=b/a;
	for(int END=1<<dic.size();bitmask<END;bitmask++){
		c=1;d=1;
		auto beg=dic.begin();
		for(int i=0;i<dic.size();i++,beg++){
			if(bitmask & (1<<i))c*=beg->second;
			else d*=beg->second;
		}
		c*=a;d*=a;
		if(mv>c+d){mv=c+d;ans={c,d};}
	}
	if(ans.first>ans.second)swap(ans.first,ans.second);
	cout<<ans.first<<" "<<ans.second;
}