#include "../include/parser.h"

Parser :: Parser(const std :: vector<token>& tokens)
{
    this -> tokens = tokens;
}

int Parser :: precedence(const std :: string& op) const
{
    if(op == "~") return 3;             // Not operator has the highest precedence meaning it'll be evaluated first.
    else if(op == "^") return 2;
    else if(op == "|") return 1;
    else if(op == "->") return 0;
    return -1; 
}

bool Parser :: IsOperator(const std :: string& token) const
{
    return (token == "~" || token == "^" || token == "|" || token == "->" || token == "(" || token == ")");
}

bool Parser :: IsRightAssociative(const std :: string& op) const
{
    return (op == "->" || op == "<->");
}

int Parser :: getVariableCount()
{
    for(const auto& token : tokens) if(!IsOperator(token)) VariableCount++;
    return VariableCount;
}

std :: vector<token> Parser :: parse() const
{
    std :: vector<token> output;               // Output vector to store the postfix notation
    std :: stack<token> operators;              // Stack to store operators

    for(const auto& token : tokens)
    {
        if(!IsOperator(token)) output.push_back(token);         // If its a varaible, push to vector

        else{                                                  

            if(token == "(") operators.push(token);             // handle brackets carefully like (p -> q) v R


            else if(token == ")")                                   // pop until we dont find the matching bracket
            {
                while(!operators.empty() && operators.top() != "(")                  
                {
                    output.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();                                // pop the remaining opening bracket 
            }


            else                    // its an operator other than brackets
            {
                while(!operators.empty() && precedence(operators.top()) >= precedence(token) && operators.top() != "(")
                {
                    output.push_back(operators.top());
                    operators.pop();
                } 
                operators.push(token);
            }
        }
    }

    // pop the remaining elements in stack
    while(!operators.empty()) output.push_back(operators.top()), operators.pop();
    return output;
}

