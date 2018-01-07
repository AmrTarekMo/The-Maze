#include <bits/stdc++.h>
#include "Room.h"
#include "Agent.h"
#include "Player.h"
#include "Monster.h"
#include "Object.h"
#include "Props.h"
#include "FixedObj.h"
#include "Treasure.h"
// Name : Amr Tarek Mahmoud
// ID : 20150181
using namespace std;

int main() {
    srand(time(NULL));
    Room Greed_Island("Greed_Island", " Is actually a game taken place in the real world on an island in the middle of the sea the game was invented by Ging Gon's father  ",1);
    Room Dolle_Harbor ("Dolle_Harbor ", " Is a huge harbor where the hunter exam take place in order to become an hunter  ",2);
    Room NGL("NGL", " Is a place where technology aren't allowed all who live there has no connection to the outside world , this where the chemera ant king was born  ",3);
    Room Whale_Island("Whale_Island", " room4 dis  ",4);
    Room Palace("Palace", " This is the place where the evil king Maryom and his loyal guards took in order to take over the world  ",5);
    Room Metero_city("Metero_city", " This city was abandoned long time ago now all who lives in it are the people who don't have a place to belong to like the phantom troupe  ",6);
    Room Yorknew_city("Yorknew_city", " It is a huge city where auctions are made to buy anything you can think of, it is the city run by the mafia  ",7);
    Room Kukuroo_mountain("Kukuroo_mountain", " Is a scary mountain ,the entrance is a huge gate beyond this gate lives a family of assassins the zoldyck family  ",8);
    Room Hunter_Association("Hunter_Association", " Is the place where all the hunters stay and it is the headquarters for them  ",9);
//---------------------------------------------------------------------------------------------------------------------------------------------
    Greed_Island.Link(&Dolle_Harbor , "East");
    Dolle_Harbor .Link(&Greed_Island, "West");
    Dolle_Harbor .Link(&NGL, "East");
    NGL.Link(&Dolle_Harbor , "West");
    Greed_Island.Link(&Whale_Island, "North");
    Whale_Island.Link(&Greed_Island, "South");
    Dolle_Harbor .Link(&Palace, "North");
    Palace.Link(&Dolle_Harbor , "South");
    NGL.Link(&Metero_city, "North");
    Metero_city.Link(&NGL, "South");
    Whale_Island.Link(&Palace, "East");
    Palace.Link(&Whale_Island, "West");
    Palace.Link(&Metero_city, "East");
    Metero_city.Link(&Palace, "West");
    Whale_Island.Link(&Yorknew_city, "North");
    Yorknew_city.Link(&Whale_Island, "South");
    Palace.Link(&Kukuroo_mountain, "North");
    Kukuroo_mountain.Link(&Palace, "South");
    Kukuroo_mountain.Link(&Hunter_Association, "East");
    Hunter_Association.Link(&Kukuroo_mountain, "West");
//----------------------------------------------------------------------------
    Monster *Gyro = new Monster("Gyro", " evil king of NGL wass killed by the chemira ants ", &Kukuroo_mountain , "sword");
    Monster *Muruem = new Monster("Muruem", " evil king of the cheimera ant and was killed by netero ", &Palace , "axe");
    Player *Kite = new Player("Kite", " the trainer of ging freecs and was killed by neferpeto ", &NGL);
    Player *Netero = new Player("Netero", " the chairman of the hunter association and was killed durning the fight with the king of the chemira ant ", &NGL);
//----------------------------------------------------------------------------
    Props *key1 = new Props("key_1" , &Dolle_Harbor  , "nothidden");
    Props *key2 = new Props("key_2" , &Whale_Island , "nothidden" );
    Props *weapon1 = new Props("sword" , &Metero_city , "nothidden");
    Props *weapon2 = new Props("axe"   , &Greed_Island , "nothidden");
    Props *key3 = new Props("key_3" , &Yorknew_city , "nothidden");
    Props *key4 = new Props("golden_key" , &Metero_city ,"hidden");
    Props *key5 = new Props("silver_key" , &Greed_Island ,"hidden") ;
//----------------------------------------------------------------------------
    FixedObj *box1 = new FixedObj("Box1" , &Metero_city , "key_1" , key4 , false );
    FixedObj *box2 = new FixedObj("Box2" , &Greed_Island , "key_2" , key5 , false);
    FixedObj *door = new FixedObj("door" , &Kukuroo_mountain , "door" , key3 , true);
    Treasure *treasure = new Treasure("Treasure" , &Hunter_Association , key4 , key5 );

    vector<Agent*> agents(4);
    agents[0] = Kite;
    agents[1] = Netero;
    agents[2] = Gyro;
    agents[3] = Muruem;

    cout << "Welcome" << endl;
    while (true) {
        for (int i = 0; i < agents.size(); i++) {
            bool flag = agents[i]->act();
            if (!flag) {
                if(agents[i]->found == true){
                    return 0;
                }
                cout<<agents[i]->getName()<<" is dead or quits"<<endl;
                agents.erase(agents.begin()+i);
            }
            if(agents.size()==2){
                cout<<"Game Over"<<endl;
                return 0;
            }
        }
    }
    return 0;
}