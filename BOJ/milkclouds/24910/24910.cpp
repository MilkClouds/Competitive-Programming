#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

int N, K, a[11];
map<string, vector<int>> P[11];
__int128 t = 1;
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
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    if(N == 1){
        rep(i, 0, 11) cout << "0\n";
        return 0;
    }
    rep(i, 0, 10) t *= N;
    while(K--){
        rep(i, 0, 11) cin >> a[i];
        rep(i, 0, 11){
            string S;
            rep(j, 0, 11) if(i ^ j) S += "|" + to_string(a[j]);
            if(P[i].find(S) == P[i].end()) P[i][S] = vector<int>{0, N + 1};
            P[i][S].pb(a[i]);
        }
    }
    rep(i, 0, 11){
        int cnt = -P[i].size();
        for(auto& [k, v]: P[i]){
            sort(all(v));
            rep(j, 0, v.size() - 1) cnt += (v[j + 1] - v[j] >= 3);
        }
        cout << t + cnt << "\n";
    }
}
