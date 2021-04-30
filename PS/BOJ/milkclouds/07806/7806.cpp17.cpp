#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int M=4e4;
int arr[M],n,k,ans=1;
vector<int> prime;
void sieve(){
	prime.pb(2);
	for(int i=3;i<M;i+=2){
		if(arr[i])continue;
		prime.pb(i);
		for(int j=i*i;j<M;j+=i)arr[j]=1;
	}
}
unordered_map<int,int> dec(int n){
	unordered_map<int,int> ret;
	for(auto i:prime){
		while(n%i==0){
			ret[i]++;
			n/=i;
		}
	}
	if(n>1) ret[n]++;
	return ret;
}
int main(){
	sieve();
	while(~scanf("%d %d",&n,&k)){
		ans=1;
		auto mm=dec(k);
		for(auto [i,j]:mm){
			int t=0,s=n;
			while(s){
				t+=s/i;
				s/=i;
			}
			ans*=pow(i,min(j,t));
		}
		cout<<ans<<'\n';
	}
}