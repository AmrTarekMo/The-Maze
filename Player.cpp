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

Player :: Player (string _name, string _Discription , Room *_starting_room) {
    name = _name;
    discription = _Discription;
    cur_room = _starting_room;
    cur_room ->Enter(this);
    type="player";
}

bool Player::act(){
    string str,choose;
    vector <Agent*> fight_monster;

    cout<<name<<" you are in the "<<cur_room->getName()<<". "<<cur_room->getDiscription()<<endl;
    cur_room->PrintOccupants();


    for(int i=0 ; i<4 ; i++) {
        if(this->cur_room->occupants[i]==NULL)continue;
        if (this->cur_room->occupants[i]->getType() == "monster") {
            fight_monster.push_back(cur_room->occupants[i]);
        }
    }
    if(cur_room->getCheck() ) {
        int c=0;
        for (int i = 0; i < fight_monster.size(); i++)
            for (map<Props*, int>::iterator it = this->hold.begin(); it != this->hold.end(); it++)
                if (fight_monster[i]->getKill() == it->first->getName())
                    c++;
        if (c==fight_monster.size())cout << "saved " << endl;
        else {
            cout<<" your are very dead"<<endl;
            cur_room->Leave(this);
            return false;
        }
    }

    cout<<"The Equpment in this room : ";
    cur_room->PrintEqu();

    if(this->cur_room->Equ.size()!=0) {
        cout << "Choose ( take , drop , donothing ) " << endl;
        while (true) {
            cin >> choose;
            if (choose == "take") {
                cin >> str;
                bool flag = false;
                for (map<Props *, int>::iterator it = this->cur_room->Equ.begin();
                     it != this->cur_room->Equ.end(); it++) {
                    if (it->first->getName() == str) {
                        this->Take(it->first);
                        flag = true;
                    }
                }
                if (!flag)cout << "there is nothing called like this" << endl;
            }
            else if (choose == "drop") {
                cin >> str;
                bool flag = false;
                for (map<Props *, int>::iterator it = this->hold.begin(); it != this->hold.end(); it++) {
                    if (it->first->getName() == str) {
                        this->Drop(it->first);
                        flag = true;
                    }
                }
                if (!flag)cout << "There is nothing called drop this" << endl;
            }
            else break;
        }
    }
    cout<<"The Fixed Objects in this room : ";
    cur_room->PrintFixed();

    for (map<Props*, int>::iterator it = this->hold.begin(); it != this->hold.end(); it++) {
        it->first->hold_player=this;
        if (it->first->act())break;
    }

    for (map<Treasure*, int>::iterator it = this->cur_room->Trea.begin(); it != this->cur_room->Trea.end(); it++) {
        it->first->hold_player=this;
        if (it->first->act()) {
            cout << "the winner is " << this->getName() << endl;
            return 0;
        }
    }
    cout<<endl;
    if(this->hold.size()!=NULL) {
        cout<<"The Equ that "<<this->getName()<<" holds : ";
        for (map<Props *, int>::iterator it = this->hold.begin(); it != this->hold.end(); it++) {
            cout << it->first->getName() << " ";
        }
        cout << endl;
    }

    cur_room->printLinked();
    cout<<"Which exit? (or 'quit'): ";
    cin>>str;
    if(str == "quit"){
        cur_room->Leave(this);
        return false;
    }
    else {
        if (cur_room->getDirections_arr(str))
            cout << "There is nothing over there." << endl;
        else {
            int z = 0;
            FixedObj *temp;
            for (map<FixedObj *, int>::iterator it = this->cur_room->getLinked(str)->Fixed.begin(); it != this->cur_room->getLinked(str)->Fixed.end(); it++) {
                if (it->first->getOpen() == "door" and it->first->isDoor()==true) {
                    z = 1;
                    temp=it->first;
                }
            }
            if (z == 1){
                int a=0;
                for (map<Props *, int>::iterator it = this->hold.begin(); it != this->hold.end(); it++) {
                    if (it->first->getName() == temp->getInbox()->getName() ) {
                        a=1;
                        cur_room->Leave(this);
                        cur_room = cur_room->getLinked(str);
                        cur_room->Enter(this);
                        cout << name << " moves to the " << str << " ..." << endl;
                        break;
                    }
                }
                if(a==0)cout<<"You cant enter the room unless you have the key "<<endl;
            }
            else {
                cur_room->Leave(this);
                cur_room = cur_room->getLinked(str);
                cur_room->Enter(this);
                cout << name << " moves to the " << str << " ..." << endl;
            }
        }
        cout<<endl;
    }

    return true;
}

void Player::Take(Props *a){
    bool flag=false;
    for (map<Props* , int>::iterator it=hold.begin(); it!=hold.end(); ++it )
        if(it->first == a)flag=true;

    if(flag)cout<<"you cant add this item , you already have it "<<endl;
    else {
        hold[a];
        a->hold_player=this;
        cout<<a->getName()<<" has been taken"<<endl;

    }
}
void Player::Drop(Props *a){
    bool flag=false;
    for(map<Props* , int>::iterator it=hold.begin(); it!=hold.end(); ++it )
        if(it->first == a)flag=true;

    if(flag){
        hold.erase(a);
        cout<<a->getName()<<" has been dropped"<<endl;

    }
    else cout<<"There is no item called this"<<endl;
}