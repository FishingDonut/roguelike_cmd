struct Position{
    int x;
    int y;
};
struct Items{
    enum TypeofItems{
        potion,
        armor,
        weapon,
        key,
    };
    TypeofItems type;
    short int quantity;
    float durability;
    enum effects{
        strengh,
        luck,
    };
};

struct inventory{
    Items items[10];
    short int size;
};

class player{
private:
    Position _position;
    int _health = 100;
public:
    inventory _inventory;
    void setRelativePosition(int x, int y){
        _position.x += x;
        _position.y += y;
    }
    void setPosition(int x, int y){
        _position.x = x;
        _position.y = y;
    }
    Position getPosition(){
        return _position;
    }
    int getHealth(){
        return _health;
    }
    void addHealth(int health){
        _health += health;
    }
    void removeHealth(int health){
        _health -= health;
    }
};
// int main(){
//     player p;
//     p.setPosition(1,1);
//     p._inventory.items[0].type = Items::potion;
//     p._inventory.items[0].quantity = 10;
//     return 0;
// }