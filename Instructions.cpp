//
//  Instructions.cpp
//  AbstractVM
//
//  Created by Manuel Konrath on 19/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#include "Instructions.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <array>
#include <algorithm>
#include <regex>

using namespace std;

vector<string> Instructions::split_line_of_instruction(string const line) const
{
    std::istringstream iss(line);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());
    return results;
}

bool Instructions::verif_line_of_instructions(vector<string> const results) const
{
    bool test_word_instruction(false);
    bool test_value_instruction(false);
    regex value("int8\\([-]?[0-9]+\\)|int16\\([-]?[0-9]+\\)|int32\\([-]?[0-9]+\\)|float\\([-]?[0-9]+.[0-9]+\\)|double\\([-]?[0-9]+.[0-9]+\\)|bigdecimal\\([-]?[0-9]+.[0-9]+\\)");
    array<string, 16> instructions_list {{
        "push",
        "pop",
        "dump",
        "clear",
        "dup",
        "swap",
        "assert",
        "add",
        "sub",
        "mul",
        "div",
        "mod",
        "load",
        "store",
        "print",
        "exit"
    }};
    
    //Verifie si le premier mot de l'instruction est correct
    for(int i(0); i<17; i++){
        if(results[0] == instructions_list[i]){
            test_word_instruction = true;
        }
    }
    
    if (test_word_instruction == false){
        cout << "Syntax Error" << endl;
    }
    
    //Verifie si une valeur est correctement donnée pour les instructions suivante :
    if(results[0] == "push" || results[0] == "assert" || results[0] == "load" || results[0] == "store" ){
        if(results.size() > 1 && regex_match(results[1], value)){
            test_value_instruction = true;
            return test_word_instruction && test_value_instruction;
        } else if (results.size() <= 1){
            test_value_instruction = false;
            cout << "Syntax Error : not enough arguments, you must pass a value for this instruction : \""<< results[0] <<"\"."<< endl;
            return test_word_instruction && test_value_instruction;
        } else {
            test_value_instruction = false;
            cout << "Syntax Error : you must pass a valide value for this instruction : \""<< results[0] <<"\"., try int8(v), int16(v), int32(v), float(z), double(z) or bigdecimal(z)"<< endl;
            return test_word_instruction && test_value_instruction;
        }
        
    }
    return test_word_instruction;
}
