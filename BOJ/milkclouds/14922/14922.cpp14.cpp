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
const ll INF = 3e9, MOD = 1e9 + 7, MAX = 1e6;

ll N, m_i = MAX;
double A[MAX], m_v = INF, eps = 1e-7;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N)cin >> A[i];
	rep(i, 0, N - 1){
		double t = (A[i] + A[i + 1]) / 2;
		if(m_v > t){
			m_v = t; m_i = i;
		}
	}
	rep(i, 0, N - 2){
		double t = (A[i] + A[i + 1] + A[i + 2]) / 3;
		if (abs(m_v - t) < eps) m_i = min(m_i, i);
		else if(m_v > t){
			m_v = t; m_i = i;
		}
	}
	cout << m_i << endl;
}
	