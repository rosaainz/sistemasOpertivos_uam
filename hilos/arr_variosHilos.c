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

int main(){

  pthread_t h[NUM_HILOS];
  int estado[NUM_HILOS];

  for(int i=0; i<NUM_HILOS; i++){
    estado[i] = pthread_create(&h[i], NULL, llenarArreglo, (void*)(size_t)i);
  }


  return 0;
}
