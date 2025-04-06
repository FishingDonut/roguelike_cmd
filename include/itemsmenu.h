#include<windows.h>
#include<string.h>
void Draw(string art,short int startX){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    short int midX = consoleWidth / 2 - startX;
    int midY = consoleHeight / 2 - 10;
    int counter = 0;
    int lineOffset = 0;
    std::string line;
    size_t pos = 0, newPos;
    while ((newPos = art.find('\n', pos)) != std::string::npos)
    {
        counter++;
        line = art.substr(pos, newPos - pos);
        SetConsoleCursorPosition(console, { midX, (SHORT)(midY + lineOffset) });
        std::cout << line;
        pos = newPos + 1;
        lineOffset++;
    }
    
    
}
void AllItems(Inventory &inventory){
    Items sword;
    sword.durability = 100;
    sword.quantity = 1;
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
    Items chest;
    chest.art = "         __________\n"
"        /\\____;;___\\\n"
"       | /         /\n"
"       `. ())oo() .\n"
"        |\\(%()*^^()^\\\n"
"        | |-%-------|\n"
"        \\ | %  ))   |\n"
"         \\|%________|\n";
    chest.midX = 21/2;
    Items potion;
    potion.type = Items::potion;
    potion.art = 
    "   _\n"
    "  |=|\n"
    "  | |\n"
    "  | |\n"
    " /   \\\n"
    ".     .\n"
    "|-----|\n"
    "|     |\n"
    "|-----|\n";
    potion.midX = 7/2;
    potion.midY = 10;
    inventory.items[1] = potion;
    Items apple;
    apple.type = Items::key;
    apple.art = "     ,--./,-.\n"
"    / #      \\\n"
"   |          |\n"
"    \\        /   \n"
"     `._,._,'\n";
    apple.midX = 15/2;
    inventory.items[2]=apple;
    inventory.size = 3;
    // Items shield;
    // shield.durability = 100;
    // shield.quantity=1;
    // shield.type = Items::armor;
    // shield.art = "           _ . - = - . _\n"
    //     "       . \"  \\  \\   /  /  \" .\n"
    //     "     ,  \\                 /  .\n"
    //     "   . \\   _,.--~=~\"~=~--.._   / .\n"
    //     "  ;  _.-\"  / \\ !   ! / \\  \"-._  .\n"
    //     " / ,\"     / ,` .---. `, \\     \". \\\n"
    //     "/.'   `~  |   /:::::\\   |  ~`   '.\\\n"
    //     "\\`.  `~   |   \\:::::/   | ~`  ~ .'/\n"
    //     " \\ `.  `~ \\ `, `~~~' ,` /   ~`.' /\n"
    //     "  .  \"-._  \\ / !   ! \\ /  _.-\"  .\n"
    //     "   ./    \"=~~.._  _..~~=`\"    \\.\n"
    //     "     ,/         \"\"          \\,\n"
    //     "       . _/             \\_ .\n"
    //     "          \" - ./. .\\. - \"\n";
    //     sword.midX = 0;
    //     sword.midY = 19/2;
    //     inventory.items[1] = shield;
}
string clearString = "                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n"
"                                             \n";
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

    int input;
    int move = 0;
    do
    {   
        input = getch();
        switch (input)
        {
        case 'd': case 77:
                move >= p.inventory.size - 1 ? move = 0 : move++;
            break;
        case 'a': case 75:
                move <= 0 ? move = p.inventory.size - 1 : move--;
            break;
        }
        
        SetConsoleCursorPosition(console, {midX, (SHORT)(midY+10)});
        Draw(clearString,30);
        Draw(p.inventory.items[move].art,p.inventory.items[move].midX);

    } while (input != 27);


    
    
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