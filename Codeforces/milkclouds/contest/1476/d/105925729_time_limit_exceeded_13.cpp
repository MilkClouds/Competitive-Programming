#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >= b; a--)
#define pb push_back
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 3e5 + 3;

string s;
int n;

int BFS(int b){
	int cnt = 0;
	vector<bool> vis(n + 1, 0);
	queue<int> Q;
	Q.push(b); vis[b] = 1; cnt++;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		if(( (s[u] == 'R') ^ ((u - b+2000000) % 2) ) && u<n && !vis[u+1]){
			vis[u + 1] = 1;
			Q.push(u + 1); cnt++;
		}
		if(u > 0 && ( (s[u - 1] == 'L') ^ ((u - b+2000000) % 2) ) && !vis[u-1]){
			vis[u - 1] = 1;
			Q.push(u - 1); cnt++;
		}
	}
	return cnt;
}


void solve(){
	cin >> n >> s;
	rep(i, 0, n + 1) cout << BFS(i) << " " ;
	cout << "\n";
}

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	int TC;
	cin >> TC;
	while(TC--){
		solve();
	}	
}