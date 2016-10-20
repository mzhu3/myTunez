#include <stdlib.h>
#include <stdio.h>
#include "myLink.h"
#include "myTune.h"
#include <ctype.h>
song_node * add(song_node *list, char name[],char artist[]){
  int row = tolower(name[0]) %'a';
  table[row] = insert_order(table[row],name,artist);
}

song_node * searchSong(song_node *list, char name[]){
  int i;
  song_node *temp;
  for(i = 0; i < 26, i ++){
    temp = findSong(table[i], name);
    if(temp){
      return temp;
    }
  }
  printf("No such song found!");
  return NULL;
}


