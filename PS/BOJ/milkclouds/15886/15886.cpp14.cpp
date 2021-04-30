#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

bool visit[1005], finished[1005];
int N, cnt;
string S;
queue<int> Q;

bool dfs(int u){
	if(finished[u]) return 0;
	if(visit[u]) return 1;
	Q.push(u);
	visit[u] = 1;
	bool ret = 0;
	if(S[u] == 'E') ret |= dfs(u + 1);
	else ret |= dfs(u - 1);
	return ret;
}
int main(){
	cin >> N >> S;
	rep(i,0,N){
		if(finished[i])continue;
		cnt += dfs(i);
		while(!Q.empty()){
			finished[Q.front()] = 1;
			Q.pop();
		}
	}
	cout << cnt;
}