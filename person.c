#include <stdio.h>
#include <stdlib.h>
#include "person.h"

Person* createPerson(int src, int dest){
        Person* p=(Person*)malloc(sizeof(Person));
        p->src=src;
        p->dest=dest;
        return p;

}

PersonList* insert(Person *p, PersonList *list){
    PersonList* L=(PersonList*)malloc(sizeof(PersonList));
    if (list==NULL){
        L->person=p;
        return L;
    }
    L->person=list->person;
    L->next=insert(p,list->next);
    return L;
}