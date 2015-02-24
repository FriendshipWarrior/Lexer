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
enum State {Empty, Start, KWD}; //States for source code. KWD is for key words found in ID
State state = Empty;
int main(int argc, const char * argv[]) {
    char c;
    string TINY = "{" //source code
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
    
    while(iss){      //read source code and pass each char through getToken function
        iss >> c;
        getToken(c);
    }
    return 0;
}

void getToken(char c){ //gather tokens from source and display to console
    if(c == '}')       // { } are considered comment brakets and will not be printed
        state = Empty;
    switch(state){
        case Empty:
            if(c == '}')  //'}' signifies the end of a comment and program will continue with business as usual
                state = Start;
            else
            break;
        case Start:      // main case to print tokens
            if(isalpha(c)) //check if letter
                cout << "ID: " << c << endl;
            else if(isdigit(c)) //check if digit
                cout << "NUM: " << c << endl;
            else if(ispunct(c)){ //check if symbol
                if(c == ';')
                    cout << "SEMI: " << c << endl; //semi token check
                else if(c == '{')
                    state = Empty; //comment check
                else if(c == '}')
                    NULL;
                else if(c == ':')
                    cout << "ASSIGN: " << c << '=' << endl; //bit of a cheat, but it works :P
                else
                    cout << "OPR: " << c << endl; //opr check
            }
            break;
        default:
            break;
    }
}