#include<stdio.h>
#include<pthread.h>

typedef struct{
  int id;
  char valor;
}dato;

char matriz[5][10];

void *funcionHilos(void *arg){
  dato *d = (dato*) arg;
  pthread_exit(0);

  return 0;
}

int main(){
  pthread_t h[5];
  dato d[5];

  for(int i=0; i<5; i++){
    d[i].id = i;
    d[i].valor = 'a' + i;

    pthread_create(&h[i], NULL, funcionHilos, (void*)&d[i]);
    pthread_join(h[i], NULL);
  }

  return 0;
}
