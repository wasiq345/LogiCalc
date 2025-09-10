#include "../include/evaluator.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    Evaluator e(4, {"A", "B", "C"});
    e.printTruthTable();
    return 0;
}