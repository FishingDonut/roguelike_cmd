struct Position{
    int x;
    int y;
};
struct Items{
    enum TypeofItems{
        potion = 2,
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

struct Inventory{
    Items items[10];
    short int size;
};
struct Player{
    Position position;
    int health = 100;
    Inventory inventory;
    void setRelativePosition(int x, int y){
        position.x += x;
        position.y += y;
    }
    void setPosition(int x, int y){
        position.x = x;
        position.y = y;
    }
    Position getPosition(){
        return position;
    }
    int getHealth(){
        return health;
    }
    void addHealth(int health){
        health += health;
    }
    void removeHealth(int health){
        health -= health;
    }
};

// int main(){
//     player p;
//     p.setPosition(1,1);
//     p._inventory.items[0].type = Items::potion;
//     p._inventory.items[0].quantity = 10;
//     return 0;
// }