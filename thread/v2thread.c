#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <wait.h>

void *operation(void *arg);

#define NBOP  10
#define MAX  10
#define RETRAIT  0
#define AJOUT  1

int solde = 2;
pthread_mutex_t mutex;

typedef struct {
	int num;
	int montant;
	int op;
}Data;

int main(){

	pthread_t tid[NBOP];
	pthread_mutex_init(&mutex,NULL);

	int i;
	srand(time(NULL));

	Data *data;

	for(i = 0 ; i <  NBOP; i++){
		data = malloc(sizeof(Data));

		data->num = i + 1;
		data->montant = rand()%MAX;
		data->op = rand()%2;

		pthread_create(tid,NULL, operation, (void *)data);
	}

	pthread_exit(NULL);
	return 0;
}


void *operation(void *arg){	

	int num = ((Data*)arg)->num;
	int op = ((Data*)arg)->op;
	int montant = ((Data*)arg)->montant;

	printf("operation n = %d, op = %d , montant = %d\n", num, op, montant );

	pthread_mutex_lock(&mutex);
	if(op == RETRAIT){
		if(solde >= montant){
			solde -= montant;
			printf("nouveau solde = %d\n", solde);
		}else{
			printf("solde  insuffisant = %d , montant = %d\n", solde, montant);
		}
	}else{
		solde += montant;
		printf("nouveau solde apres ajout = %d\n", solde);
	}pthread_mutex_unlock(&mutex);

	free(arg);
}