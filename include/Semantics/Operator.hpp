#include <iostream>

/*
Represents all possible operators.
*/
enum Operator {
    EQUALS_,
    ADD_,
    SUB_,
    MULTI_,
    DIV_,
    MOD_,
    GREATER_,
    LESS_, // TODO: no strings for this
    EQUALTO_,
    NOTEQUAL_,
    AND_,
    OR_,
    NOT_,
    GREATEREQ_,
    LESSEQ_,
    LEFTPAR_,
    RIGHTPAR_,
    GOTOF_,
    GOTO_,
    GOSUB_,
    ERA_,
    PARAM_,
    ENDFUNC_,
    PRINT_,
    RETURN_,
    END_,
    VERIFY_,
    FAKEBOT_,
    EXPO_, // TODO: expo
    INPUT_,
    IPARAM_,
    OPEN_,
    SAVE_,
    GRAYSCALE_,
    BANDW_,
    CHANGECOLOR_,
    HFLIP_,
    VFLIP_,
    CROP_,
};