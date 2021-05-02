#include <iostream>
#define rep(a,b,c) for(ll a=b;a<c;a++)
using namespace std;
const int MAX = 2e4+1;

int N, T, a, b, dist[MAX], par[MAX];
char cmd;

int find(int u){
	if(par[u] == 0) return u;
	int p = find(par[u]);
	dist[u] += dist[par[u]];
	par[u]=p;
	return p;
}
void merge(int u,int v){
	dist[u] = abs(u-v)%1000;
	par[u]=v;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		fill(dist, dist + N + 1, 0);
		fill(par, par + N + 1, 0);
		while((cin >> cmd) && cmd^'O'){
			if(cmd == 'E'){
				cin >> a; find(a);
				cout << dist[a] << '\n';
			}
			else {
				cin >> a >> b;
				merge(a, b);
			}
		}
	}
	return 0;
}