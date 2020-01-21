//
//  eOperandType.hpp
//  testStack
//
//  Created by Manuel Konrath on 19/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#ifndef eOperandType_hpp
#define eOperandType_hpp

#include <stdio.h>

namespace TypeAbstractVM
{
    typedef enum
    {
        Int8,
        Int16,
        Int32,
        Float,
        Double,
        BigDecimal
    }eOperandType;
}

#endif /* eOperandType_hpp */
