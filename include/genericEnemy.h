#include<player.h>
#include<iostream>
using namespace std;
class genericEnemy{
private:
    int _health = 100;
    int _damage = 10;
    Position _position;
public:
    void moveToPlayer(player p){
        Position position = p.getPosition();
        /* logic to check if have wall in path*/
    }
    void atackPlayer(player p, int damage){
        p.removeHealth(damage);
    }
    void randomMove(){
        Position position = _position;
        position.x +=  rand()%2;// need make the logic to check if have wall in path
        position.y +=  rand()%2;
        _position = position;
    }
    void SetSpecs(int health, int damage, Position position){
        _health = health;
        _damage = damage;
        _position = position;
    }
    }
};