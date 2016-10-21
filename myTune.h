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

void *shuffle(song_node *table[]);

void *delete_song(song_node *table[], char *name);

void *deleteAll(song_node *table[]);

#endif
