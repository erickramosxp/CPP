#pragma once

template <typename T>
void swap(T &src, T &dst) {

    T temp;

    temp = src;
    src = dst;
    dst = temp;
}

template <typename T>
T min(T first, T second) {
    
    if (first < second)
        return (first);
    else
        return (second);
}

template <typename T>
T max(T first, T second) {
    
    if (first > second)
        return (first);
    else
        return (second);
}