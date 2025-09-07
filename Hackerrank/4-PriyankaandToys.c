#include <stdio.h>
#include <stdlib.h> // For qsort
#include <limits.h> // For INT_MAX (though not strictly necessary here)

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int toys(int w_count, int* w) {
    if (w_count == 0) {
        return 0; // No toys, no containers needed
    }

    qsort(w, w_count, sizeof(int), compare);

    int containers = 1;
    int current_container_min_weight = w[0];

    for (int i = 1; i < w_count; i++) {
        if (w[i] > current_container_min_weight + 4) {
            // Current toy cannot fit in the current container, start a new one
            containers++;
            current_container_min_weight = w[i];
        }
    }

    return containers;
}

int main() {
    int n;
    scanf("%d", &n);

    int *w = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    int result = toys(n, w);
    printf("%d\n", result);

    free(w); // Free allocated memory
    return 0;
}
