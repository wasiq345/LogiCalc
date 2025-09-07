#include "../include/parser.h"

Parser :: Parser(const std :: vector<token>& tokens)
{
    this -> tokens = tokens;
}

int Parser :: precedence(const std :: string& op) const
{
    if(op == "~") return 3;             // Not operator has the highest precedence meaning it'll be evaluated first.
    else if(op == "^") return 2;
    else if(op == "v") return 1;
    else if(op == "->") return 0;
    return -1; 
}

bool Parser :: IsOperator(const std :: string& token) const
{
    return (token == "~" || token == "^" || token == "v" || token == "->");
}

// bool Parser :: IsRightAssociative(const std :: string& op) const
// {
    
// }

std :: vector<token> Parser :: parse() const
{
    std :: vector<token> output;               // Output vector to store the postfix notation
    std :: stack<token> operators;              // Stack to store operators

    for(const auto& token : tokens)
    {
        if(!IsOperator(token)) output.push_back(token);         // If its a varaible, push to vector

        else{
            
            // its a operator
            while(!operators.empty() && precedence(operators.top()) >= precedence(token))
            {
                output.push_back(operators.top());
                operators.pop();
            } 

            operators.push(token);
        }
    }

    // pop the remaining elements in stack
    while(!operators.empty()) output.push_back(operators.top()), operators.pop();
    return output;
}


// dummy main to check compilation 
int main()
{
    std :: vector<token> tokens = {"A", "^", "B", "v", "C", "->", "D"};
    std :: vector<token> tokens2 = {"A", "->", "B", "->", "C"};
    Parser parser(tokens2);
    std :: vector<token> ans = parser.parse();
    for(const auto& t : ans) std :: cout << t << " ";
}
