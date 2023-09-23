#include<stdio.h>
#include<pthread.h>
#define MAX 100
#define NUM_H 10

int A[MAX][MAX];

void *llenarMatriz(){
  return 0;
}

void imprimirMatriz(){
}

int main(){
  pthread_t h[NUM_H];
  int estado[NUM_H];

  for(int i=0; i<NUM_H; i++){
    estado[i] = pthread_create(&h[i], NULL, llenarMatriz, (void*)(size_t)i);
  }
  for(int i=0; i<NUM_H; i++){
    if(estado[i] == 0){
      pthread_join(h[i], NULL);
    }
  }

  return 0;
}
