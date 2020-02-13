#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <wait.h>

void *moyenne(void *arg);

pthread_mutex_t mutex;

int faixa = 40;
int op = 1;

int main(){


	pthread_t tid[10];
	pthread_mutex_init(&mutex,NULL);

	int i;
	int *vet = malloc(100*sizeof(int));
	srand(time(NULL));

	for(i = 0; i<100; i++){
		vet[i] = rand()%200;
	}
	int j;
	for(i = 0; i < 10 ; i ++){

		vet = NULL;
		vet = malloc(100*sizeof(int));

		for(j = 0; j<100; j++){
			vet[j] = rand()%200;
		}
		pthread_create(tid, NULL, moyenne, (void *)vet);

	}

	pthread_exit(NULL);
	return 0;
}


void *moyenne(void *arg){	

	int *vet = (int*)arg;
	int i;
	float media=0;
	for(i =0; i< 100;i++){
		media += (float)vet[i]/100.0;
	}

	pthread_mutex_lock(&mutex);

	printf("media %f op = %d\n", media, op++ );
		if(media > faixa){
			faixa = faixa + 10;
			printf("faixa aumentou %d\n", op-1 );
		}
	pthread_mutex_unlock(&mutex);

	free(arg);
}
