//
//  IOperand.hpp
//  AbstractVM
//
//  Created by Manuel Konrath on 21/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#ifndef IOperand_hpp
#define IOperand_hpp

#include <stdio.h>

class IOperand
{
    public :
        virtual std::string toString() const = 0; // string that represents the instance
        virtual eOperandType getType() const = 0; // returns the type of instance
        virtual IOperand* operator+(const IOperand& rhs) const = 0; // sum
        virtual IOperand* operator-(const IOperand& rhs) const = 0; // difference
        virtual IOperand* operator*(const IOperand& rhs) const = 0; // product
        virtual IOperand* operator/(const IOperand& rhs) const = 0; // quotient
        virtual IOperand* operator%(const IOperand& rhs) const = 0; // modulo
        virtual ~IOperand() {}
};

#endif /* IOperand_hpp */
