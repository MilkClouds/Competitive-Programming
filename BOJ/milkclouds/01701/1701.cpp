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
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

string S;
int ret;
struct fake{
    int l, r;
    int size(){
        return r - l;
    }
    char operator [](int i){
        return S[l + i];
    }
};
vector<int> getPi(fake p){
    int m = (int)p.size(), j=0;
    vector<int> pi(m, 0);
    for(int i = 1; i< m ; i++){
        while(j > 0 && p[i] !=  p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}
void kmp(string s, fake p){
    auto&& pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j =0;
    for(int i = p.l + 1; i < n ; i++){
        while(j>0 && s[i] != p[j])
            j = pi[j-1];
        if(s[i] == p[j]){
            if(j==m-1){
                j = pi[j];
            }else{
                j++;
            }
        }
        ret = max(ret, j);
    }
}
vector<vector<int>> save;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> S;
    rep(i, 0, S.size()){
        kmp(S, {i, (int)S.size()});
    }
    cout << ret << endl;
}
