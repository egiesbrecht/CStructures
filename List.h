#ifndef List_H
#define List_H

typedef struct ListNode ListNode;
typedef struct List List;

struct List {
    ListNode *head;
    ListNode *foot;
};

struct ListNode {
    ListNode *next;
    ListNode *prev;
    char val[100];
};


List *createList();

void ladd(List *list, char *val);

int lsize(List *list);

ListNode *lgetNode(List *list, int index);

char *lget(List *list, int index);

ListNode *lremoveByValue(List *list, char *val);

ListNode *lremoveByIndex(List *list, int index);

void lset(List *list, int index, char *val);

int lindexof(List *list, char *val);

bool lcontains(List *list, char *val);

void lremoveFirst(List *list);

void deleteList(List *list);

void printList(List *list);

#endif