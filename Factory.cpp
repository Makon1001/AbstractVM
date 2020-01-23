//
//  Factory.cpp
//  AbstractVM
//
//  Created by Manuel Konrath on 21/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#include "Factory.hpp"

#include "IOperand.hpp"
#include <iostream>
#include <string>
#include "Enum.hpp"


using namespace std;


IOperand* Factory::createInt8(const std::string& value)
{
    IOperand* Operand = nullptr;
    return Operand;
}

IOperand* Factory::createInt16(const std::string& value)
{
    IOperand* Operand = nullptr;
    return Operand;
}

IOperand* Factory::createInt32(const std::string& value)
{
    IOperand* Operand = nullptr;
    return Operand;
}

IOperand* Factory::createFloat(const std::string& value)
{
    IOperand* Operand = nullptr;
    return Operand;
}

IOperand* Factory::createDouble(const std::string& value)
{
    IOperand* Operand = nullptr;
    return Operand;
}

IOperand* Factory::createBigDecimal(const std::string& value)
{
    IOperand* Operand = nullptr;
    return Operand;
}


IOperand* Factory::createOperand(eOperandType type, const std::string& value)
{
    IOperand* Operand;
    
    switch (type)
    {
        case Int8 :
            Operand = createInt8(value);
            break;
        case Int16 :
            Operand = createInt16(value);
            break;
        case Int32 :
            Operand = createInt32(value);
            break;
        case Float :
            Operand = createFloat(value);
            break;
        case Double :
            Operand = createDouble(value);
            break;
        case BigDecimal :
            Operand = createBigDecimal(value);
            break;
        default :
            cout << "Erreur de type" << endl;
    }
    return Operand;
}
