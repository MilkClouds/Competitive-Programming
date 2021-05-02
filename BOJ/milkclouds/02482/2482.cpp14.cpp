#include <cstdio>
const int div = 1000000003;
int dp[1001][1001];
int main() { int N, K;
 scanf("%d %d", &N, &K);
 for (int i = 1; i <= N; ++i) dp[i][0] = 1;
 for (int i = 1; i <= N; ++i) dp[i][1] = i;
 for (int i = 2; i <= N; ++i) { for (int j = 2; j <= N; ++j) { dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % div; } } printf("%d\n", (dp[N - 3][K - 1] + dp[N - 1][K]) % div); return 0; }

