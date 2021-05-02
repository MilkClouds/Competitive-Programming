#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

int N;
vector<int> pn = {2,3,5,7};
queue<int> Q;

bool isprime(int n){
	rep(i,2,sqrt(n)+1){
		if(n%i == 0 )return 0;
	}
	return 1;
}

int main(){
	cin >> N;
	for(auto i : pn) Q.push(i);
	rep(i,0,N-1){
		int sz = Q.size();
		rep(_, 0, sz){
			int u = Q.front();
			Q.pop();
			rep(p,0,10){
				int v = u * 10 + p;
				if(isprime(v)) Q.push(v);
			}
		}
	}
	while(!Q.empty()){
		cout << Q.front() << "\n";
		Q.pop();
	}
}