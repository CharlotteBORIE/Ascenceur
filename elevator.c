#include <stdio.h>
#include <stdlib.h>
#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
            Elevator* e=(Elevator*)malloc(sizeof(Elevator));
            e->capacity=capacity;
            e->currentFloor=currentFloor;
            e->persons=persons;
            e->targetFloor=0;
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

PersonList* exitElevator(Elevator *e){
    PersonList* L=NULL;
    int j=Profondeur(e->persons);
    for (int i=0;i<j;i++){
        if (e->persons->person->dest==e->currentFloor){
            L=insert(e->persons->person, L);
            e->persons->person=e->persons->next->person;
            e->persons->next=e->persons->next->next;

        }
    }
    return L;
}

PersonList* enterElevator(Elevator *e, PersonList *list){
    int i=0;
     while (i<Profondeur(list)){
        while (Profondeur(e->persons)<e->capacity){
            insert(list->person,e->persons);
            list->person=list->next->person;
            list->next=list->next->next;
        }
    }
    return list;
}

void stepElevator(Building *b){
    if (b->elevator->currentFloor==b->elevator->targetFloor){
        exitElevator(b->elevator);
        enterElevator(b->elevator,b->waitingLists[b->elevator->currentFloor]);
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