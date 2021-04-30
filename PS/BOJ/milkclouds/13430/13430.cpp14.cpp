#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
class Matrix{
public:
	int N,M;
	vector<vector<int>> A;
	Matrix():Matrix(1,1,1){}
	Matrix(int N,int M):Matrix(N,M,0){}
	Matrix(int N,int M,int v):N(N),M(M){
		A = vector<vector<int>>(N, vector<int>(M, v));
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
Matrix power(Matrix M, int k){
	if(k==0)return Neutral;
	if(k==1)return M;
	return power(M*M,k/2)*(k%2?M:Neutral);
}
int K,N;

int main(){
	cin>>K>>N;
	Matrix A(K+2,K+2),B(K+2,1,1),C(K+2,K+2);
	rep(i,0,K+2)C.A[i][i]=1; Neutral=C; 
	rep(i,0,K+2)rep(j,0,i+1)A.A[i][j]=1;
	Matrix ans=power(A,N-1)*B;
	cout<<ans.A[K+1][0];
}