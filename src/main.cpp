#include "../include/parser.h"
#include "../include/tokenizer.h"
#include "../include/evaluator.h"
#include <iostream>

int main()
{
    std :: string expression;
    do
    {
        std :: cout << "\t\t--------------------------------------------\n";
        std :: cout << "\t\t\t Propostional Logic \n\t\t\t Evaluator \n";
        std :: cout << "\t\t--------------------------------------------\n";

        std :: cout << "\n\n\t\t Write Expression: " << std :: endl;
        std :: cout << "\t\t Write quit to Exit" << std :: endl;
        std :: getline(std :: cin, expression);
        
        if(expression == "quit") break;
        Tokenizer tokenizer(expression);
        auto tokens = tokenizer.tokenize();
        Parser parser(tokens);
        int varCount = parser.getVariableCount();
        auto PostFixexpression = parser.parse();
        Evaluator evaluator(varCount, PostFixexpression);
        auto truthTable = evaluator.getTruthTable();
        std :: cout << "\n\n\t\t Truth Table \n";
        for(const auto& var : evaluator.variables) std :: cout << var << "\t";
        std :: cout << "Result\n";
        for(const auto& row : truthTable)
        {
            for(const auto& val : row) std :: cout << val << "\t";
            std :: cout << "\n";
        }
        std :: cout << "\n\n";

    } while (true);
}