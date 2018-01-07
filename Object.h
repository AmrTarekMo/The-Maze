#ifndef OBJECT_H
#define OBJECT_H
#include <bits/stdc++.h>
//#include "Room.h"
//#include "Player.h"

using namespace std;
class Player;
class Room;
class Agent;
class Object
{
protected:
    string name;
    Room *cur_room;
    string open,type;
    bool door=false;
public:
    Player *hold_player;
    virtual bool act()=0;

    string getName();
    string getOpen();
    string getType();

    bool isDoor() const;
};

#endif