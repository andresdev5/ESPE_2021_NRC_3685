#pragma once
#include "expression.h"

class NotationParser {
public:
    NotationParser(Expression expression);
    NotationParser& from(Expression);
    std::string parse(ExpressionType target);

private:
    Expression to_infix(Expression expression);
    Expression to_prefix(Expression expression);
    Expression to_postfix(Expression expression);

    Expression infix_to_postfix(Expression expression);
    Expression prefix_to_postfix(Expression expression);
    Expression infix_to_prefix(Expression expression);
    Expression postfix_to_prefix(Expression expression);
    Expression postfix_to_infix(Expression expression);
    Expression prefix_to_infix(Expression expression);

    bool is_operator(std::string value);
    bool is_operand(std::string value);
    int precedence(std::string token);

    Expression expression_;
};
