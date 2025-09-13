#include "../include/parser.h"
#include "../include/tokenizer.h"
#include "../include/evaluator.h"
#include "../include/json.hpp"
#include <iostream>

using json = nlohmann :: json;

int main(int argc, char* argv[])
{
    std :: string expression = argv[1];
    if(argc < 2){
     std :: cerr << "Usage: " << argv[0] << " <expression> " << std :: endl;
     return 1;
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

        std :: cout << output.dump() << std :: endl;
}