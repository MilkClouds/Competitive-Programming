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
const int MAX=2e5, MAXS=390;

int N, L, M, P[MAX], X[MAX], i, y, SZ, G, update_count;

static struct GROUP{
	int arr[MAXS*2],count[MAXS*2],last[MAXS*2],size;
	void set(){
		int i, k = size;
		for(i = size; i; i--){
			while(k > i && arr[k-1]-arr[i] > L) k--;
			if(arr[size]-arr[i] <= L) count[i] = 1, last[i] = arr[i] + L;
			else count[i] = count[k] + 1, last[i]=last[k];
		}
	}
} groups[MAXS];

void all_set(){
	int N = 0, i, j;
	// groups의 원소들을 X로 옮김
	for(i = 1; i <= G; i++){
		for(j = 1; j <= groups[i].size; j++) X[++N] = groups[i].arr[j];
		groups[i].size = 0;
	}
	// groups 갱신
	G = 1;
	for(i = 1; i <= N; i++){
		if(groups[G].size == SZ) G++;
		groups[G].arr[++groups[G].size] = X[i];
	}
	// groups set
	for(i = 1; i<= G; i++) groups[i].set();
	update_count = 0;
}

int get_answer(){
	int i, ans = groups[1].count[1], last = groups[1].last[1];
	int s, e, m, t;
	// O(sqrt(N) logsqrt(N))
	for(i = 2; i <= G; i++){
		if(groups[i].arr[groups[i].size] <= last)continue;
		s = 1, e = groups[i].size;
		while(s <= e){
			m = s + e >> 1;
			if(groups[i].arr[m] > last) e = m - 1, t=m;
			else s = m + 1;
		}
		ans += groups[i].count[t];
		last = groups[i].last[t];
	}
	return ans;
}

int del(int p){
	int i, t;
	// O(sqrtN)
	for(t = 1; t < G; t++) if(groups[t].arr[1] <= p && groups[t+1].arr[1] > p)break;
	// O(sqrtN)
	for(i = 1;i <= groups[t].size; i++){
		if(groups[t].arr[i] == p){
			for(; i < groups[t].size; i++) groups[t].arr[i] = groups[t].arr[i + 1];
			groups[t].size--;
			break;
		}
	}
	groups[t].set();
	return groups[t].size;
}
void add(int p){
	int i, t, x;
	for(t = 1; t < G; t++) if(groups[t].arr[groups[t].size] > p)break;
	for(x = 1; x <= groups[t].size; x++) if(groups[t].arr[x] > p) break;
	for(i = groups[t].size; i >= x; i--)groups[t].arr[i+1] = groups[t].arr[i];
	groups[t].arr[x] = p;
	groups[t].size++;
	groups[t].set();
}

int update(int i,int y){
	if(++update_count == SZ) all_set();
	if(!del(P[i])) all_set();
	add(P[i] = y);
	return get_answer();
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> L >> M;
	SZ = sqrt(N); G = 1;
	rep(i, 0, N){
		cin >> X[i];
		P[i] = X[i];
		if(groups[G].size == SZ) G++;
		groups[G].arr[++groups[G].size] = X[i];
	}
	rep(i, 0, G) groups[i+1].set();
	rep(_, 0, M){
		cin >> i >> y;
		cout << update(i, y) << "\n";
	}
}