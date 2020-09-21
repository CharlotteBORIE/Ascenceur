#include <stdio.h>
#include <stdlib.h>
#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
            Elevator* e=(Elevator*)malloc(sizeof(Elevator));
            e->capacity=capacity;
            e->currentFloor=currentFloor;
            e->persons=persons;
            // e->targetFloor=0;
            return e;
        }

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
    Building* b=(Building*)malloc(sizeof(Building));
    b->elevator=elevator;
    b->nbFloor=nbFloor;
    b->waitingLists=waitingLists;
    return b;
}

int Profondeur(PersonList *persons){
    int j=0;
    PersonList* p=persons;
    while (p!=NULL){
        j++;
        p= p->next;
    }
    return j;
}

PersonList* exitElevator(Elevator *e){ //système FILO First in Last Out
    PersonList* L=e->persons;
    e->persons=NULL;
    PersonList* L_exit=NULL;
    while(L!=NULL){
        if (L->person->dest==e->currentFloor){
            L_exit=insert(L->person, L_exit); 
        }
        else{
            e->persons=insert(L->person,e->persons);
        }      
        L=L->next;
    }
    return L_exit;
}

PersonList* enterElevator(Elevator *e, PersonList *list){

    //calculer l'occupation de l'ascenceur
    int occupation=0;
    PersonList* p=e->persons;
    while (p!=NULL){
        occupation++;
        p= p->next;
    }

    PersonList* L_enter=NULL;
     while (list!=NULL){
        while (occupation<e->capacity){
            L_enter=insert(list->person,L_enter);
            e->persons=insert(list->person,e->persons);
            list=list->next;
            occupation++;
        }
    }
    return list;
}

void stepElevator(Building *b){
    if (b->elevator->currentFloor==b->elevator->targetFloor){
        exitElevator(b->elevator);
        b->waitingLists[b->elevator->targetFloor]=enterElevator(b->elevator,b->waitingLists[b->elevator->currentFloor]);
    }
    else{
        if (b->elevator->currentFloor<b->elevator->targetFloor){
        b->elevator->currentFloor++;
        }
        else {
            b->elevator->currentFloor--;
        }
    }

}