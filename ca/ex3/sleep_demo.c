#include <threads.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        thrd_sleep(&(struct timespec){.tv_sec=1},NULL);
    }
}
