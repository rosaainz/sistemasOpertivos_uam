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


  return 0;
}
