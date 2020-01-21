//
//  Factory.hpp
//  AbstractVM
//
//  Created by Manuel Konrath on 21/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#ifndef Factory_hpp
#define Factory_hpp

#include <stdio.h>
#include <string>
#include "IOperand.hpp"
#include "eOperandType.hpp"

class Factory {
    public :
    static IOperand* createOperand (TypeAbstractVM::eOperandType type, const std::string& value);
    IOperand* createInt8(const std::string& value);
    IOperand* createInt16(const std::string& value);
    IOperand* createInt32(const std::string& value);
    IOperand* createFloat(const std::string& value);
    IOperand* createDouble(const std::string& value);
    IOperand* createBigDecimal(const std::string& value);
    

};

#endif /* Factory_hpp */
