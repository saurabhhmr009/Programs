#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long sum;

void* summation(void *arg) {
    long long *number = (long long*)arg;
    long long i;

    for(i=1; i<=*number; i++) {
        sum += i;
    }
    printf("Sum : %lld\n", sum);
    /* Status could be 0 or NULL */
    pthread_exit(NULL);
}

int main (int argc, char **argv) {
    long long number;
    pthread_t thread_id;
    pthread_attr_t attr;

    printf("++++++++%s\n", argv[0]);

    number = atoll(argv[1]);
    pthread_attr_init(&attr);
    pthread_create(&thread_id, &attr, summation, &number);
    pthread_join(thread_id, NULL);


    return 0;
}