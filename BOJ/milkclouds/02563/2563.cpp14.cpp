#include <cstdio>
int n, r, x, y, i, j, a[101][101];

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &x, &y);
        for (i = x; i < x + 10; i++) for (j = y; j < y + 10; j++) r += !a[i][j]++;
    }
    printf("%d", r);
    return 0;
}