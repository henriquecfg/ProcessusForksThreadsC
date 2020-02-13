#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(){

	volatile int n = 0;
	printf("msg 1 n = %d \n",n++);
	fork();
	printf("msg 2 n = %d \n",n++);
    fork();
	printf("msg 3 n = %d \n",n++);
	return 0;
}
