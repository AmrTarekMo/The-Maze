#include <bits/stdc++.h>
#include "Room.h"
#include "Player.h"
#include "Monster.h"
#include "Object.h"
#include "Props.h"
#include "FixedObj.h"
#include "Treasure.h"

using namespace std;

Props :: Props (string _name , Room *_starting_room , string _hide) {
    name = _name;
    cur_room = _starting_room;
    if(_hide!="hidden"){
        cur_room->Equ[this];
    }
}
bool Props::act(){
    for(map <FixedObj* ,int>::iterator it=hold_player->cur_room->Fixed.begin() ; it!= hold_player->cur_room->Fixed.end() ; ++it){
        if(it->first->getOpen() ==this->getName()){
            it->first->hold_player=this->hold_player;
            cout<<"The box is now opened"<<endl;
            it->first->act();
            it->first->hold_player->Drop(this);
            return true;
        }
    }
    return false;
}
