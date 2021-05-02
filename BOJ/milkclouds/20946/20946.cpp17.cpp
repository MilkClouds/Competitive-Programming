#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

using ull = unsigned long long;

vector<ull> alist = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

// calculate (x + y) % m; overflow-safe
inline ull addmod(ull x, ull y, ull m) {
    x %= m;
    y %= m;
    return (x >= m - y? x - (m - y) : x + y);
}

// calculate (x * y) % m; overlow-safe
inline ull mulmod(ull x, ull y, ull m) {
    x %= m;
    y %= m;
    ull r = 0;
    while (y > 0) {
        if (y % 2 == 1)
            r = addmod(r, x, m);
        x = addmod(x, x, m);
        y /= 2;
    }
    return r;
}

// calculate x^y % m; overflow-safe
ull powmod(ull x, ull y, ull m) {
    x %= m;
    ull r = 1ULL;
    while (y > 0) {
        if (y % 2 == 1)
            r = mulmod(r, x, m);
        x = mulmod(x, x, m);
        y /= 2;
    }
    return r;
}

// true for probable prime, false for composite
inline bool miller_rabin(ull n, ull a) {
    ull d = n - 1;
    while (d % 2 == 0) {
        if (powmod(a, d, n) == n-1)
            return true;
        d /= 2;
    }
    ull tmp = powmod(a, d, n);
    return tmp == n-1 || tmp == 1;
}

bool is_prime(ull n) {
    if (n <= 1)
        return false;
    if (n <= 1000000ULL) {
        for (ull i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    for (ull a : alist)
        if (!miller_rabin(n, a))
            return false;
    return true;
}




const int MAX = 1e6 + 1;
vector<ll> pn, hap, ans;
ll N, u = 1, v, flag;
map<ll, ll> vis;
map<ll, bool> isP;
bool arr[MAX];
ll arr2[MAX];

void eratos() {
	pn.push_back(2);
	for (ll i = 3; i < MAX; i += 2) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i * i; j < MAX; j += i) arr[j] = 1;
	}
    fill(arr, arr + MAX, 0);
    for(auto p: pn) arr[p] = 1; //prime
    for(ll i = 4; i < MAX; i++){
        if(arr2[i] || arr[i]) continue;
        hap.pb(i);
        for(ll j = 1; i * j < MAX; j++){
            if(!arr[j] && !arr2[i * j]) arr2[i * j] = i;
        }
    }
}
bool isPrime(ll u){
    if(isP.find(u) != isP.end()) return isP[u];
    if(u < MAX) return arr[u];
    else {
        flag = 0;
        for(auto p: pn) if(u % p == 0) flag = 1;
        if(!flag) isP[u] = 1;
        else isP[u] = 0;
    }
    return isP[u];
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    eratos();
    if(isPrime(N)) {cout << -1; return 0;}
    while(N > 1){
        if(isPrime(N)) {cout << -1; return 0;}
        if(N < MAX){
            ans.pb(arr2[N]);
            N /= arr2[N];
        } else {
            int flag = 0;
            for(auto i: hap){
                v = N / i;
                if(N % i || isPrime(v)) continue;
                ans.pb(i);
                N = v;
                flag = 1;
                break;
            }
            if(!flag) {
                ans.pb(N);
                N = 1;
            }
        }
    }
    sort(all(ans));
    for(auto i: ans) cout << i << " " ;
}
