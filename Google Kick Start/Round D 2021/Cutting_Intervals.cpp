# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5 + 10;
int TC, N;
ll C;
pl A[MAX];
priority_queue<pl> events;
std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
__int128 solve(){
    __int128 ans = 0;
    cin >> N >> C;
    rep(i, 0, N) cin >> A[i].x >> A[i].y;
    rep(i, 0, N){
        events.emplace(-A[i].x, 1);
        events.emplace(-A[i].y + 1, -1);
    }
    ll S = 0, prev = 0;
    priority_queue<pair<ll, pl>> KK;
    while(!events.empty()){
        ll pos, d;
        tie(pos, d) = events.top(); events.pop();
        KK.emplace(S, pl(-prev, -pos));
        S += d;
        prev = pos;
    }
    while(!KK.empty()){
        ll S;
        pl p;
        tie(S, p) = KK.top(); KK.pop();
        //cout << p.x << " " << p.y << " " << S << endl;
        ans += (__int128)min(p.y - p.x, C) * S;
        C -= min(p.y - p.x, C);
        if(C == 0) break;
    }
    return ans + N;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": " << solve() << "\n";
    }
}
