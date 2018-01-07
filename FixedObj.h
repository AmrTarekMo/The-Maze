#ifndef FIXEDOBJ_H
#define FIXEDOBJ_H

#include <bits/stdc++.h>
#include "Room.h"
#include "Object.h"
#include "Props.h"

using namespace std;
class Player;
class FixedObj : public Object
{
private:
    Room *starting_room;
    Props *inbox;
public:
    Props *getInbox();
    bool act();
    FixedObj ( string _name , Room *_starting_room , string _key , Props *_inside , bool _door);



};

#endif