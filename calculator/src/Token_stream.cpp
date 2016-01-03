//
// Created by shobhit on 1/2/16.
//

#include <stdexcept>
#include <iostream>
#include "Token_stream.h"

using namespace std;

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
		:full(false), buffer(0)    // no Token in buffer
{

}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) throw std::invalid_argument("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
		// remove token from buffer
		full=false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
		case ';':    // for "print"
		case 'q':    // for "quit"
		case '(': case ')': case '+': case '-': case '*': case '/':
			return Token{ch};        // let each character represent itself
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '9':
		{
			cin.putback(ch);         // put digit back into the input stream
			double val;
			cin >> val;              // read a floating-point number
			return Token{'8',val};   // let '8' represent "a number"
		}
		default:
			throw std::invalid_argument("Bad token");
	}
}