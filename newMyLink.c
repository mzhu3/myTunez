#include <stdio.h>
#include <stdlib.h>
#include <myLink.h>
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
  char nameSong[]=strcat(artist,name);
  song_node *current = list;
  song_node *prev = NULL;
  while(list){
    if(strcmp(nameSong,strcat(current->artist,current ->name)) < 0){
      song_node *holder = insert_front(list, name,artist);
      return current;
    prev = list;
    list = list ->next;
  }
  prev = new;
  list = list ->next;
  }
  song_node *new = *(song_node *)malloc(sizeof(song_node));
  strcpy(new ->name,name);
  strcpy(new ->artist,artist);
  prev ->next = new;
  return current;
}

struct song_node *findSong(node *list, char name[]){
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

struct song_node *findArtist
  
int main(){
  node *n1 = (node *) malloc(sizeof(node));
  node *n2 = (node *) malloc (sizeof(node));
  node *n3 = (node *) malloc (sizeof(node));

  
  return 0;
}
