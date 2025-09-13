#include "../include/parser.h"
#include "../include/tokenizer.h"
#include "../include/evaluator.h"
#include "../include/json.hpp"
#include <iostream>

using json = nlohmann :: json;

int main(int argc, char* argv[])
{
    std :: string expression;
    if(argc < 2){
     std :: cerr << "Usage: " << argv[0] << " <expression> " << std :: endl;
     return 1;
    }

    for (int i = 1; i < argc; i++) {
    if (i > 1) expression += " ";
    expression += argv[i];
}

        Tokenizer tokenizer(expression);
        auto tokens = tokenizer.tokenize();
        Parser parser(tokens);
        int varCount = parser.getVariableCount();
        auto PostFixexpression = parser.parse();
        Evaluator evaluator(varCount, PostFixexpression);
        auto truthTable = evaluator.getTruthTable();

        json output;
        output["variables"] = evaluator.variables;
        output["rows"] = truthTable;
        output["classification"] = evaluator.getClassification();

        std :: cout << output.dump() << std :: endl;
}