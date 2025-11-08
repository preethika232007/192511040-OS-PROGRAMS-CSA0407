#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], m, n, i, j;
    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &blockSize[i]);
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &processSize[i]);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    return 0;
}