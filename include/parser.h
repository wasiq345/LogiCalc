#pragma once
#include <vector>
#include <stack>
#include <string> 
#include<iostream>

using token = std :: string;        // Alias for string, tells the compiler that token is a string

class Parser
{
    private:
        int VariableCount = 0;
        std :: vector<token> tokens;

        // Precedence tells the compiler which operator to evaluate first, returns the precedence of operators
        int precedence(const std :: string& op) const;

        // return true if the token is a operator 
        bool IsOperator(const std :: string& token) const;

        // Some operators are right associative like -> and <->
        bool IsRightAssociative(const std :: string& op) const;


    public:
        Parser(const std :: vector<token>& tokens);
        int getVariableCount();
        // Parses the tokens into postfix notation using the shunting yard algorithm
        std :: vector<token> parse() const;

};