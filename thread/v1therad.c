#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <wait.h>

void *hello(void *arg);

int main(){

	pthread_t tid1, tid2;

	int arg1 =1, arg2 = 2;

	pthread_create(&tid1, NULL , hello, (void*) &arg1);
	pthread_create(&tid2, NULL , hello, (void*) &arg2);
	pthread_detach(tid2);
	pthread_detach(tid1);

	pthread_exit(NULL);
	return 0;
}


void *hello(void *arg){
	int num = *(int *) arg;
	printf("hello = %d\n", num);
}