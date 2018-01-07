#ifndef Monster_H
#define Monster_H
#include <bits/stdc++.h>
#include "Agent.h"
#include "Room.h"
using namespace std;

class Monster : public Agent
{
private:
    Room *starting_room ;
public:
    Monster(string _name,string _Discription , Room *_starting_room , string _kill );
    bool act();
    int BFS(Room *current_room);

};

#endif
