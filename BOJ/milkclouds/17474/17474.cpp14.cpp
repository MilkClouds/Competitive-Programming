# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
using namespace std;
using ll=long long;
const ll MAX=1e6+2000;
ll N,A[MAX],M,op,L,R,X;

struct Node{
	ll M, M2, cnt, sum;
	Node():Node(0, 0, 0, 0){}
	Node(ll M, ll M2, ll cnt, ll sum):M(M), M2(M2), cnt(cnt), sum(sum){}
} tree[MAX*4];

Node f(Node a, Node b){
	if(a.M == b.M)return {a.M, max(a.M2, b.M2), a.cnt + b.cnt, a.sum + b.sum};
	if(a.M > b.M)swap(a,b);
	return {b.M, max(a.M, b.M2), b.cnt, a.sum + b.sum};
}

Node init(int node, int s, int e){
	if(s == e)return tree[node]=Node(A[s], -1, 1, A[s]);
	int m = s + e >> 1;
	return tree[node]=f(init(node*2,s,m), init(node*2+1,m+1,e));
}

void push(int node, int s, int e){
	if(s == e)return;
	for(auto i: {node*2, node*2+1}){
		if(tree[node].M < tree[i].M){
			tree[i].sum += tree[i].cnt * (tree[node].M - tree[i].M);
			tree[i].M = tree[node].M;
		}
	}
}

void update(int node, int s, int e, int l, int r, ll v){
    push(node, s, e);
    if(r < s || e < l || tree[node].M <= v) return;
    if(l <= s && e <= r && tree[node].M2 < v){
    	tree[node].sum += tree[node].cnt * ( v - tree[node].M );
        tree[node].M = v;
        push(node, s, e);
        return;
    }
    int m = s + e >> 1;
    update(node*2, s, m, l, r, v);
    update(node*2+1, m+1, e, l, r, v);
    tree[node] = f(tree[node*2], tree[node*2+1]);
}

ll getmax(int node, int s, int e, int l, int r){
	push(node, s, e);
	if(r < s || e < l)return 0;
	if(l <= s && e <= r)return tree[node].M;
	int m = s + e >> 1;
	return max(getmax(node*2,s,m,l,r), getmax(node*2+1,m+1,e,l,r));
}
ll getsum(int node,int s,int e,int l,int r){
	push(node, s, e);
	if(r < s || e < l)return 0;
	if(l <= s && e <= r)return tree[node].sum;
	int m = s + e >> 1;
	return getsum(node*2,s,m,l,r) + getsum(node*2+1,m+1,e,l,r);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	rep(i,1,N+1)cin>>A[i];
	init(1,1,N);
	cin>>M;
	while(M--){
		cin>>op>>L>>R;
		if(op==1){
			cin>>X;
			update(1,1,N,L,R,X);
		}
		else if (op==2){
			cout<<getmax(1,1,N,L,R)<<"\n";
		}
		else cout<<getsum(1,1,N,L,R)<<"\n";
	}
}