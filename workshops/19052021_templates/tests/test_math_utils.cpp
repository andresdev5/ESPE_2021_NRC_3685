#include "../math_utils.h"

void check_return_type() {
    if (!std::is_same<decltype(MathUtils<int>::add(2, 8)), int>::value) {
        throw std::runtime_error("expected int type");
    }
}

void check_integer() {
    int result = MathUtils<int>::add(10, 5);

    if (result != 15) {
        throw std::runtime_error("check_integer(): invalid add() result");
    }

    result = MathUtils<int>::subtract(5, 4);

    if (result != 1) {
        throw std::runtime_error("check_integer(): invalid subtract() result");
    }

    result = MathUtils<int>::multiply(2, 5);

    if (result != 10) {
        throw std::runtime_error("check_integer(): invalid multiply() result");
    }

    result = MathUtils<int>::divide(8, 2);

    if (result != 4) {
        throw std::runtime_error("check_integer(): invalid divide() result");
    }
}

void check_float() {
    float result = MathUtils<float>::add(2.5, 2.5);

    if (result != 5.f) {
        throw std::runtime_error("check_float(): invalid add() result");
    }

    result = MathUtils<float>::subtract(5.4, 1.3);

    if (result != 4.1) {
        throw std::runtime_error("check_float(): invalid subtract() result");
    }

    result = MathUtils<float>::multiply(1.5, 3);

    if (result != 4.5) {
        throw std::runtime_error("check_float(): invalid multiply() result");
    }

    result = MathUtils<float>::divide(9, 1.5);

    if (result != 6) {
        throw std::runtime_error("check_float(): invalid divide() result");
    }
}

void check_double() {
    double result = MathUtils<double>::add(9.4444, 2.3333333333333);

    if (result != (9.4444 + 2.3333333333333)) {
        throw std::runtime_error("check_double(): invalid add() result");
    }
}

int main() {
    check_return_type();
    check_integer();
    check_float();
    check_double();
}