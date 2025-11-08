#include <stdio.h>

int main() {
    int n, m, i, j, k;
    scanf("%d%d", &n, &m);
    int alloc[n][m], max[n][m], avail[m], f[n], ans[n], ind = 0;
    for (i = 0; i < n; i++) f[i] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    for (i = 0; i < m; i++) scanf("%d", &avail[i]);
    int need[n][m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    for (j = 0; j < m; j++) avail[j] += alloc[i][j];
                    ans[ind++] = i;
                    f[i] = 1;
                }
            }
        }
    }
    return 0;
}