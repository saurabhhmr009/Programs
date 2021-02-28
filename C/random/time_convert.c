#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_time(char* str) {
    int convert;
    char buff[10];
    char * token = strtok(str, ":");
    convert = atoi(token);
    
    if(str[8] == 'P') {
        if(convert == 12) {
            sprintf(buff,"%c%c:%c%c:%c%c", str[0],str[1],str[3],str[4],str[6],str[7]);
        }
        else {
            convert = 12+convert;
            sprintf(buff, "%d:%c%c:%c%c", convert, str[3],str[4],str[6],str[7]);
        }
    }
    else {
        if(convert == 12) {
            sprintf(buff,"00:%c%c:%c%c", str[3],str[4],str[6],str[7]);
        }
        else {
            sprintf(buff,"%c%c:%c%c:%c%c", str[0],str[1],str[3],str[4],str[6],str[7]);
        }
    }
    printf("%s\n", buff);
}

int main(void) {
    char str[10] = {0};
    scanf("%[^\n]", str);
    convert_time(str);
    return 0;
}
