#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=50005;

ll arr[MAX],mobius[MAX],pSum[MAX];
ll diva,moda,stepa,divb,modb,stepb,step;
void sieve(){
	for(ll i=2;i<MAX;i++){
		if(arr[i])continue;
		for(ll j=i;j<MAX;j+=i){
			if(mobius[j]==1)continue;
			arr[j]++;
			if((j/i)%i==0)mobius[j]=1;
		}
	}
}
ll gcd(ll a,ll b){return a%b?gcd(b%a,a):a;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	sieve();
	for(ll i=1;i<MAX;i++)mobius[i]=mobius[i]==1?0:((arr[i]&1)?-1:1);
	for(int i=1;i<MAX;i++)pSum[i]=mobius[i]+pSum[i-1];
	ll T;
	cin>>T;
	while(T--){
		ll a,b,d,ans=0;

		cin>>a>>b>>d;
		ll a_d=a/d, b_d=b/d,gcd_n_m=gcd(a_d,b_d);

		for(int k=1;k<=min(a_d,b_d);k++){
			diva=a_d/k; moda=a_d%k; stepa=moda/diva;
			divb=b_d/k; modb=b_d%k; stepb=modb/divb;
			step=min(stepa,stepb);
			ans+=(pSum[k+step]-pSum[k-1])*diva*divb;
			k+=step;
		}
		cout<<ans<<"\n";
	}
}