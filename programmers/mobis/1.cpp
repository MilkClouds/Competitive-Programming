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

set<int> Save;
int dice_rows, dice_cols;
void solve(vector<vector<int>>& dice, int i, string save){
    if(save.size()){
        string tmp = save;
        sort(all(tmp));
        do{
            if(tmp[0] == '0') continue;
            Save.insert(stoi(tmp));
        }while(next_permutation(all(tmp)));
    }
    if(dice_rows == i) return;
    for(int j = 0; j < dice_cols; j++){
        int tmp = dice[i][j];
        save += to_string(tmp);
        solve(dice, i + 1, save);
        save.erase(save.size() - 1);
    }
    solve(dice, i + 1, save);
}

int solution(vector<vector<int>> dice) {
    int answer = 0;
    dice_rows = dice.size();
    dice_cols = dice[0].size();
    solve(dice, 0, "");
    rep(i, 1, 123456) if(Save.count(i) == 0) return i;
    assert(0);
    return -1;
}