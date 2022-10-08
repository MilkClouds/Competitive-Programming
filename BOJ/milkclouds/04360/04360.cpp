#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define x first
#define y second
using namespace std;
using pd = pair<double, double>;
using ll = long long;

const int L = 10000;
int N;
double g = 10;
pd r[101];
pd operator + (pd a, pd b){
    return {a.x + b.x, a.y + b.y};
}
pd operator - (pd a, pd b){
    return {a.x - b.x, a.y - b.y};
}
pd operator * (double a, pd b){
    return {a * b.x, a * b.y};
}
pd operator / (pd b, double a){
    return {b.x / a, b.y / a};
}
double norm(pd a){return sqrt(a.x * a.x + a.y * a.y);}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> r[i].x >> r[i].y;
    pd theta = {1, 0};
    rep(_, 0, L){
        pd grad = {0, 0};
        rep(i, 0, N){
            grad = grad + (theta - r[i]) / norm(theta - r[i]);
        }
        theta = theta - g * grad;
        if((_ & (_ - 1)) == 0) g = 10 * cos(3.141592 / 2 / L);
    }
    double ans = 0;
    rep(i, 0, N) ans += norm(theta - r[i]);
    cout << round(ans) << endl;
}
