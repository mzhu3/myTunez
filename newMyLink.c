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
    while(list){
      printf("%s - %s,", list -> artist, list -> name);
      list = list ->next;
    }
    printf("]\n");
  }
}

void print_node(struct song_node *node){
  printf("[%s - %s]",node ->artist,node->name);
}

struct song_node *insert_front(struct song_node *list, char *name, char *artist){
  song_node *new = (song_node *)malloc (sizeof(song_node));
  strcpy(new -> name,name);
  strcpy(new ->artist, artist);
  new ->next = list;
  return new;
}

struct song_node *insert_order(struct song_node *list, char *name, char *artist){
  if(!list){
    return insert_front(list,name,artist);
  }
  if(strcmp(name, list -> name)<0){
    return insert_front(list,name,artist);
  }
  song_node *current = list;
  song_node *new = (song_node *)malloc (sizeof(song_node));
  song_node *prev = NULL;
  strcpy(new ->name,name);
  strcpy(new->artist,artist);
  
  while(current->next){
    if(strcmp(name,current->next ->name)>0){
      current = current ->next;
    }
    else{
      break;
    }
  }
  if(current != NULL){
    new ->next = current ->next;
    current ->next = new;
  }
  else{
    current ->next = new;
  }
  return list;
}
struct song_node *findSong(song_node *list, char *name){
  song_node *temp = list;
  while(temp){
    if(strcmp(temp->name,name)){
      temp = temp->next;
    }
    else{
      break;
    }
  }
  if(!temp){
    return NULL;
  }
  return temp;
}


struct song_node *findArtist(song_node * list, char *artist){
  song_node *temp = list;
  while(temp){
    if(strcmp(temp->artist,artist)){
      temp = temp ->next;
    }
    else{
      break;
    }
  }
  if(!temp){
    return NULL;
  }
  return temp;
}

 song_node * randomNode(song_node *list){
  srand(time(NULL));
  int len = 0;
  song_node *temp= list;
  while(list){
    len ++;
    list = list ->next;
  }

  int index = rand() %len;

   while(index){
    temp = temp ->next;
    index--;
  }
  return temp;
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
/*
int main(){
  song_node *n1 = (song_node *) malloc(sizeof(song_node));
  n1 = insert_order(n1,"hi","Leon");
  n1 = insert_order(n1,"bye","Leon");
  strcpy(n1->name, "lel");
  strcpy(n1->artist,"Leon");
  printf("printing n1:\n\n");
print_node(n1);
  print_list(n1);
  printf("\n");
  printf("insertfront : Dumbells - Leon :\n\n");
  n1 = insert_front(n1,"Dumbells","Leon");
  print_list(n1);

  printf("insertOrder:Hello\n");
  n1 = insert_order(n1,"Hello", "Leon");

  print_list(n1);
  printf("insertOrder:zzzz\n");
  n1 = insert_order(n1,"zzzz","Leon");
  print_list(n1);
    printf("insertOrder:Bye\n");
  n1 = insert_order(n1,"Bye", "Leon");
  print_list(n1);
  
  printf("finding hello: %s\n",findSong(n1,"Hello"));
  printf("finding Leon: %s\n",findArtist(n1,"Leon"));
  printf("finding chuck: %s\n",findArtist(n1,"chuck"));

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
