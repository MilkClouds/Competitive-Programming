#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<int,int>;

ll N,K,sum;

int main(){
	cin>>N>>K;
	int T=N-1;
	while(sum+T<=K&&T>0){
		sum+=T;
		cout<<T+1<<" ";
		T--;
	}
	int pos=K-sum;
	int remain=T+1;
	rep(i,1,1+remain){
		if(i<remain-pos)cout<<i<<" ";
		else if(i==remain-pos)cout<<T+1<<" ";
		else cout<<i-1<<" ";
	}
}