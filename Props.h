#ifndef PROPS_H
#define PROPS_H

#include <bits/stdc++.h>
//#include "Room.h"
#include "Object.h"

using namespace std;
class Room;
class Player;
class Props : public Object
{
private:
    Room *starting_room;
public:
    bool act();
    Props ( string _name , Room *_starting_room , string _hide);

};

#endif