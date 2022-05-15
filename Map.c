#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Map.h"

Map *createMap() {
    return (Map*) malloc(sizeof(Map));
}


void madd(Map *map, char *key, char *val) {
    MapNode *newMapNode=(MapNode*) malloc(sizeof(MapNode));
    strcpy(newMapNode->key, key);
    strcpy(newMapNode->val, val);

    if(map->head==NULL) {
        map->head=newMapNode;
        return;
    }

    MapNode *ptr=map->head;
    while(ptr->next!=NULL) {
        ptr=ptr->next;
    }
    
    ptr->next=newMapNode;
}


void mset(Map *map, char *key, char *val) {
    MapNode *ptr=map->head;

    while(ptr!=NULL) {
        if(strcmp(key, ptr->key)==0) {
            strcpy(ptr->val, val);
            return;
        }
        ptr=ptr->next;
    }
}


char *mget(Map *map, char *key) {
    for(MapNode *ptr=map->head; ptr!=NULL; ptr=ptr->next) {
        if(strcmp(key, ptr->key)==0)
            return ptr->val;
    }

    return NULL;
}


int msize(Map *map) {
    int len=0;
    for(MapNode *ptr=map->head; ptr!=NULL; ptr=ptr->next)
        len++;
    return len;
}


int mindexof(Map *map, char *key) {
    MapNode *ptr=map->head;
    for(int i=0; ptr!=NULL; i++) {
        if(strcmp(key, ptr->key)==0)
            return i;
        ptr=ptr->next;
    }
    return -1;
}


bool mcontains(Map *map, char *key) {
    return mindexof(map, key)!=-1;
}


void printMap(Map *map) {
    printf("[ ");
    for(MapNode *ptr=map->head; ptr!=NULL; ptr=ptr->next) {
        printf("(%s : %s) ", ptr->key, ptr->val);
    }
    printf("]\n");
}


bool misEmpty(Map *map) {
    return map->head==NULL;
}


MapNode *mremoveMapNode(Map *map, char *key) {
    MapNode *head=map->head;
    if(strcmp(head->key, key)==0) {
        map->head=head->next;
        return head;
    }

    for(MapNode *last=map->head; last->next!=NULL; last=last->next) {
        if(strcmp(last->next->key, key)==0) {
            MapNode *rem=last->next;
            if(rem->next!=NULL)
                last->next=rem->next;
            else
                last->next=NULL;
            return rem;
        }
    }

    return NULL;
}


MapNode *mremoveFirst(Map *map) {
    MapNode *oldhead=map->head;
    map->head=oldhead->next;
    return oldhead;
}


void deleteMap(Map *map) {
    while(map->head!=NULL)
        free(mremoveFirst(map));
    free(map);
}
