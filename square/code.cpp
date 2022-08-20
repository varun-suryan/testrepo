#include "code.h"

namespace first{
    int square(int n, int m) {
        return n*m;
    }
}

namespace second{
    int square(int n, int m) {
        return n*n*n+m*m*m;
    }
}
