#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myLink.h"
#include "myTune.h"
#include <ctype.h>

void * addSong(song_node *table[], char * name,char * artist){
  int row = (tolower(artist[0])) - 97;
  table[row] = insert_order(table[row],name,artist);
  
}

song_node * searchSong(song_node *table[], char *name){
  int i;
  song_node *temp;
  for(i = 0; i <26; i ++){
    temp = findSong(table[i],name);
    if(temp){
      return temp;
    }
  }
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
  return temp;
}

void * print_letterSong(song_node *table[], char *letter){
  int row = tolower(* letter) - 97;
  print_list(table[row]);
}



void * printLib(song_node *table[]){
  int i;
  for(i = 0; i<26; i++){
    if(table[i]){
    printf("%c List:\n",i+97);
    print_list(table[i]);
    }
  }
}

void * print_artSong(song_node *table[], char *artist){
  int row = tolower( artist[0]) - 97;
  int i = 0;
  song_node *temp = table[row];
  while(temp){
    if(!strcmp(temp->artist,artist)){
      print_node(temp);
    }
    temp = temp ->next;
  }
  printf("\n");
}

void *shuffle(song_node *table[]){
  srand(time(NULL));
  song_node *original= (song_node *)malloc (sizeof(song_node));
  int i = 0;
  int j = 0;
  song_node *temp;
  for(j; j <26;j++){
    temp = table[j];
    if(temp){
      while(temp){
	original = insert_order(original,temp->name,temp->artist);
	i++;
	temp = temp->next;
      }
    }
  }
  printf("%d\n",i);
  original = original ->next;
  int RNG = (rand()%i)+1;
  int k = 0;
  printf("%d\n", RNG);
  song_node *temp2;
  for(k;k<RNG;k++){
    temp2 = randomNode(original);
    print_node(temp2);
    original = removeNode(original,temp2);
  }
}
void *delete_song(song_node *table[],char *name){
  int i = 0;
  song_node * temp;
  temp = searchSong(table,name);
  if(temp){
  int init = tolower(temp->artist[0])- 97;
  table[init]=removeNode(table[init],temp);
  }
}

void * deleteAll(song_node *table[]){
  int i = 0;
  for(i; i<26;i++){
    table[i]=freeAll(table[i]);
  }
}
/*
int main(){
  printf("empty table:\n");
  printLib(table);
  printf("adding more songs\n");
  addSong(table,"hello","kelvin");
  addSong(table,"closer","chainsmoker");
  addSong(table,"heathens","twenty one pilots");
  addSong(table,"All we know", "chainsmoker");
  addSong(table,"don't let me down","chainsmoker");
  addSong(table,"clarity","zedd");
  addSong(table,"warriors","imagine dragons");
  printLib(table);
  printf("\n");
  printf("searching for chainsmoker: %s\n",searchArt(table,"chainsmoker"));
  printf("searching for zedd: %s\n\n",searchArt(table,"zedd"));
  printf("searching for warriors: %s\n",searchSong(table,"warriors"));
  printf("searching for halsey: %s\n",searchArt(table,"halsey"));
  printf("searching for darude sandstorm: %s\n",searchSong(table,"darude sandstorm"));
  printf("printing letter a:\n");
  print_letterSong(table,"a");
  printf("printing letter c:\n");
   print_letterSong(table,"c");
   printf("printing artist albus:\n");
   print_artSong(table,"albus");
    printf("printing artist chainsmoker:\n\n\n");
    print_artSong(table,"chainsmoker");
     printLib(table);
    printf("printing artist i:\n");
   print_artSong(table,"i");
   printf("test shuffle\n");
   shuffle(table);
   printf("\n");
   printf("Remove Warriors\n");
    delete_song(table,"warriors");
    printLib(table);

    printf("freeing all\n");
    deleteAll(table);
    printf("Current table:\n");
    printLib(table);
   return 0;
}

*/
	
  
    
    

  


