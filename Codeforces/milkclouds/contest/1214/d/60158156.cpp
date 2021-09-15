#include<bits/stdc++.h>
using namespace std;

int dx[]={0,1},dy[]={1,0};
int N,M,cnt[2000005],flag;
vector<vector<int> > chk;
string S[1000005];

void dfs(int x,int y){
	if(chk[x][y]&flag)return;
	chk[x][y]|=flag;
	if(chk[x][y]==3)cnt[x+y]++;
	for(int i=0;i<2;i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0||ny<0||nx>=N||ny>=M)continue;
		if(S[nx][ny]=='#')continue;
		dfs(nx,ny);
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++)chk.push_back(vector<int>(M));
	for(int i=0;i<N;i++)cin>>S[i];
	flag=1;dfs(0,0);
	dx[1]=-1;dy[0]=-1;
	flag=2;dfs(N-1,M-1);
	for(int i=0;i<N+M-1;i++){
		if(i==0||i==N+M-2)continue;
		if(cnt[i]==1){cout<<1;return 0;}
		if(cnt[i]==0){cout<<0;return 0;}
	}
	cout<<2;
}