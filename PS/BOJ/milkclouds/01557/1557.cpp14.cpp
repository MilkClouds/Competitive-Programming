#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6;
int arr[MAX],mobius[MAX];
void sieve(){
	for(int i=2;i<MAX;i++){
		if(arr[i])continue;
		for(int j=i;j<MAX;j+=i){
			if(mobius[j]==1)continue;
			arr[j]++;
			if((j/i)%i==0)mobius[j]=1;
		}
	}
}
long long func(int K){
	long long ret=0,lim=sqrt(K);
	for(int i=1;i<=lim;i++){
		ret+=mobius[i]*(K/(i*i));
	}
	return ret;
}
int K;
int main(){
	sieve();
	for(int i=1;i<MAX;i++)mobius[i]=mobius[i]==1?0:((arr[i]&1)?-1:1);
	cin>>K;
	long long lo=0, hi=2e9;
	while(lo<hi){
		int m=lo+hi>>1;
		if(func(m) > K) hi=m-1;
		else if(func(m)==K)hi=m;
		else lo=m+1;
	}
	cout<<lo;
}