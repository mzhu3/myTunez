#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myLink.h"
#include "myTune.h"
#include <ctype.h>

void * addSong(song_node *table[], char * name,char * artist){
  int row = tolower(artist[0])-97;
  table[row] = insert_order(table[row],name,artist);
  return table;
}

song_node * searchSong(song_node *table[], char *name){
  int i;
  song_node *temp;
  for(i = 0; i < 26; i ++){
    temp = findSong(table[i], name);
    if(temp){
      return temp;
    }
  }
  printf("No such song found!");
  return NULL;
}

song_node * searchArt(song_node * table[], char *artist){
  int i;
  song_node *temp;
  for(i = 0; i <26; i ++){
    temp = findArtist(table[i],artist);
    if(temp){
      return temp;
    }
  }
  printf("Artist not found!");
  return NULL;
}

void * print_letterSong(song_node *table[], char *letter){
  int row = tolower(* letter) - 97;
  print_list(table[row]);
}

void * print_artSong(song_node *table[], char *artist){
  char *cpy;
  strcpy(cpy,artist);
  int row = tolower(* artist) -97;
  printf("[");
  while(table[row]){
    if(!strcmp(cpy,table[row]->artist)){
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

void * printLib(song_node *table[]){
  int i;
  for(i = 0; i<26; i++){
    printf("%c List:\n",i+97);
    print_list(table[i]);
    
  }
}
    

int main(){
  printf("empty table:\n");
  printLib(table);
  printf("clear");
  addSong(table,"hello","kelvin");
  printf("added one song\n");
  printLib(table);
  

  return 0;
}

	
  
    
    

  


