# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;

int BFS(int n){
	queue<pi> Q;
	vector<bool> visit(1234567);
	Q.push({1%n,1}); visit[1]=1;
	while(!Q.empty()){
		int u = Q.front().x, depth = Q.front().y;
		if(u == 0)return depth;
		Q.pop();
		int v = (u * 10 + 1) % n;
		if(visit[v])continue;
		visit[v]=1; Q.push({v, depth + 1});
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	cout << BFS(n);
}