#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], m, n, i, j, bestIdx;
    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &blockSize[i]);
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &processSize[i]);
    for (i = 0; i < n; i++) {
        bestIdx = -1;
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) blockSize[bestIdx] -= processSize[i];
    }
    return 0;
}