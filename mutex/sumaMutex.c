#include<stdio.h>
#include<pthread.h>

int A[100];
pthread_mutex_t candado;
int suma=0;


void * intentaRegionCritica(){
  return 0;
}


void llenarArreglo(){
  for(int i=0; i<100; i++){
    A[i]=1;
  }
}

void imprimirArreglo(){
  for(int i=0; i<100; i++){
    printf("%d",A[i]);
  }
}


int sumar (int numHilo){
  int inicio =  numHilo * 10;
  int fin = (numHilo+1)*10;
  int res=0;

  for(int i=inicio; i<fin; i++){
    res += A[i];
  }
  return res;
}

int main(){
  pthread_t h[10];

  llenarArreglo();
  imprimirArreglo();

    //inicia mutex
  pthread_mutex_init(&candado, NULL);
  for(int i=0; i<10; i++){
    pthread_create(&h[i], NULL, intentaRegionCritica, (void*)(size_t)i);
  }

  for(int i=0; i<10; i++){
    pthread_join(h[i], NULL);
  }

  pthread_mutex_unlock(&candado);
  return 0;
}

