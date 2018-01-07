#include <bits/stdc++.h>
#include "Room.h"
#include "Agent.h"
#include "Player.h"
#include "Monster.h"
#include "Object.h"
#include "Props.h"
#include "FixedObj.h"
#include "Treasure.h"
using namespace std;

Treasure :: Treasure (string _name , Room *_starting_room , Props* _key1 , Props * _key2 ) {
    name = _name;
    cur_room = _starting_room;
    key1 = _key1;
    key2 = _key2;
    type = "Treasure";
    cur_room->Trea[this];
}

bool Treasure::act() {
    int c = 0;
    for (map<Props*, int>::iterator it = hold_player->hold.begin(); it != hold_player->hold.end(); ++it) {
        if (it->first->getName() == this->getKey1()->getName() or it->first->getName() == this->getKey2()->getName())
            c++;
    }
    if (c == 2){
        cout << "you found the Treasure " << endl;
        hold_player->found =true;
        return true;
    }
    else{
        cout<<"you found the treasure but couldnt open it "<<endl;
        return false;
    }
}

Props *Treasure::getKey1() {
    return key1;
}

Props *Treasure::getKey2() {
    return key2;
}


