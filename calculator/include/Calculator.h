//
// Created by shobhit on 1/1/16.
//

/*
	Simple calculator
	Revision history:
		Revised by Bjarne Stroustrup November 2013
		Revised by Bjarne Stroustrup May 2007
		Revised by Bjarne Stroustrup August 2006
		Revised by Bjarne Stroustrup August 2004
		Originally written by Bjarne Stroustrup
			(bs@cs.tamu.edu) Spring 2004.
	This program implements a basic expression calculator.
	Input from cin; output to cout.
	The grammar for input is:

Statement:
	Expression
	Print
	Quit
Print:
	;
Quit:
	q
Expression:
	Term
	Expression + Term
	Expression – Term
Term:
	Primary
	Term * Primary
	Term / Primary
	Term % Primary
Primary:
	Number
	( Expression )
	– Primary
	+ Primary
Number:
	floating-point-literal
Input comes from cin through the Token_stream called ts.
*/

#ifndef STRINGPERMUTATION_EXPRESSION_H
#define STRINGPERMUTATION_EXPRESSION_H

#include <string>
#include "Token.h"
#include "Token_stream.h"

class Calculator {

private:
	static const char number; // t.kind==number means that t is a number Token
	static const std::string prompt;
	static const std::string result; // used to indicate that what follows is a result
	Token_stream ts;        // provides get() and putback()

	Token get_token(); // read characters and compose tokens
	double expression(); // deal with + and –
	double term(); // deal with *, /, and %
	double primary(); // deal with numbers and parentheses
	void clean_up_mess();

public:

	Calculator();
	void evaluate();
};


#endif //STRINGPERMUTATION_EXPRESSION_H
