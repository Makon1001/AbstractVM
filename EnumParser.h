//
//  EnumParser.hpp
//  AbstractVM
//
//  Created by Manuel Konrath on 22/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#ifndef EnumParser_hpp
#define EnumParser_hpp

#include <stdio.h>
#include <string>
#include <map>
#include "Enum.hpp"

using namespace std;

template <typename T> class EnumParser
{
    map<string, T> enumMap;
public:
    EnumParser(){};
    ~EnumParser(){};

    T ParseEnum(const string &value)
    {
        typename map <string, T>::const_iterator iValue = enumMap.find(value);
        if (iValue  == enumMap.end())
            throw runtime_error("erreur de type");
        return iValue->second;
    }
};



template<> EnumParser<eInstructionsListe>::EnumParser()
{
    enumMap["push"] = push_Instruction;
    enumMap["pop"] = pop_Instruction;
    enumMap["dump"] = dump_Instruction;
    enumMap["clear"] = clear_Instruction;
    enumMap["dup"] = dup_Instruction;
    enumMap["swap"] = swap_Instruction;
    enumMap["assert"] = assert_Instruction;
    enumMap["add"] = add_Instruction;
    enumMap["sub"] = sub_Instruction;
    enumMap["mul"] = mul_Instruction;
    enumMap["div"] = div_Instruction;
    enumMap["mod"] = mod_Instruction;
    enumMap["load"] = load_Instruction;
    enumMap["store"] = store_Instruction;
    enumMap["print"] = print_Instruction;
    enumMap["exit"] = exit_Instruction;
};


template<> EnumParser<eOperandType>::EnumParser()
{
    enumMap["int8"] = Int8;
    enumMap["int16"] = Int16;
    enumMap["int32"] = Int32;
    enumMap["float"] = Float;
    enumMap["Double"] = Double;
    enumMap["bigdecimal"] = BigDecimal;
};

#endif /* EnumParser_hpp */
