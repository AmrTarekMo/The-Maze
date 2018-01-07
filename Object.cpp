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

string Object::getName() {
    return name;
}
bool Object::act(){

}

string Object::getOpen() {
    return open;
}

string Object::getType(){
    return type;
}

bool Object::isDoor() const {
    return door;
}
