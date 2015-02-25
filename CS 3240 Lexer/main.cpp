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
vector<char> vec;

int main(int argc, const char * argv[]) {
    char c;
    string TINY = "{\n" //source code
            "A TINY Program\n"
            "CS 3240\n"
            "}\n"
            "\n"
            " read x;\n"
            "     if 0 < x then\n"
            "         fact := 1;\n"
            "         repeat\n"
            "             fact := {embedded comment}fact * x;\n"
            "             x := x - 1\n"
            "         until x = 0;\n"
            "         write fact\n"
            "     end\n"
            " \n"
            "     {}\n";
    
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
                //state = KWD;  //couldn't get the keyword state to work.
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
                else if (c == '=')
                    NULL;
                else
                    cout << "OPR: " << c << endl; //opr check
            }
            break;
/*        case KWD:                //keyword state. Suppose to work for if, then, else, end, repeat, until, read, write
            if(isalpha(c)){
                vec.push_back(c);
            }
            else{
                if(vec.size() == 1)
                    cout << "ID: " << vec[0] << endl;
                else if(vec.size() > 1){
                    cout << "KWD: ";
                    for(int i = 0; i < vec.size(); i++){
                    cout << vec[i];
                    }
                }
                cout << endl;
                vec.clear();
                state = Start;
            }
            break;
 */
        default:
            break;
    }
}