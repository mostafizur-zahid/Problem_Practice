#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int testCase = 0; testCase < t; ++testCase) {
        int n;
        scanf("%d", &n);

        int stores[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &stores[i]);
        }

        qsort(stores, n, sizeof(int), compare);

        int optimalParking = (stores[n - 1] - stores[0]) * 2;
        printf("%d\n", optimalParking);
    }

    return 0;
}
