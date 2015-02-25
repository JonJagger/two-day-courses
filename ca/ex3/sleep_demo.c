#include <threads.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    for (int i=0; i<10; i++) {
        thrd_sleep(&(struct timespec){.tv_sec=1},NULL);
        printf("%d\n", i);
    }
}
