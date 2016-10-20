#include <stdlib.h>
#include <stdio.h>
#include "myLink.h"
#include "myTune.h"
#include <ctype.h>
void * add(song_node *list, char * name[],char * artist[]){
  int row = tolower(name[0]) %'a';
  table[row] = insert_order(table[row],name,artist);
}

song_node * searchSong(song_node *list, char *name[]){
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

song_node * searchArt(song_node * list, char *artist[]){
  int i;
  song_node *temp;
  for(i = 0; i <26, i ++){
    temp = findArtist(table[i],artist);
    if(temp){
      return temp;
    }
  }
  printf("Artist not found!");
  return NULL;
}

void * print_letterSong(song_node *list, char *letter[]){
  char lowerLetter = tolower(letter);
  int row = lowerLetter %'a';
  print_list(table[row]);
}

void * print_artSong(song_node *list, char *artist[]){
  char lowerArt = tolower(artist);
  int row = lowerArt[0] % 'a';
  printf("[");
  while(table[row]){
    if(!strcmp(artist,table[row]->artist)){
      if(table[row]->next){
	printf("%s - %s,",table[row]->name,table[row]->artist);
      }
      else{
	printf("%s - %s ", table[row]->name,table[row]->artist);
      }
    }
    else{
      table[row] = table[row]->next;
    }
  }
  printf("]\n");
}

void * print_lib(song_node *list[]){
  int i;
  char init;
  for(i = 0; i<26, i++){
    print_list(table[i]);
  }
}
    

int main(){
  print_lib(table);
  add(table,"Hello","Kelvin");
  print_lib(table);
  

  return 0;
}

	
  
    
    

  


