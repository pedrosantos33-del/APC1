#include <stdio.h>
int main () {
    int x = 5;
    int y = x++;
    int z = ++x;
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}