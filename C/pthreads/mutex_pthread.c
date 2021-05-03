#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_LOOPS 50000000

long long sum;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* summation(void *arg) {
    long long number = *(long long*)arg;
    long long i;
    long long *answer = NULL;

    answer = malloc(sizeof(*answer));
    free(arg);
    arg = NULL;
    pthread_mutex_lock(&mutex);
    for(i=1; i<=NUM_LOOPS; i++) {
        
        sum += number;
        
    }

    *answer = sum;
    pthread_mutex_unlock(&mutex);

    //printf("%lld\n", number); 
    pthread_exit(answer);
    free(answer);
    answer = NULL;
}

int main (int argc, char **argv) {
    long long *number = NULL, *result = NULL;
    int total_arg = argc - 1;
    pthread_t thread_ids[total_arg];
    pthread_attr_t attr;

    printf("++++++++%s\n", argv[0]);

    for(int i=0; i< total_arg; i++) {
        number = malloc(sizeof(*number));
        *number = atoll(argv[i+1]);
        //printf("num %lld\n", *number);
        pthread_attr_init(&attr);
        pthread_create(&thread_ids[i], &attr, summation, number);
    }

    for(int i=0; i<total_arg; i++) {
        result = malloc(sizeof(*result));
        pthread_join(thread_ids[i], (void**)&result);
        printf("pthread id is %ld and sum is %lld\n", thread_ids[i], *result);
        free(result);
    }

    result = NULL;
    printf("++++++++\n");
    return 0;
}