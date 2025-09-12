#pragma once
#include <vector>
#include<stack>
#include <string>
#include <cmath>
#include<set>
#include <algorithm>

class Evaluator
{
public:
    Evaluator(const int& varCount, const std :: vector<std :: string>& PostFixexpression);
    void truthValuesGenerator();
    std::vector<std::string> variables;
    std :: vector<std :: vector <bool>> getTruthTable();

private:
    int rows, cols;
    std :: vector <std :: vector<bool> > truthVals;
    std :: vector<std :: string> exp;

    bool evalPostFix(const std :: vector<bool>& rowAssingment) const;
    bool applyOperator(const std :: string& op, bool left, bool right) const;
};
