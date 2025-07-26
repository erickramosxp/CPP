#pragma once

template <typename T, typename Func>
void iter(T *adArray, unsigned int len, Func f) {

    for (unsigned int i = 0; i < len; i++) {
        f(adArray[i]);
    }
}