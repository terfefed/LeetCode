class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands;

        for (const std::string& token : tokens) {
            if (isOperator(token)) {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();

                if (token == "+") {
                    operands.push(operand1 + operand2);
                } else if (token == "-") {
                    operands.push(operand1 - operand2);
                } else if (token == "*") {
                    operands.push(operand1 * operand2);
                } else if (token == "/") {
                    operands.push(operand1 / operand2);
                }
            } else {
                operands.push(std::stoi(token));
            }
        }

        return operands.top();
    }

private:
    bool isOperator(const std::string& token) {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }
};