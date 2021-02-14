#include <stdio.h>

main(){
	int c;
	while((c = getchar()) != EOF){
		putchar(c);
		if(c == ' '){
			while((c = getchar()) == ' ')
				;
			putchar(c);
		}
	}
	//Use ctrl+D on unix systems to output an EOF to stdin
}
