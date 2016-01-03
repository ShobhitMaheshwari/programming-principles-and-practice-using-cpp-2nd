#include <iostream>
#include <vector>
#include <algorithm>
#include "Token.h"
#include "Calculator.h"

using namespace std;

int main() {
	Calculator expression;
	try {
		expression.evaluate();
		return 0;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cerr << "exception \n";
		return 2;
	}
}