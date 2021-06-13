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

int solution(int x, int y){
    int ans = 0, i = 0, j = 0;
    if(y <= 2) return y;
    while(y >= (1 << j + 1) - 1) j++;
    do{i++;} while(x >= (1 << i) - 1);
    if(i - 1 == j) return j + solution(x - (1 << j) + 1, y - (1 << j) + 1);
    ans = max(ans, i - 1 + solution(x - (1 << i - 1) + 1, (1 << i - 1) - 1));
    ans = max(ans, j + solution(0, y - (1 << j) + 1));
    if(i ^ j) ans = max(ans, 1 + j * (j - 1) / 2);
    return ans;
}

int T, x, y;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> x >> y;
        cout << solution(x, y) << "\n";
    }
}
