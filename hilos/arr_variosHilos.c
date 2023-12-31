#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#define MAX 100
#define NUM_HILOS 10

int ARR[MAX];

void *llenarArreglo(void *arg){
  int num_hilo = (int)(size_t)arg;

  for( int i=0; i<MAX; i++){
    ARR[i] = rand() % 1000 + 1;
  }
  return 0;
}

void imprimirArreglo(){
  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++){
      printf("%d", ARR[i]);
    }
  }
}


int main(){

  pthread_t h[NUM_HILOS];
  int estado[NUM_HILOS];

  for(int i=0; i<NUM_HILOS; i++){
    estado[i] = pthread_create(&h[i], NULL, llenarArreglo, (void*)(size_t)i);
  }
  for(int i=0; i<NUM_HILOS; i++){
    if(estado[i] == 0)
      pthread_join(h[i], NULL);
  }
  imprimirArreglo();


  return 0;
}
