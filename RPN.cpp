#include "RPN.h"
#include <cmath>
#include <stack>

std::string parse(std::string s)
{
	std::stack<char> operators;
	std::string output = "";
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			if (isdigit(s[i])) {
				output = output + s[i];
			} else if (s[i] == ')') {
				while (operators.top() != '(') {
					output = output + " " + operators.top();
					operators.pop();
				}
				operators.pop();
			} else {
				if (s[i] == '+' || s[i] == '-') {
					while (!operators.empty() && operators.top() != '(') {
						output = output + operators.top();
						operators.pop();
					}
				} else if (s[i] == '*' || s[i] == '/') {
					if (!operators.empty() && (operators.top() == '^' || 
					    operators.top() == '*' || operators.top() == '/')) {
						output = output + operators.top();
						operators.pop();
					}
				}
				operators.push(s[i]);
			}
		} else {
			output = output + " ";
		}
	}

	while (!operators.empty()) {
		output = output + " " + operators.top();
		operators.pop();
	}

	return output;
}

double calculate(std::string s) 
{
	if (s == "") {
		return 0;
	}
	std::stack<double> numbers;
	std::string result = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			if (isdigit(s[i]) || s[i] == '.') {
				result = result + s[i];
				if (i+1 < s.size() && s[i+1] != ' ') continue;
				numbers.push(stod(result));
				result = "";
			} else {
				double n1 = numbers.top();
				numbers.pop();
				double n2 = numbers.top();
				numbers.pop();
				switch (s[i]) {
					case '+':
						numbers.push(n2+n1);
						break;
					case '-':
						numbers.push(n2-n1);
						break;
					case '*':
						numbers.push(n2*n1);
						break;
					case '/':
						numbers.push(n2/n1);
						break;
					case '^':
						numbers.push(pow(n2, n1));
					default:
						break;
				}
			}
		}
	}

	return numbers.top();
}
