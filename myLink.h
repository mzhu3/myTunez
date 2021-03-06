#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

struct song_node * insert_front( struct song_node * list, char * name, char * artist );
struct song_node * insert_order( struct song_node * list, char * name, char * artist );
void print_list( struct song_node * list );
struct song_node * findSong( struct song_node * list, char * name );
struct song_node * findArtist( struct song_node * list, char * artist );
struct song_node * randomNode( struct song_node * list );
struct song_node * removeNode( struct song_node * list, char * name );
struct song_node * freeAll( struct song_node * list );

#endif
