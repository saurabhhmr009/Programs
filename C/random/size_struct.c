#include<stdio.h>

struct ABC
{
    int a;
    float b;
    char c;
};

int main()
{
    struct ABC *ptr=(struct ABC *)0;
    printf("Size of structure is: %d\n",ptr);
    ptr++;
    printf("Size of structure is: %d\n",ptr);
    return 0;
}