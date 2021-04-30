#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
const int MAX = 1e5 + 1;

int G, P, x;
set<int> S;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> G >> P;
	rep(i, 0, G) S.insert(i + 1);
	rep(i, 0, P){
		cin >> x;
		auto pos = S.upper_bound(x);
		if(pos == S.begin()) break;
		S.erase(--pos);
	}
	cout << G - S.size();
}