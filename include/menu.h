#include<conio.h>
#include<iostream>
#include<locale.h>
using namespace std;
void cleanmenu(short int pos){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    cout<<"Iniciar   \n";
    cout<<"Informações   \n";
    cout<<"Sair   \n";
    cout<<"Você pode precionar ESC para sair e ENTER para selecionar;)";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, pos});
}
int menu(/* args */)
{
    int option = 0;
    short int position = 0;
    do
    {   
        if (option == 0){
            cleanmenu(0);
        }
        switch (position)
        {
        case 0:
            cleanmenu(position);
            cout<<"> Iniciar \n";
            break;
        case 1:
            cleanmenu(position);
            cout<<"> Informações \n";
            break;
        case 2:
            cleanmenu(position);
            cout<<"> Sair \n";    
        break;
        default:
            break;
        }

        option = getch();
        switch (option)
        {
        case 72: case 'w':
            //cout<<"Up";
            position<=0?position=2:position--;
            break;
        case 80: case 's':
            if (position>=2){
                position=0;
            }else{
                position++;
            }
            
            break;
        case 75: case 'a':
            //cout<<"Left";
            break;
        case 77: case 'd': case 13:
            //enter/select option
            switch (position){
            case 0:
                //game();
                break;
            case 1:
                //info();
                break;
            case 2:
                return 2;    
            break;
        }
        break;
        default:
        cout<<option;
        break;
        }
    } while (option != 27);
    
}