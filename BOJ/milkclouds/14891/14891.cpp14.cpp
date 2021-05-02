#include <stdio.h>
 
int t[6][9];
 
int main() {
 
    int i, j, n, num, dir[6], k, tmp,ans;
 
    for (i = 0; i < 4; i++) 
        for (j = 0; j < 8; j++)
            scanf("%1d", &t[i + 1][j]);
    scanf("%d", &n);
 
    while (n--) {
        for (i = 0; i < 6; i++) dir[i] = 0;
        scanf("%d",&num);
        scanf("%d",&dir[num]);
         
        for (k = num; k > 0; k--) {
            if (t[k - 1][2] != t[k][6] && dir[k] == 1) dir[k - 1] = -1;
            else if (t[k - 1][2] != t[k][6] && dir[k] == -1) { dir[k - 1] = 1;}
        }
        for (k = num; k < 5; k++) {
            if (t[k + 1][6] != t[k][2] && dir[k] == 1) dir[k + 1] = -1;
            else if (t[k + 1][6] != t[k][2] && dir[k] == -1) dir[k + 1] = 1;
        }
        for (i = 0; i < 6; i++) {
            if (dir[i] == -1) {
                tmp = t[i][0];
                for (j = 0; j < 8; j++) {
                    t[i][j] = t[i][j + 1];
                }
                t[i][7] = tmp;
            }
            if (dir[i] == 1) {
                tmp = t[i][7];
                for (j = 8; j > 0; j--) {
                    t[i][j] = t[i][j - 1];
                }
                t[i][0] = tmp;
            }
        }
    }
    ans = t[1][0] + t[2][0] * 2 + t[3][0] * 4 + t[4][0] * 8;
    printf("%d",ans);
    return 0;
}