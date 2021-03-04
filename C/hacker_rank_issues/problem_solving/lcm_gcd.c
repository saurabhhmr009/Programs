#include <stdio.h>
#include <stdlib.h>

int cases_result(int lcm, int gcd) {
    int total = 0, i = 2;
    int multiple = lcm;
    while(multiple <= gcd) {
        if((gcd%multiple) == 0) {
            total++;
        }
        multiple = lcm*i;
        i++;
    }
    return total;
}

int cal_gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return cal_gcd(b, a%b);
}


int gcd(int *arr, int length) {
    int i, result;
    
    result = *arr;
    for(i=1; i<length; i++) {
        result = cal_gcd(*(arr+i), result);
        if(result == 1) {
            return 1;
        }
    }
    return result;
}
int lcm(int *arr, int length1) {
    int result, i;
    result = *arr;
    for(i=1; i<length1; i++) {
        result = (*(arr+i)*result)/cal_gcd(*(arr+i), result);
    }
    return result;
}


int main(void) {
    int length1, length2, i;
    int *arr1 = NULL;
    int *arr2 = NULL;
    int gcd_result, lcm_result, final;
    
    scanf("%d", &length1);
    scanf("%d", &length2);

    arr1 = (int*)malloc(length1*sizeof(int));
    arr2 = (int*)malloc(length2*sizeof(int));
    
    for(i=0; i<length1; i++) {
        scanf("%d", arr1+i);
    }
    for(i=0; i<length2; i++) {
        scanf("%d", arr2+i);
    }
    gcd_result = gcd(arr2, length2);
    lcm_result = lcm(arr1, length1);

    final = cases_result(lcm_result, gcd_result);
    printf("%d\n", final);

    return 0;
}
