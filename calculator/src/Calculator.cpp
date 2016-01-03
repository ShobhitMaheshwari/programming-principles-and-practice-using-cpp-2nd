//
// Created by shobhit on 1/1/16.
//

#include <iostream>
#include <error.h>
#include <stdexcept>
#include <cmath>
#include "Calculator.h"

const char Calculator::number = '8'; // t.kind==number means that t is a number Token
const std::string Calculator::prompt = "> ";
const std::string Calculator::result = "= "; // used to indicate that what follows is a result

Calculator::Calculator(){
//	ts = Token_stream();

}

Token Calculator::get_token(){
	return ts.get();
}

double Calculator::expression(){
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
double Calculator::term(){
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
			case '%':
			{
				double d = primary();
				if (d == 0) throw std::invalid_argument("divide by zero");
				left = fmod(left,d);
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}
double Calculator::primary(){
	Token t = get_token();
	switch (t.kind) {
		case '(': // handle ‘(‘ expression ‘)’
		{
			double d = expression();
			t = get_token();
			if (t.kind != ')') throw std::invalid_argument("')' expected");
			return d;
		}
		case number: // we use ‘8’ to represent a number
			return t.value; // return the number’s value
		case '-' :
			return -primary();
		case '+':
			return primary();
		default:
			throw std::invalid_argument("primary expected");
	}
}

void Calculator::evaluate(){

	while (std::cin) {

		try {
			std::cout << prompt;
			Token t = ts.get();
			while (t.kind == Token_stream::print) t=ts.get(); // first discard all “prints”
			if (t.kind == Token_stream::quit) {
				return;
			}
			ts.putback(t);
			std::cout << result << this->expression() << '\n';
		}
		catch (std::exception& e) {
			std::cerr << e.what() << '\n'; // write error message
			clean_up_mess();
		}
	}
}

void Calculator::clean_up_mess() // naive
{
	ts.ignore(Token_stream::print);
}