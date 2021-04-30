#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
const int MAX=1e5+5;
int N,K,M,cnt=1,A[MAX];
vector<int> suc[31];

void GET(int M){
	if(M==1)return;
	GET(M/2);
	rep(i,0,K){
		suc[cnt][i]=suc[cnt-1][suc[cnt-1][i]];
	}
	if(M&1){
		rep(i,0,K){
			suc[cnt][i]=suc[0][suc[cnt][i]];
		}
	}
	cnt++;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>K>>M;
	rep(i,0,N){
		cin>>A[i];A[i]--;
	}
	rep(i,0,31)suc[i]=vector<int>(K,0);
	rep(i,0,K){
		cin>>suc[0][i];suc[0][i]--;
	}
	GET(M-1);
	rep(i,0,N){
		cout<<suc[cnt-1][A[i]]+1<<" ";
	}
}