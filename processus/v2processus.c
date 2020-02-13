#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[]){
	int n; 
	pid_t pid;
	int i;
	for( i = 1; i<=argc; i++){
		if( (n = fork()) < 0){
			exit(0);
		}else{
			if(n ==0){
				if (  execlp(argv[i], argv[i], NULL) == -1 ){
					return 0;
				}
			}else pid = wait(&n);
		}	
	}
}