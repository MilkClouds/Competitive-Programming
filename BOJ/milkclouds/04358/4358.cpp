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

const int SZ = 31;
int cnt;
char c[SZ];
map<string, int> M;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    while(cin.getline(c, SZ)){
        M[string(c)]++;
        cnt++;
    }
    for(auto item: M){
        double tmp = 100.0 * item.y / cnt;
        strcpy(c, item.x.c_str());
        printf("%s %.04f\n", c, tmp);
    }
}
