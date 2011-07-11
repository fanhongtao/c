#include "gtest/gtest.h"
#include "common.h"

class C1 {
public:
    ~C1() {
        count++;
    }
    static int count;
};

int C1::count = 0;


/**
 * Test DELETE macro, it should call the destructor 1 time.
 */
TEST(Common, delete_one) {
    int * pi = new int;
    DELETE(pi);

    C1::count = 0;
    C1 * pc = new C1;
    DELETE(pc);
    EXPECT_EQ(1, C1::count);
}

/**
 * Test DELETE_A macro, it should call the destructor num times.
 */
TEST(Common, delete_array) {
    int * pi = new int[10];
    DELETE_A(pi);

    int num = 3;
    C1::count = 0;
    C1 * pc = new C1[num];
    DELETE_A(pc);
    EXPECT_EQ(num, C1::count);
}
