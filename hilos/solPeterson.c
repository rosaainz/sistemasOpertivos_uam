#include<stdio.h>
#include<pthread.h>

int memComp[2];

int turno = -1;
int interes[2];

void * intentaRegionCritica(void* args){
  int id = (int)(size_t)args;

  for(int i=0; i<5; i++){
    turno = id;
    interes[id] = 1;

    while(turno ==id && interes[1-id]==1);

    memComp[id] = memComp[id] + 1;
    memComp[1 - id] = memComp[1 - id] - 1;
    printf("%d, %d\n", memComp[id], memComp[1 - id]);

    interes[id] = 0;
  }
  pthread_exit(0);
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
