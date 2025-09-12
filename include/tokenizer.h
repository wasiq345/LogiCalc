#pragma once
#include <vector>
#include<iostream>
#include <string>

class Tokenizer
{
    private:
        std :: string expression;
        std :: vector<std :: string> tokens;
        bool isOperator(char ch) const;

    public:
        Tokenizer(const std :: string& expression);
        std :: vector<std :: string> tokenize();
};