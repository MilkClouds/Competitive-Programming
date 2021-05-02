#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

int N,A[21][21];
inline int area(int x1,int y1,int x2,int y2){return (1+x2-x1)*(1+y2-y1);}
int solve(int x1,int y1,int x2,int y2,int prev){
	if(area(x1,y1,x2,y2)==0)return 1;
	int cnt1=0,cnt2=0,ret=0;
	vector<int> r(21,0), c(21,0);
	vector<int> R(21,0), C(21,0);	
	rep(i,x1,x2+1)rep(j,y1,y2+1){
		if(A[i][j]==1)cnt1++;
		if(A[i][j]==2)cnt2++;
		if(A[i][j]==2)r[i]++,c[j]++;
	}
	if(cnt2==0)return 0;
	if(cnt2==1 && cnt1==0)return 1;
	rep(i,x1,x2+1)rep(j,y1,y2+1){
		if(A[i][j]^1)continue;
		// xline
		if(R[i]==0 && r[i]==0 && prev^1){
			ret+=solve(x1,y1,i-1,y2,1)*solve(i+1,y1,x2,y2,1);
			R[i]=1;
		}
		// yline
		if(C[j]==0 && c[j]==0 && prev^0){
			ret+=solve(x1,y1,x2,j-1,0)*solve(x1,j+1,x2,y2,0);
			C[j]=1;
		}
	}
	return ret;
}

int main(){
	cin>>N;
	rep(i,0,N)rep(j,0,N)cin>>A[i+1][j+1];
	int temp=solve(1,1,N,N,-1);
	cout<<(temp?temp:-1);
}