#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[]){

	if(argc > 0){
		printf("%s\n", argv[0]);
		printf("%s\n", argv[1]);
		printf("%s\n", argv[2]);
		int i = atoi(argv[2]) + atoi(argv[1]);
		printf("%d\n", i);
	}
	return 0;
}
