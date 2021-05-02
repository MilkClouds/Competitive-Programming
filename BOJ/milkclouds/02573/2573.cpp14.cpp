#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
 
// tot == 빙산 높이의 합
int n, m, tot;
int map[303][303], visited[303][303];
vector<pair<int, int>> ice;
// 1년마다 각 빙산이 얼마나 낮아지는지를 저장
// 1년(루프1 회)마다 초기화
int temp[10001];
 
// 4방 탐색
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
 
// 빙산에 접한 0의 개수를 세는 함수
int sea_cnt(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (map[nx][ny] == 0) cnt++;
    }
    return cnt;
}
 
// 빙산의 덩어리를 세기 위한 dfs
void dfs(int x, int y) {
 
    visited[x][y] = 1;
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!map[nx][ny] || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}
 
int main() {
 
    scanf("%d %d", &n, &m);
 
    int num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num);
            if (num) {
                tot += num;
                map[i][j] = num;
                // 빙산이 있는 지점을 저장해준다
                ice.push_back({ i,j });
            }
        }
    }
 
    int flag = 0, res = 0;
    // 모든 빙산이 녹으면 멈춘다
    while (tot) {
 
        memset(temp, 0, sizeof(temp));
 
        int hx, hy;
        for (int i = 0; i < ice.size(); i++) {
            hx = ice[i].first;
            hy = ice[i].second;
 
            if (map[hx][hy])
                temp[i] = sea_cnt(hx, hy);
        }
 
        int tmp;
        for (int i = 0; i < ice.size(); i++) {
            hx = ice[i].first;
            hy = ice[i].second;
 
            if (!temp[i]) continue;
 
            if (map[hx][hy]) {
                tmp = map[hx][hy] < temp[i] ? map[hx][hy] : temp[i];
                tot -= tmp;
                map[hx][hy] -= tmp;
            }
        }
 
        memset(visited, 0, sizeof(visited));
 
        // 빙산 덩어리의 수를 센다
        int ices = 0;
        for (int i = 0; i < ice.size(); i++) {
            hx = ice[i].first;
            hy = ice[i].second;
            if (map[hx][hy] == 0) continue;
            if (!visited[hx][hy]) {
                dfs(hx, hy);
                ices++;
            }
            if (ices >= 2) {
                flag = 1;
                break;
            }
        }
        res++;
        if (flag)
            break;
    }
 
    if (flag)
        printf("%d\n", res);
    else
        puts("0");
}




















//


