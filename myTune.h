#ifndef MY_TUNE_H
#define MY_TUNE_H

#include "myLink.h"

song_node *table[26];

void * add(song_node *list, char *name[],char *);

song_node * searchSong(song_node *list, char *name[]);

song_node * searchArt(song_node *list, char *artist[]);

void *print_letterSong(song_node *list, char *letter[]);

void *print_artSong(song_node *list, char *artist[]);

void * print_lib(song_node *list);

song_node *shuffle(song_node *list);

song_node *delete_song(song_node *list, char *name[]);

song_node *deleteAll(song_node *list);

#endif
