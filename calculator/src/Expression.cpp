//
// Created by shobhit on 1/1/16.
//

#include <iostream>
#include <error.h>
#include <stdexcept>
#include "Expression.h"

Expression::Expression(){
//	ts = Token_stream();
}

Token Expression::get_token(){
	return ts.get();
}

double Expression::expression(){
	double left = term(); // read and evaluate a Term
	Token t = ts.get(); // get the next token
	while (true) {
		switch (t.kind) {
			case '+':
				left += term(); // evaluate Term and add
				t = ts.get();
				break;
			case '-':
				left -= term(); // evaluate Term and subtract
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left; // finally: no more + or – ; return the answer
		}
	}
}
double Expression::term(){
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) throw std::invalid_argument("divide by zero");
				left /= d;
				t = ts.get();
				break;
			}
//			case '%':
//				left %= primary();
//				t = get_token();
//				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}
double Expression::primary(){
	Token t = get_token();
	switch (t.kind) {
		case '(': // handle ‘(‘ expression ‘)’
		{
			double d = expression();
			t = get_token();
			if (t.kind != ')') throw std::invalid_argument("')' expected");
			return d;
		}
		case '8': // we use ‘8’ to represent a number
			return t.value; // return the number’s value
		case '-' :
			return -primary();
		case '+':
			return primary();
		default:
			throw std::invalid_argument("primary expected");
	}
}

int Expression::evaluate(){
	
	try {
		while (std::cin) {
			std::cout << "> ";
			Token t = ts.get();
			while (t.kind == ';') t=ts.get(); // eat ‘;’
			if (t.kind == 'q') {
				return 0;
			}
			ts.putback(t);
			std::cout << "=" << this->expression() << '\n';
		}
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