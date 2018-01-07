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

Room::Room(string iname , string idisc , int _n ){
    Name=iname;
    Discription=idisc;
    n=_n;
    for(int i=0 ; i<4 ; i++){
        directions[i]="No";
        arra[i]="No";
    }
}
string Room::getName(){
    return Name;
}
string Room::getDiscription(){
    return Discription;
}

bool Room::getDirections_arr(string kelma){  // bool check if its connected so return false so if = false and cont loop
    for(int i=0 ; i<4 ;i++){                // if not connected all the loop return true and this room is not linked
        if(directions[i]==kelma)return false;
    }
    return true;
}

void Room::Link(Room* r , string direction){ // accepts obj in  ptr fourm
    if(direction=="North"){     // arra[0]= kitchen
        ptr[0]=r;                 // direction[0]= north
        arra[0] = r->getName(); // -> bec of ptr
        directions[0]="North";  // ptr holds pointer of linked room (r)
    }
    else if(direction=="East"){
        ptr[1]=r;
        arra[1] = r->getName();
        directions[1]="East";
    }
    else if(direction=="West"){
        ptr[2]=r;
        arra[2] = r->getName();
        directions[2]="West";
    }
    else if(direction=="South"){
        ptr[3]=r;
        arra[3] = r->getName();
        directions[3]="South";
    }
}

void Room::printLinked(){ // return all linked rooms to this room
    cout<<"There is an exit to ";
    for(int i=0 ; i<4 ; ++i){
        if(directions[i]!="North" and directions[i]!="South" and directions[i]!="West" and directions[i]!="East")
            continue;
        cout<<directions[i]<<" ("<<arra[i]<<") , ";
    }
    cout<<endl;
}

Room* Room::getLinked(string direction){ // return pointer and puts it in other obj
    for(int i=0 ; i<4 ; i++)
        if(direction==directions[i])
            return ptr[i];
}

void Room::operator= ( Room rhs) {
    Name = rhs.Name;
    Discription = rhs.Discription;
    for (int i = 0; i < 4; i++) {
        directions[i] = rhs.directions[i];
        arra[i] = rhs.arra[i];
        ptr[i] = rhs.ptr[i];
    }
}

void Room::Enter(Agent *a) {
    for(int i=0 ; i<4 ; i++)
        if(occupants[i]==NULL) {
            occupants[i] = a;
            break;
        }
}

void Room::Leave(Agent *a){
    for(int i=0 ; i<4 ; i++)
        if(occupants[i]==a)
            occupants[i]=NULL;
}

void Room::PrintOccupants(){
    int c=0;
    cout<<"The Monsters or Players in this room : ";
    for(int i=0  ; i<4 ; i++)
        if(occupants[i]!=NULL   ) {
            cout<<endl;
            cout << occupants[i]->getName() << occupants[i]->getDiscription() ;
            c++;
        }
    if(c==0)cout<<"None"<<endl;
    else cout<<endl;
}

void Room::PrintEqu(){

    if(Equ.size() == 0)cout<<"None"<<endl;
    else {
        cout<<endl;
        for (map<Props*, int>::iterator it = Equ.begin(); it != Equ.end(); ++it)
            cout << it->first->getName() << ". ";
        cout << endl;
    }
}
void Room::PrintFixed() {
    if (Fixed.size() == 0)cout << "None" << endl;
    else {
        cout<<endl;
        for (map<FixedObj *, int>::iterator it = Fixed.begin(); it != Fixed.end(); ++it)
            cout << it->first->getName()<<". ";
        cout << endl;
    }
}

void Room::setCheck(bool a){
    Check=a;
}
bool Room::getCheck(){
    return Check;
}
