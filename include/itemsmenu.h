#include<windows.h>

void ItemsMenu(){
    system("cls");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO windowInfo;
    GetConsoleScreenBufferInfo(console, &windowInfo);
    cout<<windowInfo.dwSize.X<<endl;
    cout<<windowInfo.dwSize.Y;
    short int CalcRap = windowInfo.dwSize.X - 1;
    SetConsoleCursorPosition(console, {CalcRap, 0});
    short int midY = windowInfo.dwSize.Y%2==0?windowInfo.dwSize.Y/2-1:windowInfo.dwSize.Y/2;
    short int midX = windowInfo.dwSize.X/2;
    for (short int i = 0; i < windowInfo.dwSize.Y; i++){
        SetConsoleCursorPosition(console, {CalcRap, i});
        cout<<"|";
        SetConsoleCursorPosition(console, {0, i});
        cout<<"|";
        if (i==midY) {
            CalcRap = windowInfo.dwSize.X - 4;
            SetConsoleCursorPosition(console, {CalcRap, i});
            cout<<"D ->";
            SetConsoleCursorPosition(console, {0, i});    
            cout<<"<- A";
        }
    }
    midX -= 5;
    SetConsoleCursorPosition(console, {midX, midY});  
    cout<<" __";
    midY +=1;
    SetConsoleCursorPosition(console, {midX, midY});
    cout<<"/o \\_____";
    midY += 2;
    SetConsoleCursorPosition(console, {midX, midY});
    cout<<"\\__/-=\"=\"`";
    getch();
}