#include "notation_parser.h"
#include "stack.h"
#include <stack>

NotationParser::NotationParser(Expression expression) : expression_(expression) {
    
}

NotationParser &NotationParser::from(Expression expression) {
    expression_ = expression;
    return *this;
}

std::string NotationParser::parse(ExpressionType target) {
    if (target == expression_.type()) {
        return expression_.content();
    }

    if (target == ExpressionType::Postfix) {
        return to_postfix(expression_).content();
    } else if (target == ExpressionType::Prefix) {
        return to_prefix(expression_).content();
    } else {
        return to_infix(expression_).content();
    }
}

Expression NotationParser::to_infix(Expression expression) {
    Expression output(expression);
    std::string content;

    if (expression.type() == ExpressionType::Infix) {
        return expression;
    } else if (expression.type() == ExpressionType::Postfix) {
        return postfix_to_infix(expression);
    } else {
        return prefix_to_infix(expression);
    }

    return output;
}

Expression NotationParser::to_prefix(Expression expression) {
    Expression output(expression);
    std::string content;

    if (expression.type() == ExpressionType::Prefix) {
        return expression;
    } else if (expression.type() == ExpressionType::Infix) {
        return infix_to_prefix(expression);
    } else {
        return postfix_to_prefix(expression);
    }

    return output;
}

Expression NotationParser::to_postfix(Expression expression) {
    if (expression.type() == ExpressionType::Postfix) {
        return expression;
    } else if (expression.type() == ExpressionType::Infix) {
        return infix_to_postfix(expression);
    } else {
        return prefix_to_postfix(expression);
    }
}

Expression NotationParser::infix_to_postfix(Expression expression) {
    Expression output(expression);
    std::string content;
    std::string input = expression.content();
    Stack<std::string> operators;
    int index = 0;

    while (true) {
        if (index >= input.size()) break;

        std::string token = input.substr(index, 1);

        if (token == " ") {
            index++;
            continue;
        }

        bool is_function = (index + 3) < input.length() && is_operator(input.substr(index, 3));

        if (!is_function && is_operand(token)) {
            content += token;
            index++;
        } else if (is_function || is_operator(token)) {
            if (is_function) {
                token = input.substr(index, 3);
            }

            while ((!operators.empty()) && precedence(operators.top()) >= precedence(token)) {
                content += operators.top();
                operators.pop();
            }

            operators.push(token);

            if (is_function) {
                index += 3;
            } else {
                index++;
            }
        } else if (token == "(") {
            operators.push("(");
            index++;
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                content += operators.top();
                operators.pop();
            }

            if (!operators.empty()) {
                operators.pop();
            } else {
                // throw error
            }

            index++;
        } else {
            // throw error
        }
    }

    while (!operators.empty()) {
        content += operators.top();
        operators.pop();
    }

    output.content(content);
    output.type(ExpressionType::Postfix);

    return output;
}

Expression NotationParser::prefix_to_postfix(Expression expression) {
    Expression output(expression);
    std::string input = expression.content();
    Stack<std::string> helper;
    int index = input.length() - 1;

    while (true) {
        if (index < 0) break;

        std::string token = input.substr(index, 1);
        bool is_function = index - 3 >= 0 && is_operator(input.substr(index - 2, 3));

        if (is_function) {
            token = input.substr(index - 2, 3);
        }

        if (token == " ") {
            index--;
            continue;
        }

        if (!is_function && is_operand(token)) {
            helper.push(token);
            index--;
        } else if (is_function || is_operator(token)) {

            std::string operator1;

            if (!helper.empty()) {
                operator1 = helper.top();
                helper.pop();
            }

            std::string operator2;
            
            if (!helper.empty()) {
                operator2 = helper.top();
                helper.pop();
            }

            std::string temp = operator1 + operator2 + token;
            helper.push(temp);

            if (is_function) {
                index -= 3;
            } else {
                index--;
            }
        }  else {
            // throw error
        }
    }

    output.content(helper.top());
    output.type(ExpressionType::Postfix);

    return output;
}

Expression NotationParser::infix_to_prefix(Expression expression) {
    Expression postfix = infix_to_postfix(expression);
    std::string infix_str = expression.content();

    std::reverse(infix_str.begin(), infix_str.end());

    for (int i = 0; i < infix_str.size(); i++) {

        if (infix_str[i] == '(') {
            infix_str[i] = ')';
            i++;
        }         else if (infix_str[i] == ')') {
            infix_str[i] = '(';
            i++;
        }
    }

    Expression prefix = infix_to_postfix(Expression(infix_str, ExpressionType::Infix));
    std::string prefix_str = prefix.content();

    reverse(prefix_str.begin(), prefix_str.end());

    return Expression(prefix_str, ExpressionType::Prefix);
}

Expression NotationParser::postfix_to_prefix(Expression expression) {
    Expression output(expression);
    std::string input = expression.content();
    Stack<std::string> helper;
    int index = 0;

    while (true) {
        if (index >= input.size()) break;

        std::string token = input.substr(index, 1);
        bool is_function = (index + 3) < input.length() && is_operator(input.substr(index, 3));

        if (is_function) {
            token = input.substr(index, 3);
        }

        if (token == " ") {
            index++;
            continue;
        }

        if (!is_function && is_operand(token)) {
            helper.push(token);
            index++;
        } else if (is_function || is_operator(token)) {

            std::string operator1 = helper.top();
            helper.pop();

            std::string operator2;

            if (!helper.empty()) {
                operator2 = helper.top();
                helper.pop();
            }

            std::string temp = token + operator2 + operator1;

            helper.push(temp);

            if (is_function) {
                index += 3;
            } else {
                index++;
            }
        } else {
            // throw error
        }
    }

    std::string prefix = "";

    while (!helper.empty()) {
        prefix += helper.top();
        helper.pop();
    }

    output.content(prefix);
    output.type(ExpressionType::Prefix);

    return output;
}

Expression NotationParser::postfix_to_infix(Expression expression) {
    Expression output(expression);
    std::string input = expression.content();
    Stack<std::string> helper;
    int index = 0;

    while (true) {
        if (index >= input.size()) break;

        std::string token = input.substr(index, 1);
        bool is_function = (index + 3) < input.length() && is_operator(input.substr(index, 3));

        if (is_function) {
            token = input.substr(index, 3);
        }

        if (token == " ") {
            index++;
            continue;
        }

        if (!is_function && is_operand(token)) {
            helper.push(token);
            index++;
        } else if (is_function || is_operator(token)) {

            std::string operand1 = helper.top();
            helper.pop();

            if (token == "sen" || token == "cos" || token == "tan") {
                helper.push("(" + token + "(" + operand1 + ")" + ")");
                index += 3;
                continue;
            }

            std::string operand2;

            if (!helper.empty()) {
                operand2 = helper.top();
                helper.pop();
            }

            std::string temp = "(" + operand2 + token + operand1 + ")";
            helper.push(temp);

            index++;
        } else {
            // throw error
        }
    }

    output.content(helper.top());
    output.type(ExpressionType::Infix);

    return output;
}

Expression NotationParser::prefix_to_infix(Expression expression) {
    return postfix_to_infix(prefix_to_postfix(expression));
}

bool NotationParser::is_operator(std::string token) {
    std::vector<std::string> operators = {
        "+",
        "-",
        "*",
        "/",
        "^",
        "%",
        "sen",
        "cos",
        "tan"
    };

    return std::find(operators.begin(), operators.end(), token) != operators.end();
}

bool NotationParser::is_operand(std::string token) {
    return std::regex_match(token, std::regex("([a-zA-Z]{1}|[0-9]+)")) == 1;
}

int NotationParser::precedence(std::string token) {
    if (token == "sen" || token == "cos" || token == "tan") {
        return 5;
    } else if (token == "^") {
        return 4;
    } else if (token == "*" || token == "/" || token == "%") {
        return 3;
    } else if (token == "-") {
        return 2;
    } else if (token == "+") {
        return 1;
    } else {
        return 0;
    }
}