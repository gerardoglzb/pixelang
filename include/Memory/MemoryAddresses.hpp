#include <iostream>

enum MemoryAddresses {
    GLOBAL_INT=0,
    GLOBAL_FLOAT=2000,
    GLOBAL_STRING=4000,
    GLOBAL_BOOL=6000,

    GLOBAL_TEMP_INT=8000,
    GLOBAL_TEMP_FLOAT=12000,
    GLOBAL_TEMP_STRING=16000,
    GLOBAL_TEMP_BOOL=20000,

    GLOBAL_CTE_INT=24000,
    GLOBAL_CTE_FLOAT=26000,
    GLOBAL_CTE_STRING=28000,
    GLOBAL_CTE_BOOL=30000,


    LOCAL_INT=32000,
    LOCAL_FLOAT=23000,
    LOCAL_STRING=34000,
    LOCAL_BOOL=35000,

    LOCAL_TEMP_INT=36000,
    LOCAL_TEMP_FLOAT=39000,
    LOCAL_TEMP_STRING=42000,
    LOCAL_TEMP_BOOL=45000,

    LOCAL_CTE_INT=48000,
    LOCAL_CTE_FLOAT=49000,
    LOCAL_CTE_STRING=50000,
    LOCAL_CTE_BOOL=51000,

    END_MEMORY=52000
};