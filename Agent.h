#ifndef AGENT_H
#define AGENT_H
#include <bits/stdc++.h>
#include "Room.h"
using namespace std;

//class Room;
class Agent
{
protected:
    //Room *cur_room;
    string name , discription,type="non";
    string kill;

public:
    Room *cur_room;
    bool found=false;

    virtual bool act()=0;
    string getName();
    string getDiscription();
    string getType();
    string getKill();

};

#endif
