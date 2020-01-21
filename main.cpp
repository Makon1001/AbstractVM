//
//  main.cpp
//  AbstractVM
//
//  Created by Manuel Konrath on 19/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#include <iostream>
#include "Source_Instructions.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Source_Instructions source;
    if(argc == 1){
        source.instruction_from_input();
    } else if (argc == 2){
        source.instruction_from_file(argv[1]);
    } else {
        cout << "To much arguments" << endl;
        return 0;
    }
    
    
    return 0;
}
