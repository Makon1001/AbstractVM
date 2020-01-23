//
//  Instructions.hpp
//  AbstractVM
//
//  Created by Manuel Konrath on 19/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#ifndef Instructions_hpp
#define Instructions_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

class Instructions
{
    std::vector<std::string> results;
public :
    std::vector<std::string> split_line_of_instruction(std::string const & line) const;
    bool verif_line_of_instructions(std::vector<std::string> const & results) const;
    int verif_and_execute(std::string const & line);
    void execute(std::string instruction, std::string value="") const;
    void set_results(std::vector<std::string> const & results);
    std::vector<std::string> get_resluts() const;
};
#endif /* Instructions_hpp */
