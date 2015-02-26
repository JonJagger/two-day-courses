#include <stdio.h>
#include <threads.h>
#include <time.h>

int global_counter = 0;

mtx_t mymutex;

void increase_counter(void)
{
    mtx_lock(&mymutex);
    global_counter++;
    mtx_unlock(&mymutex);
}

int func(void * arg)
{
    (void)arg;
    for (int i = 0; i < 1000000; i++) 
        increase_counter();
    return 0;
}

int main(void)
{
    int n_threads = 10;
    thrd_t threads[n_threads];

    if (mtx_init(&mymutex, mtx_plain) != thrd_success) {
        perror("Failed to init mutex");
        return -1;
    }
    
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

    mtx_destroy(&mymutex);

    printf("global_counter = %d\n", global_counter);
}
