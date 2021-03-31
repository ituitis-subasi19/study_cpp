#pragma once
#include "node.h"

struct Stack{
    Node* head;
    void create();
    void close();
    void push(StackDataType);
    StackDataType pop();
    bool isempty(); 
};