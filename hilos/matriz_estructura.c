#include<stdio.h>
#include<pthread.h>

typedef struct{
  int id;
  char valor;
}dato;

char matriz[5][10];

void *funcionHilos(void *arg){
  dato *d = (dato*) arg;

  int i = d->id;
  for(int j=0; j<10; j++){
    matriz[i][j] = d->valor;
  }
  pthread_exit(0);

  return 0;
}

void imprimirMatriz(){
  for(int i=0; i<5; i++){
    for(int j=0; j<10; j++){
      printf("%c", matriz[i][j]);
    }
    printf("\n");
  }
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

  imprimirMatriz();
  return 0;
}
