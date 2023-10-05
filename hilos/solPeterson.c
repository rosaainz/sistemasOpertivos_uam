#include<stdio.h>
#include<pthread.h>

int memComp[2];

int turn = -1;
int interes[2];

void * intentaRegionCritica(void* args){
  return 0;
}

int main(){
  pthread_t h0, h1;
  pthread_create(&h0, NULL, intentaRegionCritica, (void*)(size_t)0);
  pthread_create(&h0, NULL, intentaRegionCritica, (void*)(size_t)1);
  pthread_join(h0, NULL);
  pthread_join(h1, NULL);

  return 0;
}
