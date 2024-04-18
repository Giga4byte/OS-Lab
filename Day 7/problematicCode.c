/* safe state sheri ayi, unsafe state sheri ayit illa. So don't blindly copy - esp batch 2, she'll ask about it */
#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter the number of processes and resources: ");
    scanf("%d%d", &n, &m);

    // Allocation Matrix
    int alloc[n][m];
    printf("\nEnter the Allocation Matrix [%d][%d]:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Max Matrix
    int max[n][m];
    printf("\nEnter the Max Matrix [%d][%d]:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Available Resources
    int available[m];
    printf("\nEnter the Available Resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    // Need Matrix
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Safety Algorithm
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (j = 0; j < m; j++) {
                        available[j] += alloc[i][j];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    // Safety Check
    int safe = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            safe = 0;
            printf("The system is not in a safe state.\n");
            break;
        }
    }

    if (safe) {
        printf("Following is the SAFE Sequence:\n");
        for (i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d\n", ans[n - 1]);
    }

    return 0;
}
