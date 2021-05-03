#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct arg_list {
    long long num;
    long long sum;
};

void* summation(void *arg) {
    struct arg_list *arg_struct = (struct arg_list*)arg;
    long long i, sum = 0;

    for(i=1; i<=arg_struct->num; i++) {
        sum += i;
    }
    arg_struct->sum = sum;
    printf("pthread id is %ld\n", pthread_self());
    /* Status could be 0 or NULL */
    pthread_exit(NULL);
}

int main (int argc, char **argv) {
    long long number;
    int total_arg = argc - 1;
    pthread_t thread_ids[total_arg];
    pthread_attr_t attr;
    /* Structure array to store the result of individual threads.*/
    struct arg_list args[total_arg];

    printf("++++++++%s\n", argv[0]);

    for(int i=0; i< total_arg; i++) {
        number = atoll(argv[i+1]);
        pthread_attr_init(&attr);
        args[i].num = number; 
        pthread_create(&thread_ids[i], &attr, summation, &args[i]);
        printf("+++++++\n");
    }

    for(int i=0; i<total_arg; i++) {
        pthread_join(thread_ids[i], NULL);
        printf("Sum is %lld\n", args[i].sum);
    }

    return 0;
}