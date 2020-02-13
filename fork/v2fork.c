#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(){

	int a = 5;
	int n;
	if ((n = fork()) < 0) exit(1);
	
	if( n == 0){
		a = 4;

		printf("fill - PID = %d \n",getpid());
		printf("%d\n", a );
		exit(0);
	}else{
		pid_t m; int r;
		if( (m = wait(&r)) < 0 ) exit(1);
		printf("%d\n", a );
		printf("fin de proc %d avec %d",m,r);
	}
	return 0;
}

