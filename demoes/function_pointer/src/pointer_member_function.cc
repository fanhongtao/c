/**
 * Thie is a demo for pointer to member functin.
 */
#include <stdio.h>

// define a class
class Class1 {
public:
    void test(int a) {
        printf("param %d\n", a);
    }
};

// define a pointer type
typedef void (Class1::*func_pointer)(int);

typedef struct {
    void (Class1::*ptr)(int);
} Struct1;

int main() {
    Class1 c1;

    func_pointer pointer = &Class1::test;
    (c1.*pointer)(1);

    Struct1 s1;
    s1.ptr = &Class1::test;
    (c1.*s1.ptr)(2);

    return 0;
}
