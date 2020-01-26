//
//  Instructions.cpp
//  AbstractVM
//
//  Created by Manuel Konrath on 19/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#include "Instructions.hpp"
#include "EnumParser.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <array>
#include <algorithm>
#include <regex>
#include <stack>
#include "TOperand.hpp"
#include "Factory.hpp"

using namespace std;

Instructions::Instructions(){}
Instructions::~Instructions(){}

vector<string> Instructions::split_line_of_instruction(string const & line) const
{
    std::istringstream iss(line);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());
    return results;
}

bool Instructions::verif_line_of_instructions(vector<string> const & results) const
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



/*void Instructions::push(IOperand const *operand, )
{
    stack.push(operand);
}*/




void Instructions::execute(string instruction, string type, string value) const
{
    EnumParser<eInstructionsListe> InstructionParser;
    eInstructionsListe index_of_instruction = InstructionParser.ParseEnum(instruction);
    
    switch (index_of_instruction){
        case push_Instruction :
            cout << "push" << endl;
            cout << "type : " << type << endl;
            cout << "value : " << value << endl;
        break;
        case pop_Instruction :
            cout << "pop" << endl;
        break;
        case dump_Instruction :
            cout << "dump" << endl;
        break;
        case clear_Instruction :
            cout << "clear" << endl;
        break;
        case swap_Instruction :
            cout << "swap" << endl;
        break;
        case assert_Instruction :
            cout << "assert" << endl;
            cout << "type : " << type << endl;
             cout << "value : " << value << endl;
        break;
        case add_Instruction :
            cout << "add" << endl;
        break;
        case sub_Instruction :
            cout << "sub" << endl;
        break;
        case mul_Instruction :
            cout << "mul" << endl;
        break;
        case div_Instruction :
            cout << "div" << endl;
        break;
        case mod_Instruction :
            cout << "mod" << endl;
        break;
        case load_Instruction :
            cout << "load" << endl;
            cout << "type : " << type << endl;
             cout << "value : " << value << endl;
        break;
        case store_Instruction :
            cout << "store" << endl;
            cout << "type : " << type << endl;
             cout << "value : " << value << endl;
        break;
        case print_Instruction :
            cout << "print" << endl;
        break;
        case exit_Instruction :
            cout << "exit" << endl;
        break;
        default:
        break;
    }
}

vector<string> Instructions::splitTypeValue(vector<string>& results) const
{
    vector<string> splitInstruction;
    splitInstruction.push_back(results[0]);
    const string s = results[1];
    
    regex rgx1("int8|int16|int32|float|double|bigdecimal");
    regex rgx2("\\([-]?[0-9]+\\)");
    regex rgx3("[-]?[0-9]+");
    regex rgx4("[-]?[0-9]+.[0-9]+");
    smatch match;
    
    if (std::regex_search(s.begin(), s.end(), match, rgx1))
        splitInstruction.push_back(match[0]);
    
    if ((splitInstruction[1]=="int8"||splitInstruction[1]=="int16"||splitInstruction[1]=="int32")&& regex_search(s.begin(), s.end(), match, rgx2)){
        const string v = match[0];
        if (std::regex_search(v.begin(), v.end(), match, rgx3)){
            splitInstruction.push_back(match[0]);
        }
    }
    if ((splitInstruction[1]=="float"||splitInstruction[1]=="double"||splitInstruction[1]=="bigdecimal")&& std::regex_search(s.begin(), s.end(), match, rgx4)){
        splitInstruction.push_back(match[0]);}
    return splitInstruction;
}


int Instructions::verif_and_execute(std::string const & line)
{
    this->set_results(this->split_line_of_instruction(line));
    vector<string> results(get_resluts());
    
    if(results[0]==";;"){
        return 0;
    }else if(verif_line_of_instructions(results)){
        if (results.size() <= 1){
            execute(results[0]);
        }else {
            this->set_results(this->splitTypeValue(results));
            results=get_resluts();
            execute(results[0], results[1], results[2]);
        }
    } else {
        cout << "Instruction non valide" << endl;
    }
    return 0;
}

void Instructions::set_results(std::vector<std::string>const & results){
    this->results = results;
}

vector<string> Instructions::get_resluts() const{
    return this->results;
}
