#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *funcionHiloPadre(void *arg){
  int num_hilo = (int)(size_t)arg;
  printf("Proceso padre, hilo  %d\n", num_hilo);
  return 0;
}

void *funcionHiloHijo(void *arg){
  int  num_hilo = (int)(size_t)arg;
  printf("Proceso hijo, hilo %d\n", num_hilo);
  return 0;
}

int main(){

  pthread_t h1, h2;
  int idf;
  idf = fork();

  if(idf > 0){
    pthread_create(&h1, NULL, funcionHiloPadre, (void*)(size_t)1);
    pthread_create(&h2, NULL, funcionHiloPadre, (void*)(size_t)2);
  }
  if(idf == 0){
    pthread_create(&h1, NULL, funcionHiloHijo, (void*)(size_t)1);
    pthread_create(&h2, NULL, funcionHiloHijo, (void*)(size_t)2);
  }

  pthread_join(h1, NULL);
  pthread_join(h2, NULL);

int wait;
scanf("%d", wait);
return 0;
}
