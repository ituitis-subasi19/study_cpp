#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "movestack.h"
#include "stack.h"
using namespace std;

void Hanoi_iterative(Stack s[3], int n){
    MoveStack m;
    m.create();
    StackMoveType move = {n, 0, 2};
    m.push(move);
    Node* traverse;
    for(int i = 0; i < 3; i++){
        cout << "s[" << i << "]: ";
        traverse = s[i].head;
        while(traverse){
            cout << traverse->data << " ";
            traverse = traverse->next;
        }
        cout << endl;
    }
    cout << endl << endl;
    while(!m.isempty()){
        move = m.pop();
        if(move.n == 1){
            s[move.destination].push(s[move.source].pop());
                for(int i = 0; i < 3; i++){
                cout << "s[" << i << "]: ";
                traverse = s[i].head;
                while(traverse){
                    cout << traverse->data << " ";
                    traverse = traverse->next;
                }
                cout << endl;
            }
            cout << endl << endl;
        } else{
            int temp = 3 - move.destination - move.source;
            StackMoveType new_move = {move.n - 1, temp, move.destination};
            m.push(new_move);
            new_move = {1, move.source, move.destination};
            m.push(new_move);
            new_move = {move.n - 1, move.source, temp};
            m.push(new_move);
        }
    }
    m.close();
}

int main(){
    Stack s[3];

    for(int i = 0; i < 3; i++){
        s[i].create();
    }
    for(int i = 0; i < 5; i++){
        s[0].push(5-i);
    }
    Hanoi_iterative(s, 5);

    for(int i = 0; i < 3; i++){
        s[i].close();
    }
    return EXIT_SUCCESS;
}