#include<windows.h>
#include "./player.h"
void Draw(string art,short int startX){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int midX = consoleWidth / 2;
    int midY = consoleHeight / 2 - 19;
    int counter = 0;
    int lineOffset = 0;
    std::string line;
    size_t pos = 0, newPos;
    while ((newPos = art.find('\n', pos)) != std::string::npos)
    {
        counter++;
        line = art.substr(pos, newPos - pos);
        SetConsoleCursorPosition(console, { startX, (SHORT)(midY + lineOffset) });
        std::cout << line;
        pos = newPos + 1;
        lineOffset++;
    }
    
    
}
void AllItems(Inventory &inventory){
    Items sword;
    sword.durability = 100;
    sword.quantity=1;
    sword.type = Items::weapon;
    sword.art = "      .         \n"
        "     /:\\    (\"\"\")\n"
        "     |:|     III\n"
        "     |:|     III\n"
        "     |:|     III\n"
        "     |:|   __III__\n"
        "     |:| /:-.___,-:\\\n"
        "     |:| \\]  |:|  [/\n"
        "     |:|     |:|\n"
        "     |:|     |:|\n"
        "     |:|     |:|\n"
        " /]  |:|  [\\ |:|\n"
        " \\:-'\"\"\"`-:/ |:|\n"
        "   \"\"III\"\"   |:|\n"
        "     III     |:|\n"
        "     III     |:|\n"
        "     III     |:|\n"
        "    (___)    \\:/\n"
        "              \"\n";
    sword.midX = 16/2;
    sword.midY = 19/2;
    inventory.items[0] = sword;
    Items shield;
    shield.durability = 100;
    shield.quantity=1;
    shield.type = Items::armor;
    shield.art = "           _ . - = - . _\n"
        "       . \"  \\  \\   /  /  \" .\n"
        "     ,  \\                 /  .\n"
        "   . \\   _,.--~=~\"~=~--.._   / .\n"
        "  ;  _.-\"  / \\ !   ! / \\  \"-._  .\n"
        " / ,\"     / ,` .---. `, \\     \". \\\n"
        "/.'   `~  |   /:::::\\   |  ~`   '.\\\n"
        "\\`.  `~   |   \\:::::/   | ~`  ~ .'/\n"
        " \\ `.  `~ \\ `, `~~~' ,` /   ~`.' /\n"
        "  .  \"-._  \\ / !   ! \\ /  _.-\"  .\n"
        "   ./    \"=~~.._  _..~~=`\"    \\.\n"
        "     ,/         \"\"          \\,\n"
        "       . _/             \\_ . \n"
        "          \" - ./. .\\. - \"\n";
    inventory.items[1] = shield;
    sword.midX = 32/2;
    sword.midY = 19/2;
}
void ItemsMenu(){
    system("cls");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO windowInfo;
    GetConsoleScreenBufferInfo(console, &windowInfo);
    cout<<windowInfo.dwSize.X<<endl;
    cout<<windowInfo.dwSize.Y;
    short int CalcRap = windowInfo.dwSize.X - 1;
    short int MidCalc = windowInfo.dwSize.X - 1;
    SetConsoleCursorPosition(console, {CalcRap, 0});
    short int midY = windowInfo.dwSize.Y%2==0?windowInfo.dwSize.Y/2-1:windowInfo.dwSize.Y/2;
    short int midX = windowInfo.dwSize.X/2;
    for (short int i = 0; i < windowInfo.dwSize.Y; i++){
        SetConsoleCursorPosition(console, {CalcRap, i});
        cout<<"|";
        SetConsoleCursorPosition(console, {0, i});
        cout<<"|";
        if (i==midY) {
            MidCalc = windowInfo.dwSize.X - 4;
            SetConsoleCursorPosition(console, {MidCalc, i});
            cout<<"D ->";
            SetConsoleCursorPosition(console, {0, i});    
            cout<<"<- A";
        }
    }
    Player p;
    AllItems(p.inventory);
    midX -= 20/2;
    midY -= 19/2;
    SetConsoleCursorPosition(console, {midX, midY});  
    // cout<<"center";
    Draw(p.inventory.items[0].art,midX);
    getch();

    // cout<<" __";
    // midY +=1;
    // SetConsoleCursorPosition(console, {midX, midY});
    // cout<<"/o \\_____";
    // midY += 2;
    // SetConsoleCursorPosition(console, {midX, midY});
    // cout<<"\\__/-=\"=\"`";
    // getch();
}