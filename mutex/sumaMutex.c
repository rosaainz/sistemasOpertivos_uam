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


void sumar (){
}

int main(){
  llenarArreglo();
  imprimirArreglo();
  return 0;
}
