#include <stdio.h>
#include <threads.h>
#include <time.h>

int global_counter = 0;

void increase_counter(void)
{
    static mtx_t mymutex;
    mtx_lock(&mymutex);
    global_counter++;
    mtx_unlock(&mymutex);
}

int func(void * arg)
{
    (void)arg;
    for (int i=0; i<1000000; i++) 
        increase_counter();
    return 0;
}

int main(void)
{
    int n_threads = 10;
    thrd_t threads[n_threads];

    for (size_t i = 0; i < n_threads; i++) {
        if (thrd_create(&threads[i], func, NULL) != thrd_success) {
            perror("Failed to create thread");
            return -1;
        }
    }

    for (size_t i = 0; i < n_threads; i++) {
        if (thrd_join(threads[i], NULL) != thrd_success) {
            perror("Failed to join thread");
            return -1;
        }
    }

    printf("global_counter = %d\n", global_counter);
}
