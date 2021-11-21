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

const int MAX = 2e5;
ll N, A[MAX], ans;
struct ABC{
    ll a, b;
    ABC(): ABC(0, 0){}
    ABC(ll a, ll b): a(a), b(b){}
    ABC operator + (ABC o){
        return ABC(a + o.a, b + o.b);
    }
    ABC operator - (ABC o){
        return ABC(a - o.a, b - o.b);
    }
    ABC operator * (ll o){
        return ABC(a * o, b * o);
    }
} save[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N);
    if(accumulate(A, A + N, 0)){
        cout << "-1";
        return 0;
    }
    save[1] = ABC(1, 0);
    save[2] = ABC(2, A[2]);
    rep(i, 3, N + 2){
        save[i % N] = save[(i - 1) % N] * 2 - save[(i - 2) % N] + ABC(0, A[i % N]);
    }
    if(save[1].a == 1 || save[1].b % (save[1].a - 1) != 0){
        cout << -1;
        return 0;
    }
    ll x = -save[1].b / (save[1].a - 1);
    ll M = 1e18;
    rep(i, 1, N){
        ans += save[i].a * x + save[i].b;
        M = min(M, save[i].a * x + save[i].b);
    }
    if(M < 0) cout << ans + N * (-M) << endl;
    else cout << ans - M * (N - 2) << endl;
}
