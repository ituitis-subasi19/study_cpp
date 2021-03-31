#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "stack.h"
using namespace std;

void Stack::create(){
    head = NULL;
}

void Stack::close(){
    Node* todelete;
    while(!isempty()){
        todelete = head;
        head = head->next;
        delete todelete;
    }
}

void Stack::push(StackDataType topush){
    Node* new_node = new Node;
    new_node->data = topush;
    new_node->next = head;
    head = new_node;
}

StackDataType Stack::pop(){
    StackDataType top = head->data;
    Node* todelete = head;
    head = head->next;
    delete todelete;
    return top;
}

bool Stack::isempty(){
    return head == NULL;
}