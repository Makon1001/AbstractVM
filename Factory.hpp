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
#include "Enum.hpp"


class Factory {
    public :
    static IOperand* createOperand(eOperandType type, const std::string& value);
    private :
        static IOperand* createInt8(const std::string& value);
        static IOperand* createInt16(const std::string& value);
        static IOperand* createInt32(const std::string& value);
        static IOperand* createFloat(const std::string& value);
        static IOperand* createDouble(const std::string& value);
        static IOperand* createBigDecimal(const std::string& value);
    

};

#endif /* Factory_hpp */
