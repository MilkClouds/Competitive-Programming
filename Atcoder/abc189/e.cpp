# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

const int MAX = 2e5;
ll N, M, Q, X[MAX], Y[MAX], c, p;
struct AB{
    ll x, y;
    AB(): AB(0, 0){}
    AB(ll x, ll y): x(x), y(y){}
    AB minus(){
        return AB(-x, -y);
    }
    AB sym(ll p){
        return AB(-x, 2 * p - y);
    }
    ll eval(ll a){
        return a * x + y;
    }
} op_x[MAX + 1], op_y[MAX + 1];
int rev[MAX + 1], a, b;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> X[i] >> Y[i];
    cin >> M;
    op_x[0] = {1, 0};
    op_y[0] = {1, 0};
    rep(i, 0, M){
        cin >> c;
        rev[i + 1] = rev[i] ^ (c <= 2);
        if(c == 1){
            op_x[i + 1] = op_y[i];
            op_y[i + 1] = op_x[i].minus();
        }
        else if(c == 2){
            op_x[i + 1] = op_y[i].minus();
            op_y[i + 1] = op_x[i];
        }
        else {
            cin >> p;
            if(c & 1){
                op_x[i + 1] = op_x[i].sym(p);
                op_y[i + 1] = op_y[i];
            } else {
                op_x[i + 1] = op_x[i];
                op_y[i + 1] = op_y[i].sym(p);
            }
        }
    }
    cin >> Q;
    while(Q--){
        cin >> a >> b;
        if(rev[a]){
            cout << op_x[a].eval(Y[b - 1]) << " " << op_y[a].eval(X[b - 1]) << "\n";
        } else cout << op_x[a].eval(X[b - 1]) << " " << op_y[a].eval(Y[b - 1]) << "\n";
    }
}
