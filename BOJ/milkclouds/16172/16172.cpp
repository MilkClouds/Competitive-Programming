#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

string A, B, C;
vector<int> getPi(string p){
    int m = p.size(), j = 0;
    vector<int> pi(m, 0);
    for(int i = 1; i < m; i++){
        while(j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}
bool kmp(string s, string p){
    vector<int> ans;
    auto&& pi = getPi(p);
    int n = s.size(), m = p.size(), j = 0;
    for(int i = 0; i < n; i++){
        while(j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if(s[i] == p[j]){
            if(j == m - 1){
                ans.push_back(i - m + 1);
                return 1;
                j = pi[j];
            }else{
                j++;
            }
        }
    }
    return 0;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> A >> B;
    for(auto i: A) if(i > '9') C += i;
    cout << kmp(C, B) << endl;
}
