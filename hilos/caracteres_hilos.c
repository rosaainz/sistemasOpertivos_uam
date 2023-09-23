#include<stdio.h>
#include<pthread.h>

void *funcionConstantes(void *arg){
  char * cadena = (char*) arg;
  printf("%s\n", cadena);
  return 0;
}

void *funcionVocales(void *arg){
  char * cadena = (char*) arg;
  printf("%s\n", cadena);
  return 0;
}

int main(){
  pthread_t h1, h2;
  char cadena[50];
  scanf("%s", cadena);

  pthread_create(&h1, NULL, funcionConstantes, (void*)&cadena);
  pthread_create(&h2, NULL, funcionVocales, (void*)&cadena);
  pthread_join(h1, NULL);
  pthread_join(h2, NULL);

  return 0;
}
