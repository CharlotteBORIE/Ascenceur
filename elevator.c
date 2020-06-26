#include <stdio.h>
#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
            Elevator* e=(Elevator*)malloc(sizeof(Elevator));
            e->capacity=capacity;
            e->currentFloor=currentFloor;
            e->persons=persons;
            e->targetFloor=NULL;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
    Building* b=(Building*)malloc(sizeof(Building));
    b->elevator=elevator;
    b->nbFloor=nbFloor;
    b->waitingLists=waitingLists;
    return b;
}

Profondeur(PersonList *persons){
    int j=0;
    PersonList* p=persons;
    while (p!=NULL){
        j++;
        p= p.next;
    }
    return j;
}

PersonList* exitElevator(Elevator *e){
    PersonList* L=NULL;
    int j=Profondeur(e.persons);
    for (int i=0;i<j;i++){
        if (e.persons[i][1]==e.currentFloor){
            L=insert(e.persons.pop(i), L);
        }
    }
    return L;
}

PersonList* enterElevator(Elevator *e, PersonList *list){
    int i=0;
     while (i<Profondeur(list)){
        while (Profondeur(e.persons)<e.capacity){
            insert(list.pop(i),e.persons);
        }
    }
    return list;
}

void stepElevator(Building *b){
    b.elevator->targetFloor=scanf("%d");
}