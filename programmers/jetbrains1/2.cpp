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

const array<pi, 4> actions = {pi(1, 0), pi(0, 1), pi(0, -1), pi(-1, 0)};
int cnt;
bool vis[501][501][3][3];
void dfs(vector<string>& grid, int x, int y, int dx, int dy){
    if(x < 0) x += grid.size();
    if(x >= grid.size()) x -= grid.size();
    if(y < 0) y += grid[0].size();
    if(y >= grid[0].size()) y -= grid[0].size();
    
    if(vis[x][y][dx + 1][dy + 1]) return;
    vis[x][y][dx + 1][dy + 1] = 1; cnt++;
    int ndx = dx, ndy = dy;
    if(grid[x][y] == 'L') ndx = -dy, ndy = dx;
    else if(grid[x][y] == 'R') ndx = dy, ndy = -dx;
    dx = ndx; dy = ndy;
    dfs(grid, x + dx, y + dy, dx, dy);
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    rep(i, 0, grid.size()) rep(j, 0, grid[0].size()){
        for(auto [dx, dy]: actions){
            cnt = 0;
            dfs(grid, i, j, dx, dy);
            if(cnt) answer.emplace_back(cnt);
        }
    }
    sort(all(answer));
    return answer;
}