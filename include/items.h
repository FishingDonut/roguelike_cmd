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

struct Inventory{
    Items items[10];
    short int size;
};