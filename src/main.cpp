#include "../include/parser.h"

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
        std :: cin >> expression;
        
        // Tokenize the expression
        // Convert infix to postfix
        // Evaluate the postfix expression
        // Display the result

    } while (expression != "quit");
}