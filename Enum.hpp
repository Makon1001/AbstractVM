//
//  Enum.hpp
//  AbstractVM
//
//  Created by Manuel Konrath on 23/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#ifndef Enum_h
#define Enum_h

typedef enum
{
    push_Instruction,
    pop_Instruction,
    dump_Instruction,
    clear_Instruction,
    dup_Instruction,
    swap_Instruction,
    assert_Instruction,
    add_Instruction,
    sub_Instruction,
    mul_Instruction,
    div_Instruction,
    mod_Instruction,
    load_Instruction,
    store_Instruction,
    print_Instruction,
    exit_Instruction,
}eInstructionsListe;


typedef enum
{
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal
}eOperandType;

#endif /* Enum_h */
