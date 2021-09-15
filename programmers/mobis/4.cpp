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

vector<int> p;
multiset<int> q;
int Max;
void dfs(int pos, int cnt, int sum, vector<int>& we){
    if(Max == cnt){
        auto pos = q.find(sum);
        // cout << sum << endl;
        if(pos != q.end()){
            for(auto i: we){
                if(p[i] == 0) return;
            }
            for(auto i: we) p[i] = 0;
            q.erase(pos);
        }
        return;
    }
    if(pos == p.size()) return;
    auto tmp = p[pos];
    dfs(pos + 1, cnt, sum, we);
    we.pb(pos);
    dfs(pos + 1, cnt + 1, sum + tmp, we);
    we.erase(--we.end());
}
bool solve(vector<int>& pp, vector<int>& qq){
    q.clear();
    swap(p, pp);
    for(auto i: qq) q.insert(i);
    vector<int> we;
    rep(i, 1, p.size() + 1){
        Max = i;
        dfs(0, 0, 0, we);
        // cout << "!";
        // cout << Max << endl;
        // for(auto i: p) cout << i << " ";
        // cout << endl;
    }
    for(auto i: p) if(i) return 0;
    return q.empty();
}
vector<bool> solution(vector<vector<int>> p, vector<vector<int>> q) {
    int N = p.size();
    vector<bool> answer(N);
    rep(i, 0, N){
        answer[i] = solve(p[i], q[i]);
    }
    return answer;
}
int main(){
    vector<vector<int>> p = {{4,3,3},{1,2,3},{3,2,4}};
    vector<vector<int>> q = {{5,5},{5,1},{1,8}};
    for(auto i: solution(p, q)) cout << i << endl;
}