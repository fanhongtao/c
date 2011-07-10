/**
 * Define a template class
 */
#include <stdio.h>

template <typename T>
class C1 {
public:
    T get() { return t_; }
    void set(T t) { t_ = t; }

private:
    T  t_;
};

int main() {
    C1<int> c;
    c.set(12);
    printf("value: %d\n", c.get());

    return 0;
}
