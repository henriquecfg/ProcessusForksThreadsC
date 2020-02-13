#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(){

	int n = 0;
	if ((n = fork()) < 0) exit(1);
	
	if( n == 0){
		printf("fill - PID = %d \n",getpid());
		for(;;);
	}else{
		pid_t m; int r;
		if( (m = wait(&r)) < 0 ) exit(1);
		printf("fin de proc %d avec %d",m,r);
	}
	return 0;
}
