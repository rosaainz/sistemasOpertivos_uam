#include<stdio.h>
#include<pthread.h>

#define N 5
int matriz[N][N];

typedef struct{
  int renglon;
  char valor;
}dato;

void * llena_renglon(void*arg){
  dato *d = (dato*)arg;
  for(int i=0; i<N; i++){
    matriz[d->renglon][i] = d->valor;
  }
  return NULL;
}

void * imprimir_matriz(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      printf("%d", matriz[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int main(){
  pthread_t h[N];
  dato d[N];

  for(int i=0; i<N; i++){
    printf("Ingresa el valor para el hilo %d: ",i);
    int valor;
    scanf("%d", &valor);

    d[i].renglon = 0;
    d[i].valor = valor;

    pthread_create(&h[i], NULL, llena_renglon, (void*)&d[i]);

  }

  for(int i=0;i<N; i++ ){
    pthread_join(h[i], NULL);
   }


  imprimir_matriz();

  return 0;
}

