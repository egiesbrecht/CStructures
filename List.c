#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

List *createList() {
    return (List*) malloc(sizeof(List));
}


void ladd(List *list, char *val) {
    ListNode *newListNode=(ListNode*) malloc(sizeof(ListNode));
    strcpy(newListNode->val, val);

    if(list->head==NULL) {
        list->head=newListNode;
        list->foot=newListNode;
        return;
    }

    ListNode *foot=list->foot;
    foot->next=newListNode;
    newListNode->prev=foot;
    list->foot=newListNode;
}


int lsize(List *list) {
    int len=0;
    for(ListNode *ptr=list->head; ptr!=NULL; ptr=ptr->next)
        len++;
    return len;
}


ListNode *lgetNode(List *list, int index) {
    if(index>=lsize(list)) {
        printf("index out of bounds\n");
        return NULL;
    }

    ListNode *ptr=list->head;
    for(int i=0; i<index; i++)
        ptr=ptr->next;

    return ptr;
}

char *lget(List *list, int index) {
    ListNode *n=lgetNode(list, index);
    if(n!=NULL)
        return n->val;
    else
        return NULL;
}


ListNode *lremoveByValue(List *list, char *val) {
    ListNode *ptr=list->head;
    if(strcmp(ptr->val, val)==0) {
        list->head=ptr->next;
        ptr->next->prev=NULL;
        return ptr;
    }

    ptr=ptr->next;
    for(; ptr!=NULL; ptr=ptr->next) {
        if(strcmp(ptr->val, val)==0) {
            ptr->prev->next=ptr->next;
            if(ptr->next!=NULL)
                ptr->next->prev=ptr->prev;
            return ptr;
        }

    }

    return NULL;
}


ListNode *lremoveByIndex(List *list, int index) {
    int size=lsize(list);
    if(index>=size) {
        printf("index out of bounds\n");
        return NULL;
    }

    if(index==0) {
        ListNode *head=list->head;
        head->next->prev=NULL;
        list->head=head->next;
        return head;
    }

    ListNode *ptr=list->head;
    for(int i=0; i<index; i++) {
        ptr=ptr->next;
    }

    ptr->prev->next=ptr->next;
    if(ptr->next!=NULL)
        ptr->next->prev=ptr->prev;
    return ptr;
}


void lset(List *list, int index, char *val) {
    strcpy(lgetNode(list, index)->val, val);
}


int lindexof(List *list, char *val) {
    ListNode *ptr=list->head;
    for(int i=0; ptr!=NULL; i++) {
        if(strcmp(val, ptr->val)==0)
            return i;
        ptr=ptr->next;
    }
    return -1;
}


bool lcontains(List *list, char *val) {
    return lindexof(list, val)!=-1;
}


void lremoveFirst(List *list) {
    if(list->head==list->foot) {
        free(list->head);
        list->head=NULL;
        list->foot=NULL;
        return;
    }
    ListNode *first=list->head;
    first->next->prev=NULL;
    list->head=first->next;
    free(first);
}


void deleteList(List *list) {
    while(list->head!=NULL)
        lremoveFirst(list);
    free(list);
}


void printList(List *list) {
    if(list->head==NULL) {
        printf("[]");
        return;
    }

    ListNode *ptr=list->head;
    printf("[%s", ptr->val);
    ptr=ptr->next;

    for(; ptr!=NULL; ptr=ptr->next) {
        printf(", %s", ptr->val);
    }
    printf("]\n");
}
