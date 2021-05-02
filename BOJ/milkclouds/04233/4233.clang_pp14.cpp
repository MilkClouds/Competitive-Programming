#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a,p;
ll pow(ll a,ll b,ll mod){
	if(b==0)return 1;
	if(b==2)return a*a%mod;
	if(b&1)return pow(pow(a,b/2,mod),2,mod)*a %mod;
	return pow(pow(a,b/2,mod),2,mod)%mod;
}
bool isprime(ll a){
	int limit=sqrt(a);
	for(int i=2;i<=limit;i++)if(a%i==0)return 0;
	return 1;
}
int main(){
	while(scanf("%d%d",&p,&a) and p){
		if(isprime(p)){cout<<"no\n";continue;}
		cout<<((pow(a,p,p)==a)?"yes\n":"no\n");
	}
}