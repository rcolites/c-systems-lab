#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global = 10;

int main(void)
{
    int local = 20;
    int *heap = malloc(sizeof(int));

    if (heap == NULL)
        return 1;

    *heap = 30;

    printf("Global: %p\n", (void *)&global);
    printf("Local:  %p\n", (void *)&local);
    printf("Heap:   %p\n", (void *)heap);
    printf("PID:    %ld\n", (long)getpid());

    getchar(); // Keep process alive

    free(heap);
    return 0;
}
