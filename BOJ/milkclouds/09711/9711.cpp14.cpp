#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
ll MOD;
class Matrix{
public:
	int N,M;
	vector<vector<ll>> A;
	Matrix():Matrix(1,1,0){}
	Matrix(int N,int M):Matrix(N,M,0){}
	Matrix(int N,int M,ll v):N(N),M(M){
		A = vector<vector<ll>>(N, vector<ll>(M, v));
	}
	Matrix operator *(const Matrix O)const{
		Matrix R(N,O.M);
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				for(int k=0; k<O.M; k++)
					R.A[i][k] = (R.A[i][k] + 1LL*A[i][j]*O.A[j][k]) % MOD;
		return R;
	}
	void pprint(){
		rep(i,0,N){rep(j,0,M)cout<<A[i][j]<<" ";cout<<"\n";}
	}
} Neutral;
Matrix power(Matrix M, ll k){
	if(k==0)return Neutral;
	if(k==1)return M;
	return power(M*M,k/2)*(k%2?M:Neutral);
}
ll fibo(ll n){
	Matrix A(2,2,1),C(2,2);
	rep(i,0,2)C.A[i][i]=1; Neutral=C; 
	A.A[1][1]=0;
	Matrix ans=power(A,n);
	return ans.A[0][1];
}
int sum_odd(ll N){
	return fibo(N+(N%2));
}
int sum_even(ll N){
	return fibo(N+!(N%2))-1;
}
int sum(ll n){return (sum_odd(n)+sum_even(n))%MOD;}

ll T,N;
int main(){
	cin>>T;
	rep(i,1,T+1){
		cin>>N>>MOD;
		printf("Case #%d: %d\n",i,fibo(N)%MOD);
	}
}