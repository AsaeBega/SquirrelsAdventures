#include "DISCLIENT.h"
#include <fstream>
#include <string>
#include<iostream>

int main() {
    std::ifstream token("C:\\Users\\Squirrel\\source\\repos\\SquirrelsAdventures\\SquirrelsAdventures\\token.txt");
    std::string token_str;
    if(token.is_open())
        std::getline(token, token_str);
    DSClient client(token_str, 2);
    //token_str.clear();
    token.close();
    client.run();
}