#pragma once

enum class ExpressionType {
    Infix,
    Postfix,
    Prefix
};

class Expression {
public:
    Expression(std::string content, ExpressionType type);
    std::string const &content();
    void content(std::string const &content);
    ExpressionType const& type();
    void type(ExpressionType const &type);

private:
    ExpressionType type_;
    std::string content_;
};