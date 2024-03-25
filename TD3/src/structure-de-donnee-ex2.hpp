#pragma once

//EXERCICE 2
enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value);
Token make_token(Operator op);
std::vector<Token> tokenize(std::vector<std::string> const& words);

std::string SaisieUtilisateur ();
std::vector<std::string> split_string(std::string const& s);
bool is_floating(std::string const& s);
float npi_evaluate(std::vector<Token> const& tokens);
