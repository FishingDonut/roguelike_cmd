#include<iostream>
#include<conio.h>
#include<windows.h>
#include "./include/menu.h"
using namespace std;
int key;
int main(){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    system("cls");
    if(menu() == 1){
        system("cls");
        return 0;
    }
}