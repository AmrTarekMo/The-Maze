#ifndef ROOM_H
#define ROOM_H

#include <bits/stdc++.h>

using namespace std;

class Agent;
class Props;
class FixedObj;
class Treasure;
class Room
{
private:
    string Name,Discription , arra[4],directions[4];
    Room *ptr[4]  ;
    bool Check=false;

public:
    map<Props*,int> Equ;
    int n;
    map<FixedObj*,int> Fixed;
    map<Treasure*,int> Trea;
    Agent *occupants[4] = {NULL,NULL,NULL,NULL};

    Room(string iname , string idisc , int _n );
    string getName();
    string getDiscription();
    bool getDirections_arr(string kelma);

    void printLinked();
    void Link(Room *r , string direction);
    Room *getLinked(string direction);
    void operator = ( Room rhs);

    void Enter(Agent *a);
    void Leave(Agent *a);
    void PrintOccupants();

    void PrintEqu();
    void PrintFixed();
    void setCheck(bool a);
    bool getCheck();


};

#endif
