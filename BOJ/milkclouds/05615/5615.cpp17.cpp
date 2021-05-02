#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
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

vector<ull> alist = { 2, 7, 61 };

// calculate x^y % m
ull powmod(ull x, ull y, ull m) {
    x %= m;
    ull r = 1ULL;
    while (y > 0) {
        if (y % 2 == 1)
            r = (r * x) % m;
        x = (x * x) % m;
        y /= 2;
    }
    return r;
}

// true for probable prime, false for composite
inline bool miller_rabin(ull n, ull a) {
    ull d = n - 1;
    while (d % 2 == 0) {
        if (powmod(a, d, n) == n - 1)
            return true;
        d /= 2;
    }
    ull tmp = powmod(a, d, n);
    return tmp == n - 1 || tmp == 1;
}

bool is_prime(ull n) {
    if (n <= 1)
        return false;
    if (n <= 10000ULL) {
        for (ull i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    for (ull a : alist)
        if (!miller_rabin(n, a))
            return false;
    return true;
}

ll N, a, ans;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    while (N--) {
        cin >> a;
        ans += is_prime(2 * a + 1);
    }
    cout << ans;
}