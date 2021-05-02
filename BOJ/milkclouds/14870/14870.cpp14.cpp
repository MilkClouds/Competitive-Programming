#include <bits/stdc++.h>
using namespace std;
 
typedef long long lld;
 
int N;
int A[1501][1501], D[1501][1501];
int bit[1501][1502];
int S[1501], E[1501];
 
void add(int n, int v, int bit[1502])
{ for (;n<=N;n+=n&(-n)) bit[n] += v; }
int get(int n, int bit[1502])
{ int ret = 0; for (;n;n^=n&(-n)) ret += bit[n]; return ret; }
 
inline int dp(int i, int j){ return D[i][j] + get(j, bit[i]); }
 
int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) scanf("%d", A[i]+j);
    lld ans = 0;
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++){
        D[i][j] = max(D[i-1][j], D[i][j-1]) + A[i][j];
        ans += D[i][j];
    }
    printf("%lld\n", ans);
    for (int t=1;t<=N;t++){
        char c; int y, x; scanf(" %c%d%d", &c, &y, &x);
        int v = c == 'U' ? 1 : -1;
        for (int i=y;i<=N;i++) S[i] = N+1, E[i] = 0;
        S[y] = E[y] = x;
        for (int ny=y,nx=x;;){
            if (nx < N && max(dp(ny-1, nx+1), dp(ny, nx))+v == max(dp(ny-1, nx+1), dp(ny, nx)+v)) nx++;
            else ny++;
            if (ny > N) break;
            E[ny] = nx;
        }
        for (int ny=y,nx=x;;){
            if (ny < N && max(dp(ny+1, nx-1), dp(ny, nx))+v == max(dp(ny+1, nx-1), dp(ny, nx)+v)) ny++;
            else nx++;
            if (nx > N || E[ny] < nx) break;
            S[ny] = min(S[ny], nx);
        }
        for (int i=y;i<=N;i++) if (S[i] <= E[i]){
            add(S[i], v, bit[i]);
            add(E[i]+1, -v, bit[i]);
            ans += v * (E[i]-S[i]+1);
        }
        printf("%lld\n", ans);
    }
}