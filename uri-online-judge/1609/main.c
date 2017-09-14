#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

void insertion_sort(int *v, int n, int (*cmp)(const void*, const void*));
int intComparer(const void *a, const void *b);

int main (void) {
    int T, N, n;
    int size;
    int values[MAX_SIZE];

    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &N);

        size = 0;

        while (N-- > 0) {
            scanf("%d", &n);

            if (bsearch(&n, values, size, sizeof(int), intComparer) == NULL) {
                values[size++] = n;
                insertion_sort(values, size, intComparer);
            }
        }

        printf("%d\n", size);
    }
    return EXIT_SUCCESS;
}

void insertion_sort(int *v, int n, int (*cmp)(const void*, const void*)) {
    int i, j, c;

    for (i = 1; i < n; i++) {
        for (j = i; j > 0 && cmp(&v[j - 1], &v[j]) > 0; j--) {
            c = v[j];
            v[j] = v[j - 1];
            v[j - 1] = c;
        }
    }
}

int intComparer(const void *a, const void *b) {
    const int *ibPtr = b;
    const int *iaPtr = a;

    return *iaPtr - *ibPtr;
}
