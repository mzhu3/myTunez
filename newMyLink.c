#include <stdio.h>
#include <stdlib.h>
#include "myLink.h"
#include <string.h>
void print_list(struct song_node *list){
  printf("[");
  if(list-> name == NULL && list -> artist ==NULL && list ->next== NULL){
    printf("]\n");
  }
  else{
    while(list->next){
      printf("%s - %s,", list -> name, list -> artist);
      list = list ->next;
    }
    printf("%s - %s", list ->name, list ->artist);
    printf("]\n");
  }
}

struct song_node *insert_front(struct song_node *list, char *name, char *artist){
  song_node *new = (song_node *)malloc (sizeof(song_node));
  strcpy(new -> name,name);
  strcpy(new ->artist, artist);
  new ->next = list;
  return new;
}

struct song_node *insert_order(struct song_node *list, char *name, char *artist){
  char *nameSong=strcat(artist,name);
  song_node *current = list;
  song_node *prev = NULL;
  song_node *new = (song_node *)malloc(sizeof(song_node));
  strcpy(new ->name,name);
  strcpy(new ->artist,artist);
  if(strcmp(nameSong, strcat(current ->artist,current ->name))<0){
    list = insert_front(current,new->name,new ->artist);
    return list;
  }
  while(current){
    if(strcmp(nameSong,strcat(current->artist,current ->name)) < 0){
      prev = insert_front(prev, new->name,new->artist);
      return list;
    }
    prev = list;
    current = current ->next;
  }
  prev ->next = new;
  return list;
}

struct song_node *findSong(song_node *list, char name[]){
  song_node *temp = list;
  if(temp->next && strcmp(temp->name,name)){
    findSong(temp ->next, name);
  }
  else if(!strcmp(temp->name,name)){
    printf("found: %s\n",temp ->name);
    return temp;
  }
  else{
    printf("Not found: %s\n",name);
    return NULL;
  }
}

//struct song_node *findArtist
  
int main(){
  song_node *n1 = (song_node *) malloc(sizeof(song_node));
  song_node *n2 = (song_node *) malloc (sizeof(song_node));
  song_node *n3 = (song_node *) malloc (sizeof(song_node));
  
  
  
  strcpy(n1-> name, "aba");
  strcpy(n1->artist,"Leon");
  strcpy(n2 ->name, "bab");
  strcpy(n2 -> artist, "Leon");
  strcpy(n3 -> name, "ppap");
  strcpy(n3 -> artist, "Leon");

  n1->next = n2;
  n2 -> next = n3;
  n3 ->next = NULL;

  print_list(n1);

  n1 = insert_front(n1,"Dumbells","Leon");

  print_list(n1);

  n1 = insert_order(n1,"Hello", "Leon");

  print_list(n1);
  
  return 0;
}
