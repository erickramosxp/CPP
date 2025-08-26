
#pragma once

#include <algorithm>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream> 

template <typename T>
typename T::iterator easyfind(T& container, int nb);

#include "easyfind.tpp"