#include<windows.h>

int ItemsMenu(){
    system("cls");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO windowInfo;
    GetConsoleScreenBufferInfo(console, &windowInfo);
    cout<<windowInfo.dwSize.X<<endl;
    cout<<windowInfo.dwSize.Y;
    SetConsoleCursorPosition(console, {windowInfo.dwSize.X-1, 0});
    int midY = windowInfo.dwSize.Y%2==0?windowInfo.dwSize.Y/2-1:windowInfo.dwSize.Y/2;
    int midX = windowInfo.dwSize.X/2;
    for (int i = 0; i < windowInfo.dwSize.Y; i++){
        SetConsoleCursorPosition(console, {windowInfo.dwSize.X-1, i});
        cout<<"|";
        SetConsoleCursorPosition(console, {0, i});
        cout<<"|";
        if (i==midY) {
            SetConsoleCursorPosition(console, {windowInfo.dwSize.X-4, i});
            cout<<"D ->";
            SetConsoleCursorPosition(console, {0, i});    
            cout<<"<- A";
        }
    }
    SetConsoleCursorPosition(console, {midX-5, midY});  
    cout<<" __";
    SetConsoleCursorPosition(console, {midX-5, midY+1});
    cout<<"/o \\_____";
    SetConsoleCursorPosition(console, {midX-5, midY+2});
    cout<<"\\__/-=\"=\"`";
    getch();
}