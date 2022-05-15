#ifndef Map_H
#define Map_H

typedef struct Map Map;
typedef struct MapNode MapNode;

struct Map {
    MapNode *head;
};

struct MapNode {
    char key[100];
    char val[100];
    MapNode *next;
};


Map *createMap();

void madd(Map *map, char *key, char *val);

void mset(Map *map, char *key, char *val);

char *mget(Map *map, char *key);

int msize(Map *map);

int mindexof(Map *map, char *key);

bool mcontains(Map *map, char *key);

void printMap(Map *map);

bool misEmpty(Map *map);

MapNode *mremoveMapNode(Map *map, char *key);

MapNode *mremoveFirst(Map *map);

void deleteMap(Map *map);

#endif