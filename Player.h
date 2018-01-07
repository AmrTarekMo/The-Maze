#ifndef Player_H
#define Player_H
#include <bits/stdc++.h>
#include "Agent.h"
#include "Props.h"
//#include "Object.h"
using namespace std;
class Room;
class Object;
class Player : public Agent
{
private:
    Room *starting_room;
public:
    map<Props*, int> hold ;

    bool act();
    Player(string _name,string _Discription ,Room *_starting_room);
    void Take(Props *a);
    void Drop(Props *a);

};

#endif