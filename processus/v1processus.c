#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[]){

	int n, n1, n2; pid_t pid;
	if( (n = fork()) == -1){
		return 0;
	}

	if( n == 0 ){

		if ( execv("mult", argv) == -1){
			return 0;
		}
	}

	else pid = wait(&n);
	

	return 0;
}

