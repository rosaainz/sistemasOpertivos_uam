#include<stdio.h>
#include<pthread.h>

typedef struct{
  int id;
  char valor;
}dato;

void *funcionHilos(void *arg){
  dato *d = (dato*) arg;
  printf("Hilo con el id %d, Valor %c\n", d->id, d->valor);
  pthread_exit(0);

  return 0;
}

int main(){
  pthread_t h1, h2;
  dato d1, d2;

  d1.id = 1;
  d1.valor = 'a';

  d2.id = 2;
  d2.valor = 'b';


  pthread_create(&h1, NULL, funcionHilos, (void*)&d1);
  pthread_create(&h2, NULL, funcionHilos, (void*)&d2);

  pthread_join(h1, NULL);
  pthread_join(h2, NULL);

  return 0;
}
