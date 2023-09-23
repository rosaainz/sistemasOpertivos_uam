#include<stdio.h>
#include<pthread.h>
#define MAX 100
#define NUM_H 10

int A[MAX][MAX];

void *llenarMatriz(void *arg){
  int numHilo = (int)(size_t)arg;

  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++){
      A[i][j] = numHilo;
    }
  }
  return 0;
}

void imprimirMatriz(){
  for(int i=0; i<MAX; i++){
   for(int j=0; j<MAX; j++){
    printf("%d", A[i][j]);
   }
  }
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

  imprimirMatriz();

  return 0;
}
