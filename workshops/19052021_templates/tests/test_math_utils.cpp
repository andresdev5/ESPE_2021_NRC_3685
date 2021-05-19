#include "../math_utils.h"

void test_integers() {
    int result = MathUtils<int>::add(2, 8);
    static_assert(std::is_same<decltype(result), int>::value, "expected int type");
}

int main() {
    test_integers();
}