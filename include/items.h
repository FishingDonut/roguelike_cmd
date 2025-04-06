#include<string>
using namespace std;
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
    string art;
};

struct Inventory{
    Items items[10];
    short int size;
};