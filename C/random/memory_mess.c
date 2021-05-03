#include <stdio.h>
#include <stdlib.h>

char* message() {
    char *msg = malloc(20*sizeof(*msg));
    msg = "Hello world";
    printf("%p\n", msg);
    return msg;
}

void print_msg() {
    char *ret = NULL;
    ret = message();
    printf("address %p String %s\n", ret, ret);
    free(ret);
}

int main (void) {
    print_msg();
    return 0;
}