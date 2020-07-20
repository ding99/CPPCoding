// pch.cpp: source file corresponding to the pre-compiled header
#include <iostream>
#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.

int add(int a, int b) { return a + b; }
void add1() { std::cout << add(2, 3) << std::endl; }
void add2() { std::cout << add(5, 6) << std::endl; }
