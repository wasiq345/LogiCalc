#include "../include/evaluator.h"

Evaluator :: Evaluator(const int& varCount, const std :: vector<std :: string>& PostFixexpression)
{
    for (const auto& token : PostFixexpression)
    {
        if (isalpha(token[0]) && std::find(variables.begin(), variables.end(), token) == variables.end() && token != "v")
        {
            variables.push_back(token);
        }
    }
    cols = varCount;
    rows = static_cast<int>(pow(2, varCount));
    exp = PostFixexpression;
}

bool Evaluator :: applyOperator(const std :: string& op, bool left, bool right) const
{
    if (op == "^") return left && right;        // AND
    if (op == "v") return left || right;        // OR
    if (op == "->") return (!left) || right;    // Implication
    if (op == "<->") return (left == right);    // Biconditional
    return false; // fallback
}

void Evaluator :: truthValuesGenerator()
{
    int start;
    int limit;
    for (int i = 1; i <= variables.size(); i++)
    {
        int row = i;
        limit = (pow(2,i)/2)-1;
        start = 0;
        std :: vector<bool> varVals;
        for (int j = 0; j < rows; j++)
        {
            if (j <= limit && j >= start)
            {
                varVals.push_back(false);
            }
            else
            {
                varVals.push_back(true);
                if (j > limit)
                {
                    limit += static_cast<int>(pow(2, row));
                    start += static_cast<int>(pow(2, row));
                }
            }
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


// dummy main to check results

int main() {
    Evaluator e(2, {"A", "B","<->"}); // Represents the expression (A ^ B) v C
    auto table = e.getTruthTable();
    for(const auto& var : e.variables) std :: cout << var << " ";
    std :: cout << "| Result\n";
    std :: cout << "--------------\n";
    for(const auto& row : table)
    {
        for(size_t i = 0; i < row.size(); i++)
        {
            std :: cout << row[i] << " ";
            if(i == row.size() - 2) std :: cout << "| ";
        }
        std :: cout << "\n";
    }
    return 0;
}

