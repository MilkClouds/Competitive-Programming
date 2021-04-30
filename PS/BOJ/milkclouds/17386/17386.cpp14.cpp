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

using C = complex<ll>;

ll ccw2(C x, C y){
	return (x * conj(y) * C(0, 1)).real();
}
ll ccw3(C x, C y, C z){
	ll t = ccw2(x - z, y - z);
	return (t > 0) - (t < 0);
}
bool Intersect(C a, C b, C c, C d){
	ll abc = ccw3(a, b, c), abd = ccw3(a, b, d), cda = ccw3(c, d, a), cdb = ccw3(c, d, b);
	if(abc * abd == 0 && cda * cdb == 0){
		if(a.real() > b.real()) swap(a, b);
		if(c.real() > d.real()) swap(c, d);
		return a.real() <= d.real() && c.real() <= b.real();
	}
	return abc * abd <= 0 && cda * cdb <= 0;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	C P1, P2, P3, P4;
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	P1 = C(a, b); P2 = C(c, d);
	cin >> a >> b >> c >> d;
	P3 = C(a, b); P4 = C(c, d);

	cout << Intersect(P1, P2, P3, P4);
}