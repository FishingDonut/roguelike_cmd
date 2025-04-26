#include <iostream>

int main() {
    std::string text = "rasbe\arry";
    
    for(char c: text){
        if( c == '\\'){
            std::cout << true;
            continue;
        }
        std::cout << c << std::endl;
    }
    
    return 0;
}
