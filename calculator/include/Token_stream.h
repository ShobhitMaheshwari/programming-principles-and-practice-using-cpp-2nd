//
// Created by shobhit on 1/2/16.
//

#ifndef STRINGPERMUTATION_TOKEN_STREAM_H
#define STRINGPERMUTATION_TOKEN_STREAM_H

#include "Token.h"

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};


#endif //STRINGPERMUTATION_TOKEN_STREAM_H