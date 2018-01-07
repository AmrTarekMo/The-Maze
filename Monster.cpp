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

Monster :: Monster (string _name,string _Discription,Room *_starting_room , string _kill) {
    name = _name;
    discription = _Discription;
    kill = _kill;
    cur_room = _starting_room;
    cur_room->Enter(this);
    cur_room->setCheck(true);
    type="monster";
}

bool Monster::act() {
    int n=rand() % 4;
    string direction;
    switch(n) {
        case 0: direction = "North"; break;
        case 1: direction = "East"; break;
        case 2: direction = "West"; break;
        case 3: direction = "South"; break;
    }
    cur_room->setCheck(false);
    cur_room->Leave(this);
    if(cur_room -> getLinked(direction) != NULL) {
        cur_room = cur_room->getLinked(direction);
    }
    cur_room->Enter(this);
    cur_room->setCheck(true);

    return true;
}


/*
bool Monster::act() {
    string Direction;

    int East=100000,West=100000,South=100000,North=100000;
    if(cur_room->getLinked("East")!=NULL)East=BFS(cur_room);
    if(cur_room->getLinked("West")!=NULL)West=BFS(cur_room);
    if(cur_room->getLinked("South")!=NULL)South=BFS(cur_room);
    if(cur_room->getLinked("North")!=NULL)North=BFS(cur_room);

    if(East <= West && East <= South && East <= North){
        cur_room->setCheck(false);
        cur_room->Leave(this);
        cur_room = cur_room->getLinked("East");
        cur_room->Enter(this);
        cur_room->setCheck(true);
    }
    if(East >= West && West <= South && West <= North){
        cur_room->setCheck(false);
        cur_room->Leave(this);
        cur_room = cur_room->getLinked("West");
        cur_room->Enter(this);
        cur_room->setCheck(true);
    }
    if(South <= West && East >= South && South <= North){
        cur_room->setCheck(false);
        cur_room->Leave(this);
        cur_room = cur_room->getLinked("South");
        cur_room->Enter(this);
        cur_room->setCheck(true);
    }
    if(North <= West && North <= South && East >= North){
        cur_room->setCheck(false);
        cur_room->Leave(this);
        cur_room = cur_room->getLinked("North");
        cur_room->Enter(this);
        cur_room->setCheck(true);
    }
    return true;
}

int Monster ::BFS(Room *current_room){
    queue<Room*>q;
    q.push(current_room);
    Room *visit[1000] = {};
    memset(visit,NULL,sizeof visit);
    int res=0 ;
    while(q.size()){
        int currentLevel=q.size();
        while(currentLevel--){
            Room *r=q.front();q.pop();
            for(int i = 0 ; i < 4; ++i){
                if(r->occupants[i]->getType()== "player")return res;
            }
            if(visit[r->n]!=NULL)continue;
            visit[r->n]=current_room;

            if(r->getLinked("North")!=NULL)q.push(r->getLinked("North"));
            if(r->getLinked("East")!=NULL)q.push(r->getLinked("East"));
            if(r->getLinked("West")!=NULL)q.push(r->getLinked("West"));
            if(r->getLinked("South")!=NULL)q.push(r->getLinked("South"));
        }
        res++;
    }
    return 100000;
}

*/
