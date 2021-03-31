#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "movestack.h"
using namespace std;

void MoveStack::create(){
    head = NULL;
}

void MoveStack::close(){
    StackMoveType* todelete;
    while(!isempty()){
        todelete = head;
        head = head->next;
        delete todelete;
    }
}

void MoveStack::push(StackMoveType topush){
    StackMoveType* new_move = new StackMoveType;
    new_move->n = topush.n;
    new_move->source = topush.source;
    new_move->destination = topush.destination;
    new_move->next = head;
    head = new_move;
}

StackMoveType MoveStack::pop(){
    StackMoveType top;
    top.n = head->n;
    top.source = head->source;
    top.destination = head->destination;
    StackMoveType* todelete = head;
    head = head->next;
    delete todelete;
    return top;
}

bool MoveStack::isempty(){
    return head == NULL;
}