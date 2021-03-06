//
//  Source_Instructions.cpp
//  AbstractVM
//
//  Created by Manuel Konrath on 19/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#include "Source_Instructions.hpp"
#include "Instructions.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Source_Instructions::Source_Instructions(){
    
}

int Source_Instructions::instruction_from_input(){
    string line;
    Instructions verif;
    vector<string> results;
    
    do{
        getline(cin, line);
        if(!line.empty()){
            results = verif.split_line_of_instruction(line);
            if(verif.verif_line_of_instructions(results)){
                cout << "OK test" << endl;
            }
        }
    }while(line.compare(";;") != 0);
    return 0;
}

int Source_Instructions::instruction_from_file(std::string const path){
    string line;
    Instructions verif;
    vector<string> results;
    
    ifstream Instruction_File(path.c_str());
    if(Instruction_File){ //tet ouverture du fichier
        while(getline(Instruction_File, line)){
            cout << line << endl;
            results = verif.split_line_of_instruction(line);
            verif.verif_line_of_instructions(results);
        }

        //Executer les instructions
    } else {//le fichier n'est pas ouvert
        cout << "Error : can not open the file.";
    }
    return 0;
}
