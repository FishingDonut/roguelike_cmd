#include<player.h>
#include<iostream>
using namespace std;
struct genericEnemy{
    int health = 100;
    int damage = 10;
    Position position;
    void moveToPlayer(Player p){
        Position position = p.getPosition();
        /* logic to check if have wall in path*/
    }
    void atackPlayer(Player p, int damage){
        p.removeHealth(damage);
    }
    void randomMove(){
        Position position = position;
        position.x +=  rand()%2;// need make the logic to check if have wall in path
        position.y +=  rand()%2;
        position = position;
    }
    void SetSpecs(int health, int damage, Position position){
        health = health;
        damage = damage;
        position = position;
    }
};
