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

const int MAX = 61;
int N, K, RESULT_DIM, FILTER_DIM, IMG_DIM;
ll A[MAX * 5 * MAX * 5], B[MAX * 2 * MAX * 2], C[MAX * 3 * MAX * 3];
// ll *A = new ll[MAX * 5 * MAX * 5], *B = new ll[MAX * 2 * MAX * 2], *C = new ll[MAX * 3 * MAX * 3];

ll* conv2(ll* a, ll* w, ll* result)
{
    ll acc;
    int i; 
    int j;
    int k1, k2;
    int l1, l2;
    int t1, t2;

    for(i = 0; i < RESULT_DIM; i++) 
    {
        t1 = i * RESULT_DIM; // loop invariants
        for(j = 0; j < RESULT_DIM; j++) 
        {   
            acc = 0.0;
            for(k1 = FILTER_DIM - 1, k2 = 0; k1 >= 0; k1--, k2++)
            {
                t2 = k1 * FILTER_DIM;  // loop invariants
                for(l1 = FILTER_DIM - 1, l2 = 0; l1 >= 0; l1--, l2++)
                {
                    acc += w[t2 + l1] * a[(i + k2) * IMG_DIM + (j + l2)];
                }
            }
            result[t1 + j] = acc;
            //cout << t1 / RESULT_DIM << " " << j << " " << acc << endl;
        }
    }

    return result;
}
void solve(){
    ll ans = 0;
    cin >> N >> K;
    if(N > 50){
        cout << "0\n";
        return;
    }
    IMG_DIM = (2 * K - 1) * 2 + N;
    FILTER_DIM = 2 * K - 1;
    RESULT_DIM = N + 2 * K;
    memset(A, 0, sizeof(ll) * IMG_DIM * IMG_DIM);
    memset(B, 0, sizeof(ll) * FILTER_DIM * FILTER_DIM);
    
    // A = (ll*) calloc(IMG_DIM * IMG_DIM, sizeof(ll));
    // B = (ll*) calloc(FILTER_DIM * FILTER_DIM, sizeof(ll));
    // C = (ll*) calloc(RESULT_DIM * RESULT_DIM, sizeof(ll));

    rep(i, 0, N) rep(j, 0, N) cin >> A[(i + 2 * K - 1) * IMG_DIM + j + 2 * K - 1];
    rep(i, 0, 2 * K - 1) rep(j, 0, 2 * K - 1) {
        B[i * FILTER_DIM + j] = max(0, K - (abs(i - (K - 1)) + abs(j - (K - 1))));
    }
    conv2(A, B, C);
    rep(i, 0, RESULT_DIM) rep(j, 0, RESULT_DIM) ans = max(ans, C[i * RESULT_DIM + j]);
    
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << '\n';
        solve();
    }
}
