#include <string>
#include "./primitiveTypes.h"

using namespace std;

struct Items
{
    enum TypeofItems
    {
        consumables,
        armor,
        weapon,
        empty,
    };
    TypeofItems type = empty;
    short int quantity;
    float durability;
    short int damage = 0;
    short int defense = 0;
    short int heal = 0;
    enum effects
    {
        strengh,
        luck,
    };
    string art;
    short int midX, midY;
    string description[3] ={"", "", ""};
};

struct Inventory
{
    Items items[10] = {Items()};
    short int size;
};