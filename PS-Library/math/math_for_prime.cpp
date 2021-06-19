vector<ll> pn;
bool arr[MAX];

void eratos() {
	pn.push_back(2);
	for (ll i = 3; i < MAX; i += 2) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i * i; j < MAX; j += i) arr[j] = 1;
	}
}
// #####################################################################
// version 2
void eratos() {
	for (ll i = 2; i < MAX; i++) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i; j < MAX; j += i) arr[j] = i;
	}
}

ll gcd(ll x, ll y){
    if(x % y == 0) return y;
    return gcd(x, y % x);
}

ll euler_phi(ll x){
    ll ret = 1;
    for(auto p: pn){
        ll tmp = 1;
        while(x % p == 0){
            x /= p;
            tmp *= p;
        }
        if(tmp > 1){
            ret *= tmp - tmp / p;
        }
    }
    if(x != 1) ret *= x - 1;
    return ret;
}