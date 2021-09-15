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

string A, B, C;
int c_to_i[26], cnt, p[10];
set<char> S;
bool solvable(){
    ll a = 0, b = 0, c = 0;
    for(auto i: A){
        a = a * 10 + p[c_to_i[i - 'A']];
    }
    for(auto i: B){
        b = b * 10 + p[c_to_i[i - 'A']];
    }
    for(auto i: C){
        c = c * 10 + p[c_to_i[i - 'A']];
    }
    return a + b == c;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> A >> B >> C;
    for(auto i: A) S.insert(i);
    for(auto i: B) S.insert(i);
    for(auto i: C) S.insert(i);
    if(S.size() > 10){
        cout << "NO\n";
        return 0;
    }
    for(auto i: S){
        c_to_i[i - 'A'] = cnt;
        cnt++;
    }
    rep(i, 0, 10) p[i] = i;
    do{
        if(solvable()){
            cout << "YES\n"; 
            return 0;
        }
    } while(next_permutation(p, p + 10));
    cout << "NO\n";
}
