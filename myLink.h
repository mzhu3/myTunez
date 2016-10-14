typedef struct node {
  int i;
  struct node *next;
} node;
void print_list(node *list);

node *insert_front(node *list, int new);

node *insert_order(node *list,int new);

node *findSong(node *list,char name[]);

node *firstArtSong(node *list,char artist[]);

node *rng(node *list);

node *remove(node *ist);

node *free_list(node *list);
