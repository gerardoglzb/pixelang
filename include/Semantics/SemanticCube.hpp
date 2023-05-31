#include <iostream>
using namespace std;

static int semanticCube(int oper, int type1, int type2) {
    int cube[6][3][3] = {
        {
            {INT_, -1, INT_},
            {FLOAT_, FLOAT_, FLOAT_},
            {BOOL_, -1, BOOL_},
        },
        {
            {INT_, FLOAT_, INT_},
            {FLOAT_, FLOAT_, FLOAT_},
            {INT_, FLOAT_, INT_},
        },
        {
            {INT_, FLOAT_, INT_},
            {FLOAT_, FLOAT_, FLOAT_},
            {INT_, FLOAT_, INT_},
        },
        {
            {INT_, FLOAT_, INT_},
            {FLOAT_, FLOAT_, FLOAT_},
            {INT_, FLOAT_, INT_},
        },
        {
            {FLOAT_, FLOAT_, FLOAT_},
            {FLOAT_, FLOAT_, FLOAT_},
            {FLOAT_, FLOAT_, FLOAT_},
        },
        {
            {INT_, -1, INT_},
            {-1, -1, -1},
            {INT_, -1, INT_},
        },
    };

    if (oper == PRINT_ || oper == RETURN_)
        return 0;

    if (oper > LESSEQ_ || type1 > 2 || type2 > 2) {
        cout << "Error in semantic cube." << endl;
        printf("%i %i %i\n", oper, type1, type2);
        exit(-1);
    }

    return oper < 5 ? cube[oper][type1][type2] : 0;
}