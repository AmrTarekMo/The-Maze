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

bool Agent::act(){

}
string Agent::getName()  {
    return name;
}
string Agent::getDiscription()  {
    return discription;
}

string Agent::getType() {
    return type;
}
string Agent:: getKill(){
    return kill;
}
