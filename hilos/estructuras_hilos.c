#include<stdio.h>
#include<pthread.h>

typedef struct{
  int id;
  char valor;
}dato;

void *funcionHilos(void *arg){
  dato *d = (dato*) arg;
  printf("Hilo con el id %d, Valor %c\n", d->id, d->valor);
  return 0;
}

int main(){
  pthread_t h[10];


  return 0;
}
