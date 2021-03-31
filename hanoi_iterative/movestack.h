#pragma once

struct StackMoveType{
    int n;
    int source;
    int destination;
    StackMoveType* next;
};

struct MoveStack{
    StackMoveType* head;
    void create();
    void close();
    void push(StackMoveType);
    StackMoveType pop();
    bool isempty(); 
};