
#include "debug.h"

struct s{
    s(){};
    static int i;
    void f(void);
};

void s::f()
{
TEST
}

#include <string.h>

int main ()
{
    struct s t;
    struct s u;

TESTn(sizeof(struct s))
TESTn(sizeof(t))
    memcpy(&t, &u, sizeof(struct s));
    t.f();
}