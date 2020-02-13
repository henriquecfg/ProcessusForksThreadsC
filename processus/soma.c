#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[]){

	int n = atoi(argv[0]);
	int m = atoi(argv[1]);
	int j = m + n;
	printf("%d\n %d", j, n );
	return 0;
}
