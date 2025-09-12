#include "../include/evaluator.h"

Evaluator :: Evaluator(const int& varCount, const std :: vector<std :: string>& PostFixexpression)
{
     std::set<std::string> variableSet;
    for (const auto& token : PostFixexpression)
    {
        if (isalpha(token[0]) && std::find(variables.begin(), variables.end(), token) == variables.end() && token != "v")
        {
             variableSet.insert(token);
        }
    }
    variables.assign(variableSet.begin(), variableSet.end());
    cols = variables.size();
    rows = static_cast<int>(pow(2, varCount));
    exp = PostFixexpression;
}

bool Evaluator :: applyOperator(const std :: string& op, bool left, bool right) const
{
    if (op == "^") return left && right;        // AND
    if (op == "|") return left || right;        // OR
    if (op == "->") return (!left) || right;    // Implication
    if (op == "<->") return (left == right);    // Biconditional
    return false;
}

void Evaluator :: truthValuesGenerator()
{ 
        truthVals.clear();
        int numVars = variables.size();
        rows = pow(2, numVars);
        
        // Generate truth values for each variable
        for (int varIndex = 0; varIndex < numVars; varIndex++) {
            std::vector<bool> varVals;
            int cycleLength = pow(2,numVars - varIndex - 1);
            
            for (int row = 0; row < rows; row++) {
                // Determine if this row should be true or false for this variable
                bool value = (row / cycleLength) % 2;
                varVals.push_back(value);
            }
            truthVals.push_back(varVals);
        }
}

bool Evaluator :: evalPostFix(const std :: vector<bool>& rowAssingment) const
{
    std :: stack <bool> st;

    for(const auto& token : exp)
    {
        if(isalpha(token[0]))        // Its a variable 
        {
            auto it = std :: find(variables.begin(), variables.end(), token);
            if(it != variables.end()) 
            {
                int idx = std :: distance(variables.begin(), it);
                st.push(rowAssingment[idx]);
            }
        }

        else if(token == "~")        // if its unary operator
        {
            bool val = st.top(); st.pop();
            st.push(!val);
        }

        else               
        {
            bool rhs = st.top(); st.pop();
            bool lhs = st.top(); st.pop();
            st.push(applyOperator(token, lhs, rhs));
        }
    }

    return st.top();
}

std :: vector<std :: vector <bool>>  Evaluator :: getTruthTable()
{
    truthValuesGenerator();

    std::vector<std::vector<bool>> truthTable;

    for(int i = 0; i < rows; ++i)
    {
        std :: vector<bool> rowAssignment;

        for(int j = 0; j < cols; ++j)  rowAssignment.push_back(truthVals[j][i]);

        bool result = evalPostFix(rowAssignment);

        rowAssignment.push_back(result);
        truthTable.push_back(rowAssignment);
    }
    return truthTable;
}

