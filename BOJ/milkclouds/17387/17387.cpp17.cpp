#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using C = complex<ll>;

int ccw2(C x, C y) {
	ll t = (x * conj(y) * C(0, 1)).real();
	return (t > 0) - (t < 0);
}
inline int ccw3(C x, C y, C z) {
	return ccw2(x - z, y - z);
}
bool comp(C i, C j){
	return i.real() != j.real() ? i.real() > j.real() : i.imag() > j.imag();
}
bool Intersect(C a, C b, C c, C d) {
	int abc = ccw3(a, b, c), abd = ccw3(a, b, d), cda = ccw3(c, d, a), cdb = ccw3(c, d, b);
	if(ccw2(a - b, c - d) == 0){ //평행하거나 같은 직선
		if(abc) return 0; //평행한 직선
		if(comp(a, b)) swap(a, b);
		if(comp(c, d)) swap(c, d);
		return !comp(a, d) && !comp(c, b); //같은 직선
	}
	int S1 = abc * abd, S2 = cda * cdb;
	return S1 <= 0 && S2 <= 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	C P1, P2, P3, P4;
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	P1 = C(a, b); P2 = C(c, d);
	cin >> a >> b >> c >> d;
	P3 = C(a, b); P4 = C(c, d);
	assert(P1 != P2);
	assert(P3 != P4);
	cout << Intersect(P1, P2, P3, P4) << endl;
}