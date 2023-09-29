#include<stdio.h>
#include<pthread.h>

#define N 5
int matriz[N][N];

typedef struct{
  int id;
  char valor;
}dato;

void * llena_renglon(void*arg){
  dato *d = (dato*)arg;
  for(int i=0; i<N; i++){
    matriz[d->id][i] = d->valor;
  }
  return NULL;
}


int main(){

  return 0;
}

