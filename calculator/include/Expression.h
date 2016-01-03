//
// Created by shobhit on 1/1/16.
//

#ifndef STRINGPERMUTATION_EXPRESSION_H
#define STRINGPERMUTATION_EXPRESSION_H

#include <string>
#include "Token.h"
#include "Token_stream.h"

class Expression {

private:
	Token_stream ts;        // provides get() and putback()

public:

	Expression();

	Token get_token(); // read characters and compose tokens
	double expression(); // deal with + and –
	double term(); // deal with *, /, and %
	double primary(); // deal with numbers and parentheses
	int evaluate();

};


#endif //STRINGPERMUTATION_EXPRESSION_H
