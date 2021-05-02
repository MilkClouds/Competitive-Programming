#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> fibo={1,2};
ll N,T=1,last,M;
int main(){
	cin>>N;M=N;
	while(fibo[T]<=N){fibo.push_back(fibo[T]+fibo[T-1]);T++;}
	while(T--)if(N>=fibo[T])N-=last=fibo[T];
	cout<<(M^last?last:-1);
}