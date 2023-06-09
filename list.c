#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {

    List *lista = (List *) malloc(sizeof(List));
    lista->head = NULL;
    lista->current = NULL;
    lista->tail = NULL;

     return lista;
}

void * firstList(List * lista) {
if(lista->current == NULL) return NULL;
  
  lista->current = lista->head;
  
    return lista->head->data;
}

void * nextList(List * lista) {

  if(lista == NULL || lista->current == NULL) return NULL;

  lista->current = lista->current->next;

  if(lista->current == NULL) return NULL;
  
     return lista->current->data;
}

void * lastList(List * lista) {

if(lista == NULL ) return NULL;

  lista->current = lista->tail;

  if(lista->current == NULL) return NULL;
  
    return lista->current->data;
}

void * prevList(List * lista) {

if(lista->current == NULL || lista->current->prev == NULL) return NULL;

  lista->current = lista->current->prev;

  
    return lista->current->data;
}

void pushFront(List * lista, void * data) {

Node* x = createNode(data);

if(lista->head == NULL){

  lista->head = x;
  lista->tail = x;
}else{

  x->next = lista->head;
  lista->head->prev = x;
  lista->head = x;
}
}

void pushBack(List * list, void * data) {
  
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * lista, void * data) {

  Node* x = createNode(data);
  
  if(lista->current->next == NULL){
    
    x->prev = lista->current;
    lista->current->next = x;
    lista->tail = x;
      
  }else{

    x->prev = lista->current;
    lista->current->next->prev = x;
    x->next = lista->current->next;
    lista->current->next = x;
    
    
  }
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * lista) {

  void *aux = lista->current->data;
  if(lista->current->next == NULL){

    lista->tail = lista->current->prev;
    lista->tail->next = NULL;
    
  }else if(lista->head == lista->current){

    lista->head = lista->current->next;
    lista->head->prev = NULL;
    
  }else{

    lista->current->prev->next = lista->current->next;
    lista->current->next->prev = lista->current->prev;
    free(lista->current);
  }

    return aux;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}