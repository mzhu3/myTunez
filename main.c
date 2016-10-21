#include <stdio.h>
#include <stdlib.h>
#include "myTune.h"

int main(){
  printf("List FUNCTIONS------------------------------------------\n");
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
  printf("----------------------------------------------------------\n");
  printf("Lib Functions --------------------------------------------\n");
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
    printf("THE END-----------------------------------------------------\n");
   return 0;
}
