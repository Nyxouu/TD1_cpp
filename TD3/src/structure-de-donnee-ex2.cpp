#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype> 
#include <stack>
#include "structure-de-donnee-ex2.hpp"



//EXERCICE 2
// enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN};
// enum class TokenType { OPERATOR, OPERAND };
// struct Token {
//   TokenType type;
//   float value;
//   Operator op;
// };

Token make_token(float value){
    return Token{TokenType::OPERAND, value, Operator::ADD}; //ADD par default
}
Token make_token(Operator op){
    return Token{TokenType::OPERATOR, 0, op}; //value 0 par default
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> Tokens {};
    for (std::string i : words){
        if (is_floating(i)){
            Token iToken = make_token(stof(i)); //stof pour mettre string en float
            Tokens.push_back(iToken);
        }
        if (!is_floating(i)){
            if (i == "+"){
                Tokens.push_back(make_token(Operator::ADD));
            }
            else if (i == "-"){
                Tokens.push_back(make_token(Operator::SUB));
            }
            else if (i == "*"){
                Tokens.push_back(make_token(Operator::MUL));
            }
            else if (i == "/"){
                Tokens.push_back(make_token(Operator::DIV));
            }
            else if (i == "^"){
                Tokens.push_back(make_token(Operator::POW));
            }
        }
    }
    return Tokens;
}


std::string SaisieUtilisateur (){
    std::string saisie {};

    std::cout << "Entrez votre calcul : ";
    std::getline(std::cin , saisie);
    return saisie ;
}

std::vector<std::string> split_string(std::string const& s){
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s){
    for (int i : s){
        if (!(std::isdigit(i) || i == '.')){
            return false ;
        }
    }
    return true ;
}



float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack ;
    for(Token tok : tokens ){
        if (tok.type == TokenType::OPERAND){
            stack.push(tok.value);  //std::stof sert a convertir les caracteres du tableau en float 
        }
        if (tok.type == TokenType::OPERATOR){
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            float result {};
            if (tok.op == Operator::ADD){
                result =leftOperand+rightOperand;
            }
            else if (tok.op == Operator::SUB){
                result =leftOperand-rightOperand;
            }
            else if (tok.op == Operator::MUL){
                result =leftOperand*rightOperand;
            }
            else if (tok.op == Operator::DIV){
                result =leftOperand/rightOperand;
            }
            else if (tok.op == Operator::POW){
                result = pow(leftOperand, rightOperand);
            }
            stack.push(result);
        }
    }
    float final_result {stack.top()};
    return (final_result) ;
    
}