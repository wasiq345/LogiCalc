#include "../include/evaluator.h"

Evaluator ::Evaluator(int varCount, vector<string> expression)
{
    cols = varCount;
    rows = static_cast<int>(pow(2, varCount));
    exp = expression;
}

void Evaluator ::truthValuesGenerator()
{
    int start;
    int limit;
    for (int i = 1; i <= cols; i++)
    {
        int row = i;
        limit = (pow(2,i)/2)-1;
        start = 0;
        vector<bool> varVals;
        for (int j = 0; j < rows; j++)
        {
            if (j <= limit && j >= start)
            {
                // cout << "false" << endl;
                varVals.push_back(false);
            }
            else
            {
                // cout << "true" << endl;
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

void Evaluator ::printTruthTable()
{
    truthValuesGenerator();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << truthVals[j][i] << "\t";
        }
        cout << endl;
    }
}



