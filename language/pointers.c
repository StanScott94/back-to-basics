#include <stdio.h>

void increment(int *pointer) {
    (*pointer)++;
}

int main(void) {
    int x = 10;
    int *y = &x;
    int **z = &y;
    
    printf("value of int x = %d\n", x);
    printf("address of int x = %p\n", (void *)&x);
    printf("value of pointer y = %p\n", (void *)y);
    printf("address of pointer y = %p\n", (void *)&y);
    printf("dereferenced pointer y = %d\n", *y);
    printf("value of pointer to pointer z = %p\n", (void *)z);
    printf("address of pointer to pointer z = %p\n", (void *)&z);
    printf("dereferenced pointer z = %p\n", (void *)*z);
    printf("dereferenced pointer to pointer z = %d\n", **z);
    increment(y);
    printf("increment pointer y = %d\n", *y);
}
