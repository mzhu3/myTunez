#include <stdio.h>
#include <stdlib.h>
#include "myLink.h"
#include <string.h>
#include <time.h>
void print_list(struct song_node *list){
  printf("[");
  if(list ==NULL){
    printf("]\n");
  }else{
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
  
  if(strcmp(name, list -> name)<0){
    return insert_front(list,name,artist);
  }
  song_node *current = list;
  song_node *new = (song_node *)malloc (sizeof(song_node));
  strcpy(new ->name,name);
  strcpy(new->artist,artist);
  new ->next = NULL;
  
  while(current ->next){
    if(strcmp(name,current->next ->name)<0){
      song_node * temp = insert_front(current ->next ,name,artist);
      current ->next = temp;
      return list;
    }
    list = list ->next;
    
  }
  list ->next = new;
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
struct song_node *findArtist(song_node * list, char artist[]){
  song_node *temp = list;
  if(temp->next && strcmp(temp->artist,artist)){
    findArtist(temp ->next, artist);
  }
  else if(!strcmp(temp->artist,artist)){
    printf("found: %s\n",temp ->artist);
    return temp;
  }
  else{
    printf("Not found: %s\n",artist);
    return NULL;
  }
}

struct song_node *randomNode(song_node *list){
  srand(time(NULL));
  int len = 0;
  song_node *temp;
  while(temp){
    len ++;
    temp = temp ->next;
  }
  int index = rand() %len;
  while(index){
    list = list ->next;
    index--;
  }
  return list;
}

struct song_node * removeNode(song_node * list, char *name){
  song_node *prev = NULL;
  song_node *current = list;
  song_node *temp = list;
  if(!strcmp(list->name, name)){
    song_node *temp2 = list ->next;
    free(list);
    return temp2;
  }
  current = current ->next;
  while(current){
    if(!strcmp(current->name,name)){
      temp ->next = current ->next;
      free(current);
      return list;
    }
    temp = current;
    current = current ->next;
  }
  return NULL;
}

struct song_node *freeAll(song_node * list){
  song_node *temp = list;
  song_node *start;
  while(list){
    start = list ->next;
    free(list);
    list = start;
  }
  return NULL;
  
}
/*int main(){
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

  printf("printing n1:\n\n");
  print_list(n1);
  printf("\n");
  printf("insertfront : Dumbells - Leon :\n\n");
  n1 = insert_front(n1,"Dumbells","Leon");
  print_list(n1);

  n1 = insert_order(n1,"Hello", "Leon");

  print_list(n1);

  printf("finding hello: %s\n",findSong(n1,"Hello"));
  printf("finding Leon: %s\n",findArtist(n1,"Leon"));
  printf("finding leon: %s\n",findArtist(n1,"leon"));

  printf("Random node : %s\n",randomNode(n1));

  printf("Remove node : Hello\n");
    n1 = removeNode(n1,"Hello");
  print_list(n1);

  printf("Remove All\n");
   n1 =freeAll(n1);
   print_list(n1);
  return 0;
}
*/
