#include<stdio.h>
#include<pthread.h>
#include<string.h>


void *funcionConsonantes(void *arg){
  char * cadena = (char*) arg;
  printf("%s\n", cadena);
  printf("%lu\n", strlen(cadena));
  int cons = 0;

  for(int i=0; i<strlen(cadena); i++){
    if(!(cadena[i] == 'a' ||
           cadena[i] == 'e'||
            cadena[i] == 'i' ||
             cadena[i] == 'o' ||
              cadena[i] == 'u'))
      cons += 1;
    }
      printf("Constantes: %d", cons);

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

  pthread_create(&h1, NULL, funcionConsonantes, (void*)&cadena);
  pthread_create(&h2, NULL, funcionVocales, (void*)&cadena);
  pthread_join(h1, NULL);
  pthread_join(h2, NULL);

  return 0;
}
