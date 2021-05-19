#pragma once
#include "math_utils.h"

template <typename T, typename U>
T MathUtils<T, U>::add(T addend1, T addend2) {
    return addend1 + addend2;
}

template <typename T, typename U>
T MathUtils<T, U>::subtract(T minuend, T subtrahend) {
    return minuend - subtrahend;
}

template <typename T, typename U>
T MathUtils<T, U>::multiply(T multiplicand, T multiplier) {
    return multiplicand * multiplier;
}

template <typename T, typename U>
T MathUtils<T, U>::divide(T divisor, T dividend) {
    if (dividend == 0) {
        throw std::invalid_argument("dividend cannot be zero");
    }

    return divisor / dividend;
}
