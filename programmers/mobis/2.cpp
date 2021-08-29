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

bool solve(string& S){
    vector<int> pSum(S.size() + 10);
    rep(i, 0, S.size()) pSum[i + 1] += pSum[i] + (S[i] == 'a');
    int s = 0, e = S.size() - 1;
    while(pSum[e + 1] - pSum[s]){
        while(s < e && S[s] == 'a') s++;
        while(s < e && S[e] == 'a') e--;
        if(s == e) return S[s] == 'a';
        rep(i, 0, pSum[e + 1] - pSum[s]){
            if(S[s] != 'b') return 0;
            if(S[e] != 'b') return 0;
            s++; e--;
        }
    }
    return pSum[e + 1] - pSum[s] == 1;
}
vector<bool> solution(vector<string> a) {
    vector<bool> answer(a.size());
    int i = 0;
    for(auto S: a){
        answer[i++] = solve(S);
    }
    return answer;
}

int main(){
    vector<string> a = {"abab","bbaa","bababa","bbbabababbbaa"};
    for(auto i: solution(a)) cout << i << endl;
}