char direction[4]={'|','/','-','\\'};
    int loaded = 0;
    for(int i = 0; i < 100; i++){
        if (loaded >= 4){
            loaded = 0;
        }else{
            loaded++;
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        cout<<direction[loaded];
        Sleep(10);
    }