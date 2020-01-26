//
//  Source_Instructions.hpp
//  AbstractVM
//
//  Created by Manuel Konrath on 19/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#ifndef Source_Instructions_hpp
#define Source_Instructions_hpp

#include <stdio.h>
#include <string>
#include "IOperand.hpp"
#include <stack>

class Source_Instructions
{
    public :
    Source_Instructions();
    ~Source_Instructions();
    int instruction_from_input();
    int instruction_from_file(std::string const path);
    private:
    std::stack<IOperand const *> stack;
};
#endif /* Source_Instructions_hpp */
