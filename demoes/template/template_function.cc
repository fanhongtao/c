/**
 * Define a template function
 */
#include <stdio.h>

// implement strcmp-like generic compare function
// returns 0 if the values are equal, 1 if v1 is larger, -1 if v1 is smaller
template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main() {
    int x = 1;
    int y = 2;
    printf("%d compare %d, result: %d\n", x, y, compare(x,y));

    x = 2;
    printf("%d compare %d, result: %d\n", x, y, compare(x,y));

    x = 3;
    printf("%d compare %d, result: %d\n", x, y, compare(x,y));

    return 0;
}
