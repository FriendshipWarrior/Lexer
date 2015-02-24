//
//  main.cpp
//  CS 3240 Lexer
//
//  Created by Dustin Hurst on 2/21/15.
//  Copyright (c) 2015 Dustin Hurst. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
void getToken(char input);
enum State {Empty, Start};
State state = Empty;
int main(int argc, const char * argv[]) {
    char c;
    string TINY = "{"
                  "A TINY Program"
                  "CS 3240"
                  "}"
                  " "
                  " read x;"
                  "     if 0 < x then"
                  "         fact := 1;"
                  "         repeat"
                  "             fact := {embedded comment}fact * x;"
                  "             x := x - 1"
                  "         until x = 0;"
                  "         write fact"
                  "     end"
                  " "
                  "     {}";
    istringstream iss (TINY);
    
    while(iss){
        iss >> c;
        getToken(c);
    }
    return 0;
}

void getToken(char c){
    if(c == '}')
        state = Empty;
    switch(state){
        case Empty:
            if(c == '}')
                state = Start;
            else
            break;
        case Start:
            if(isalpha(c))
                cout << "ID: " << c << endl;
            else if(isdigit(c))
                cout << "NUM: " << c << endl;
            else if(ispunct(c)){
                if(c == ';')
                    cout << "SEMI: " << c << endl;
                else if(c == '{')
                    state = Empty;
                else if(c == '}')
                    NULL;
                else if(c == ':')
                    cout << "ASSIGN: " << c << '=' << endl;
                else
                    cout << "OPR: " << c << endl;
            }
            break;
        default:
            break;
    }
}