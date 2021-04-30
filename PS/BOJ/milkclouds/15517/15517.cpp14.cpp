#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
const int MAX = 1e6+1;

ll N, B[MAX], tree[MAX];
pair<ll,ll> A[MAX];
void update(int u,int v){
	for(;u<=N;u+=u&-u) tree[u]+=v;
}
int query(int u){
	int ret = 0;
	for(;u;u&=u-1) ret += tree[u];
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i = 0; i< N; i++){
		cin >> A[i].x; A[i].y = i;
	}
	sort(A, A+N);
	for(int i = 0; i < N; i++){
		B[A[i].y] = i + 1;
	}
	for(int i = 0; i < N; i++){
		cout << query(B[i]) << " " ;
		update(B[i], 1);
	}
}