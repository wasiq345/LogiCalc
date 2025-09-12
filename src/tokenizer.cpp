#include "../include/tokenizer.h"

Tokenizer :: Tokenizer(const std :: string& expression)
{
    this -> expression = expression;
}

bool Tokenizer :: isOperator(char ch) const
{
    return (ch == '~' || ch == '^' || ch == 'v' || ch == '-' || ch == '<' || ch == '>' || ch == '(' || ch == ')');
}

std :: vector<std :: string> Tokenizer :: tokenize()
{
    for (size_t i = 0; i < expression.length(); i++) {
            char token = expression[i];
            
            if (token == ' ') continue; // ignore spaces
            
            if (isOperator(token))
             { 
                if (token == '-')
                 {                     
                    if (!tokens.empty() && tokens.back() == "<") tokens.back() += token;    // handle <-
                    else tokens.push_back(std::string(1, token));
                 }

                 else if (token == '<')  tokens.push_back(std::string(1, token));
                 else if (token == '>')
                  {
                    
                    if (!tokens.empty() && tokens.back() == "-")  tokens.back() += token;     // handle ->
                    else if (!tokens.empty() && tokens.back() == "<-") tokens.back() += token;     // handle <->
                    else tokens.push_back(std::string(1, token));

                }
                else tokens.push_back(std::string(1, token)); 
            }
             else                               // it's a variable 
              { 
                if (!tokens.empty() && !tokens.back().empty() && !isOperator(tokens.back().back()) && (std::isalnum(token) || token == '_'))
                 {
                    tokens.back() += token;                     // Continue building multi-character variable (P1, Q2, etc.)
                 } 
                else 
                {
                    // Start new token
                    tokens.push_back(std::string(1, token));
                }
            }
        }
        return tokens;
    }


int main()
{
    Tokenizer t("A ^ B v C -> D <-> E");
    auto tokens = t.tokenize();
    for(const auto& token : tokens) std :: cout << token << "*";
    return 0;
}
