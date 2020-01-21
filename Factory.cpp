//
//  Factory.cpp
//  AbstractVM
//
//  Created by Manuel Konrath on 21/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#include "Factory.hpp"
#include "eOperandType.hpp"
#include "IOperand.hpp"
#include <iostream>
#include <string>


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


IOperand* Factory::createOperand (TypeAbstractVM::eOperandType type, const std::string& value)
{
    IOperand* Operand;
    
    switch (type)
    {
        case TypeAbstractVM::Int8 :
            
            break;
        case TypeAbstractVM::Int16 :
            
            break;
        case TypeAbstractVM::Int32 :
            
            break;
        case TypeAbstractVM::Float :
            
            break;
        case TypeAbstractVM::Double :
            
            break;
        case TypeAbstractVM::BigDecimal :
            
            break;
        default :
            cout << "Erreur de type" << endl;
    }
    return Operand;
}
