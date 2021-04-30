#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(int a=b;a>c;a--)
using namespace std;
using ll = long long;
const int MAX = 1e5 + 5;

int N, B, A[MAX], pivot, G, g;
map<int,int> left_map, right_map;
ll ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> B;
	rep(i,0,N) { cin >> A[i]; if(A[i] == B) pivot = i;}
	rep2(i,pivot-1,-1){
		if(A[i] < B) g++;
		else G++;
		left_map[G-g]++;
	}
	G = g = 0;
	rep(i,pivot+1,N){
		if(A[i] < B) g++;
		else G++;
		right_map[g-G]++;
	}
	left_map[0]++; right_map[0]++;
	for(auto [i,j] : left_map){
		ans += right_map[i]*j;
	}
	cout << ans;
}