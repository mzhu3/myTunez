#include <stdio.h>
#include <stdlib.h>
#include <myLink.h>
#include <string.h>
void print_list(node *list){
  printf("[");
  if(list-> i == NULL && list ->next== NULL){
    printf("]\n");
  }
  else{
    while(list->next){
      printf("%s,", list -> i);
      list = list ->next;
    }
    printf("%s", list ->i);
    printf("]\n");
  }
}

void *insert_front(node *list, node *new){
  new ->next = list;
  return new;
}

void *insert_order(node *list, node *new){
  char nameSong[]=strcat( new->name,new ->artist);
  node *temp = list;
  while(strcmp(nameSong,strcat(temp->name,new ->artist)) < 0){
    temp = temp ->next;
  }
  new -> next = temp;
  return list;
}

void *findSong(node *list, char name[]){
  node *temp = list;
  if(temp->next && strcmp(temp->name,name)){
    findSong(list ->next, name);
  }
  else if(!strcmp(temp->name,name)){
    printf("found: %s",temp ->name);
  }
  else{
    printf("Not found: %s")
      }
}
  
int main(){
  node *n1 = (node *) malloc(sizeof(node));
  node *n2 = (node *) malloc (sizeof(node));
  node *n3 = (node *) malloc (sizeof(node));

  
  return 0;
}
