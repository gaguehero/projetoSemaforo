#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* semaforoThread(void*arg){
    int num = *(int*) arg;
    while(1)
    {
        printf("Semaforo %d Vermelho\n", num);
        pthread_mutex_lock(&mutex);
        printf("Semaforo %d Verde\n", num);
        sleep(5);
        printf("Semaforo %d Amarelo\n", num);
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t semaforo1;
    pthread_t semaforo2;
    int i=1;
    int j=2;
    pthread_create(&semaforo1, NULL, semaforoThread, &i);
    pthread_create(&semaforo2, NULL, semaforoThread, &j);


    pthread_join(semaforo1,NULL);
    pthread_join(semaforo2,NULL);   
}