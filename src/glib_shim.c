#include "glib_shim.h"

int g_atomic_int_dec_and_test(int* _pi) {
    *_pi -= 1;
    return (_pi == 0);
}

int g_atomic_int_add(int* _pi, int _add) {
    int tmp = *_pi;
    *_pi += _add;
    return tmp;
}
