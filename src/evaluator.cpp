#include "../include/evaluator.h"

Evaluator :: Evaluator(int varCount, vector<string> expression){
    cols = varCount;
    rows = pow(2,varCount);
}
