#include<stdio.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>


int main(){
  pthread_t h0, h1;
  int idf = 0;

  idf = fork();

  if( idf == 0 ){
    pthread_create(&h0, NULL, mensajeHijo, (void*)(size_t)1);
    pthread_create(&h2, NULL, mensajeHijo, (void*)(size_t)2);


  }else{

  }



  return 0;
}
