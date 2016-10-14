typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * add(song_node *list, char new[];);

song_node * searchSong(song_node *list, char name[]);

song_node * searchArt(song_node *list, char artist[]);

void *print_letterSong(song_node *list, char letter);

void *print_artSong(song_node *list, char artist);

song_node * print_lib(song_node *list);

song_node *shuffle(song_node *list);

song_node *delete_song(song_node *list, char name[]);

song_node *deleteAll(song_node *list);
