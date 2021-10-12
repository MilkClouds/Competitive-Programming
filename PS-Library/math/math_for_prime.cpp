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
// version 2 _ for decomposition
const ll MAX = 3e6;
vector<ll> pn;
ll arr[MAX];

void eratos() {
	for (ll i = 2; i < MAX; i++) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i; j < MAX; j += i) arr[j] = i;
	}
}

vector<ll> divisors(ll n){
    vector<ll> div;
    rep(p, 1, (ll)sqrt(n) + 1) if(n % p == 0){
        div.eb(p);
        if(p != n / p) div.eb(n / p);
    }
    sort(all(div));
    return div;
}

ll gcd(ll x, ll y){
    if(x % y == 0) return y;
    return gcd(y, x % y);
}

ll exEuclid(ll a, ll b, ll &s, ll &t) {
    if (b == 0) { s = 1; t = 0; return a; }
    ll gcd = exEuclid(b, a % b, s, t);
    ll tmp = t;
    t = s - (a / b)*t;
    s = tmp; if (s <= 0) { s += b; t -= a; }
    return gcd;
}

ll euler_phi(ll x){
    ll ret = x;
    for(auto p: pn) {
        if(p * p > x) break;
        if(x % p == 0){
            while(x % p == 0) x /= p;
            ret -= ret / p;
        }
    }
    if(x != 1) ret -= ret / x;
    return ret;
}

// w/i pn vector
ll euler_phi(ll x){
    ll ret = x;
    for(ll p = 2; p * p <= x; p++) if(x % p == 0){
        while(x % p == 0) x /= p;
        ret -= ret / p;
    }
    if(x != 1) ret -= ret / x;
    return ret;
}

long long pow(long long a, long long b) {
	long long ret = 1;
	while (b) {
	if (b & 1) ret *= a;
		a *= a;
		a %= MOD;
		ret %= MOD;
		b >>= 1;
	}
	return ret;
}