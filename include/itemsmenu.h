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
    string line;
    size_t pos = 0, newPos;
    // Imprime os itens
    while ((newPos = art.find('\n', pos)) != string::npos)
    {
        counter++;
        line = art.substr(pos, newPos - pos);
        SetConsoleCursorPosition(console, { midX, (SHORT)(midY + lineOffset) });
        cout << line;
        pos = newPos + 1;
        lineOffset++;
    }
    
    
}
void consumablesSound() {
    Beep(450, 40);
    Sleep(30);
    Beep(400, 40);
    Sleep(30);
    Beep(350, 60);
    Sleep(30);
    Beep(300, 70);
}
void ClearDescription(int midY, CONSOLE_SCREEN_BUFFER_INFO windowInfo){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    for (unsigned short int i = 0; i < 3; i++) // Imprime a descrição do item
        {
            SetConsoleCursorPosition(console, {1, (SHORT)(midY+21+i)});
            cout<<"                                                                                                        ";
        }
        SetConsoleCursorPosition(console, {1, (SHORT)(windowInfo.dwSize.Y - 2)});
        cout<<"                                                                                                             ";
        SetConsoleCursorPosition(console, {1, (SHORT)(windowInfo.dwSize.Y - 1)});
        cout<<"                                                                                                             ";
    }
void OrganizationInventory(Inventory &inventory, short int move){
    for(int i = move+1; i < inventory.size + 1; i++){
        inventory.items[i-1] = inventory.items[i];
    }
    inventory.size--;
}
void AllItems(Inventory &inventory){
    Items sword;
    // sword.durability = 100; // Para uma possível atualização futura
    sword.quantity = 1;
    sword.damage = 10;
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
    // Items chest;
//     chest.art = "         __________\n"
// "        /\\____;;___\\\n"
// "       | /         /\n"
// "       `. ())oo() .\n"
// "        |\\(%()*^^()^\\\n"
// "        | |-%-------|\n"
// "        \\ | %  ))   |\n"
// "         \\|%________|\n";
//     chest.midX = 21/2;
    Items potion;
    potion.type = Items::consumables;
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
    apple.type = Items::consumables;
    apple.art = "     ,--./,-.\n"
"    / #      \\\n"
"   |          |\n"
"    \\        /   \n"
"     `._,._,'\n";
    apple.midX = 15/2;
    inventory.items[2]=apple;
    Items shield;
    // shield.durability = 100; // Para uma possível atualização possível
    shield.quantity=1;
    shield.type = Items::armor;
    shield.art = "|\\===============/|\n"
                 "| \\_____________/ |\n"
                 "|      _____      |\n"
                 "|     |     |     |\n"
                 "|     |     |     |\n"
                 "|  ====     ====  |\n"
                 "|  ||         ||  |\n"
                 "|  ||         ||  |\n"
                 "|  ====     ====  |\n"
                 "|    ||     ||    |\n"
                 "|    ||     ||    |\n"
                 "|    ||     ||    |\n"
                 "|    ||     ||    |\n"
                 "|    =========    |\n"
                 "|=================|\n";
    shield.midX = 19/2;
    shield.midY = 15/2;
    inventory.items[3] = shield;
    inventory.size = 4;
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
void ItemsMenu(Inventory &inventory, Player &player){
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
    midX -= 20/2;
    midY -= 19/2;
    SetConsoleCursorPosition(console, {midX, midY});  
    short int sim = 0;
    int input;
    int move = 0;
    do
    {   
        input = getch();
        switch (input)
        {
        case 'x': case 'X':
            if(inventory.items[move].type != Items::empty){
                SetConsoleCursorPosition(console, {1, (SHORT)(windowInfo.dwSize.Y - 2)});
                cout << "Esse item é importante, deseja jogar fora mesmo?    S ou N";
                sim = getch();
                switch (sim){
                    case 's' : case 'S':
                    {
                        OrganizationInventory(inventory,move);
                        Draw(clearString,30);
                        ClearDescription(midY,windowInfo);
                        move > 1 ? move-- : move = 0;
                    }
                    case 'n' : case 'N':
                    break;
                }
            }
        break;
        case 'c': case 'C':
            if(inventory.items[move].type == Items::consumables){
                player.health += inventory.items[move].heal;
                player.health > 100 ? player.health = 100 : player.health;
                OrganizationInventory(inventory,move);
                Draw(clearString,30);
                ClearDescription(midY,windowInfo);
                move > 1 ? move-- : move = 0;
    
                consumablesSound();
            }else{
                SetConsoleCursorPosition(console, {1, (SHORT)(windowInfo.dwSize.Y - 2)});
                cout << "Esse item não é consumível";
                break;
            }
        break;
        case 'd': case 77:
                move > inventory.size - 2 ? move = 0 : move++;
            break;
        case 'a': case 75:
                if(inventory.size > 0) move < 1 ? move = inventory.size - 1 : move--;
            break;
        }
        // AllItems(inventory);
        SetConsoleCursorPosition(console, {midX, (SHORT)(midY+10)});
        Draw(clearString,30);
        ClearDescription(midY,windowInfo);
        if (inventory.items[move].type == Items::empty)
        {
            inventory.items[move].description[0]="Você encontrou o lendário item do nada absoluto!";
            inventory.items[move].description[1]="...que não faz nada mesmo.";
            inventory.items[move].description[2]="(Slot vazio.)";
        }else{
        Draw(inventory.items[move].art,inventory.items[move].midX);
        }
        SetConsoleCursorPosition(console, {1, (SHORT)(midY+9+11)});
        for (unsigned short int i = 0; i < windowInfo.dwSize.X - 2; i++) // Imprime a linha entre o item e a descrição
        {
            cout<<"-";
        }
        for (unsigned short int i = 0; i < 3; i++) // Imprime a descrição do item
        {
            SetConsoleCursorPosition(console, {1, (SHORT)(midY+21+i)});
            cout<<inventory.items[move].description[i];
        }
        SetConsoleCursorPosition(console, {1, (SHORT)(windowInfo.dwSize.Y - 1)});
        if(inventory.items[move].type == Items::consumables){
            cout << " Pressione C para consumir.";
        }else if(inventory.items[move].type != Items::empty){
            cout << " Pressione X para descartar.";
        }
    } while (input != 27);
    system("cls");
}