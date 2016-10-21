#ifndef MY_TUNE_H
#define MY_TUNE_H

#include "myLink.h"

song_node *table[26];

void * add(song_node *table[], char *name,char *artist);

song_node * searchSong(song_node *table[], char *name);

song_node * searchArt(song_node *table[], char *artist);

void *print_letterSong(song_node *table[], char *letter);

void *print_artSong(song_node *table[], char *artist);

void * print_lib(song_node *table[]);

song_node *shuffle(song_node *table[]);

song_node *delete_song(song_node *table[], char *name);

song_node *deleteAll(song_node *table[]);

#endif
