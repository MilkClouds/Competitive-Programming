#include <iostream>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
const int MAX = 2e5+1;

int N, M, par[MAX][20],Q,n,x;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	rep(i,0,N)cin>>par[i+1][0];
	rep(k,1,19){
		rep(i,1,N+1){
			par[i][k] = par[par[i][k-1]][k-1];
		}
	}
	cin >> Q;
	while(Q--){
		cin >> n >> x;
		rep(i,0,19){
			if(n&(1<<i)){
				x = par[x][i];
			}
		}
		cout << x << '\n';
	}
}