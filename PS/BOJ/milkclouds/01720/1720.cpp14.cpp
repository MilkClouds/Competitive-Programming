# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;

int N, A[31] = {1, 1}, B[31] = {1, 1, 3, 1};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 2, N + 1) A[i] = A[i - 1] + A[i - 2] * 2;
	rep(i, 4, N + 1) B[i] = B[i - 2] + B[i - 4] * 2;
	cout << (A[N] + B[N]) / 2;
}