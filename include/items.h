#include <string>
#include "./primitiveTypes.h"

using namespace std;

struct Items
{
    enum TypeofItems
    {
        potion = 2,
        armor,
        weapon,
        key,
    };
    TypeofItems type;
    short int quantity;
    float durability;
    enum effects
    {
        strengh,
        luck,
    };
    string art;
    short int midX, midY;
};

struct Inventory
{
    Items items[10];
    short int size;
};