#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
const int MOD=1e4;

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
} Neutral(2,2);

Matrix power(Matrix M, int k){
	if(k==0)return Neutral;
	if(k==1)return M;
	return power(M*M,k/2)*(k%2?M:Neutral);
}
int n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	Neutral.A[0][0]=Neutral.A[1][1]=1;
	while(~scanf("%d",&n)&&~n){
		Matrix A(2,2,1);
		A.A[1][1]=0;
		cout<<power(A,n).A[0][1]<<"\n";
	}
}