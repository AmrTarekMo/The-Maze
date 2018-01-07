#ifndef TREASURE_H
#define TREASURE_H

#include <bits/stdc++.h>
#include "Room.h"
//#include "Object.h"
#include "Props.h"
using namespace std;
class Object;
class Treasure : public Object
{
private:
    Room *starting_room;
    Props *key1 , *key2;
public:

    bool act();
    Props *getKey1() ;
    Props *getKey2() ;

    Treasure ( string _name , Room *_starting_room , Props* _key1 , Props * _key2);


};

#endif