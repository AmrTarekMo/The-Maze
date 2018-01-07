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

FixedObj :: FixedObj (string _name , Room *_starting_room , string _key,Props *_inside , bool _door ) {
    name = _name;
    cur_room = _starting_room;
    open = _key;
    inbox=_inside;
    cur_room->Fixed[this];
    door=_door;
}
bool FixedObj::act(){
    cout<<"There is -> "<<this->getInbox()->getName()<<endl;

    hold_player=this->hold_player;
    hold_player->hold[this->getInbox()];
    return true;
}

Props* FixedObj::getInbox(){
    return inbox;
}

