#include "expression.h"

Expression::Expression(std::string content, ExpressionType type) : content_(content), type_(type) {}

std::string const& Expression::content() {
    return content_;
}

void Expression::content(std::string const& content) {
    content_ = content;
}

ExpressionType const& Expression::type() {
    return type_;
}

void Expression::type(ExpressionType const& type) {
    type_ = type;
}
