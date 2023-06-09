#include <iostream>
using namespace std;

/*
This method represents the use of a semantic cube, to determine whether an operation is valid.
It takes the operator and the types of the two operands involved, then returns the type of the result.
If the operation is not valid, it'll return a -1.
*/
static int semanticCube(int oper, int type1, int type2) {
    // cout << oper << " " << type1 << " " << type2 << endl;
    int cube[15][4][4] = {
        {
            {INT_, -1, INT_, -1},
            {FLOAT_, FLOAT_, FLOAT_, -1},
            {BOOL_, -1, BOOL_, -1},
            {-1, -1, -1, STRING_},
        },
        {
            {INT_, FLOAT_, INT_, -1},
            {FLOAT_, FLOAT_, FLOAT_, -1},
            {INT_, FLOAT_, INT_, -1},
            {STRING_, STRING_, STRING_, STRING_},
        },
        {
            {INT_, FLOAT_, INT_, -1},
            {FLOAT_, FLOAT_, FLOAT_, -1},
            {INT_, FLOAT_, INT_, -1},
            {-1, -1, -1, -1},
        },
        {
            {INT_, FLOAT_, INT_, -1},
            {FLOAT_, FLOAT_, FLOAT_, -1},
            {INT_, FLOAT_, INT_, -1},
            {-1, -1, -1, -1},
        },
        {
            {INT_, FLOAT_, INT_, -1},
            {FLOAT_, FLOAT_, FLOAT_, -1},
            {INT_, FLOAT_, INT_, -1},
            {-1, -1, -1, -1},
        },
        {
            {INT_, -1, INT_, -1},
            {-1, -1, -1, -1},
            {INT_, -1, INT_, -1},
            {-1, -1, -1, -1},
        },
        {
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {-1, -1, -1, -1},
        },
        {
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {-1, -1, -1, -1},
        },
        {
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {-1, -1, -1, BOOL_},
        },
        {
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {-1, -1, -1, -1},
        },
        {
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {-1, -1, -1, -1},
        },
        {
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {-1, -1, -1, -1},
        },
        {
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {-1, -1, -1, -1},
        },
        {
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {-1, -1, -1, -1},
        },
        {
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {BOOL_, BOOL_, BOOL_, -1},
            {-1, -1, -1, -1},
        },
    };

    if (oper == PRINT_ || oper == RETURN_)
        return INT_;

    if (type1 == VOID_ && type2 == VOID_)
        return VOID_;

    if (oper > LESSEQ_ || type1 > STRING_ || type2 > STRING_) {
        cout << "ERROR: You're trying to perform an operation with operands that are not compatible." << endl;
        exit(-1);
    }

    return oper < LEFTPAR_ ? cube[oper][type1][type2] : BOOL_;
}